#include "CCentralAbstractInterface.h"

CCentralAbstractInterface::CCentralAbstractInterface()
{ 
  // Anlegen der Layouts
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  gLayout_ = new QGridLayout;
  editLayout_ = new QHBoxLayout;
  
  // Anlegen der Widgets
  dropDown_ = new QComboBox;
  //bNew_ = new QPushButton("Neue Gruppe");
  bDelete_ = new QPushButton("Gruppe löschen");
  bInputDelete_ = new QPushButton("Eintrag löschen");
  editProperties_ = new QPushButton("Eigenschaften bearbeiten");
  
  // Konfigurieren der Layouts
  hLayout_->addWidget(dropDown_);
  //hLayout_->addWidget(bNew_);
  hLayout_->addWidget(bDelete_);
  vLayout_->addLayout(hLayout_);
  vLayout_->addLayout(gLayout_);
  vLayout_->addLayout(sLayout_);
  editLayout_->addWidget(editProperties_);
  editLayout_->addWidget(bInputDelete_);
  vLayout_->addLayout(editLayout_);
  this->setLayout(vLayout_);
  
  // setzen der connections
  //connect(bNew_, SIGNAL(clicked()), this, SLOT(addGroup()));
  connect(bDelete_, SIGNAL(clicked()), this, SLOT(deleteGroup()));
  connect(dropDown_, SIGNAL(activated(int)), this, SLOT(changeGroup(int)));
  connect(editProperties_, SIGNAL(clicked()), this, SLOT(openProperties()));
  connect(bInputDelete_, SIGNAL(clicked()), this, SLOT(deleteEntry()));
}

//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::buildGroupLists()
{  
  for (std::map<int,QString>::iterator it = firstNameList_.begin(); it != firstNameList_.end(); it++)
  {
    addGroup(it->first, it->second);
  }
}

//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::addGroup()
{
  bool ok_name;
  bool ok_number;

  // Eingabeauforderung der neuen Stationsnummer
  int number = QInputDialog::getInt(this, tr("Erstellung einer neuen Gruppe"),
                                       tr("neue Nummer:"),0,1,200,1,&ok_number);
  
  // Wenn durch "ok" bestätigt
  if (ok_number && ok_name)
  { 
    // Abfrage ob Gruppe bereits vorhanden ist
    if (checkDoubleGroup(number) || firstNameList_.count(number) == 0)
    {
      // Warnung ausgeben
      QMessageBox msgBox;
      msgBox.setIcon(QMessageBox::Warning);
      msgBox.setText("Diese Gruppe ist bereits vorhanden, oder nicht in der Gruppenliste");
      msgBox.setInformativeText("Gruppe wird nicht hinzugefügt");
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.setDefaultButton(QMessageBox::Ok);
      msgBox.exec();

      return;
    }
    
    // Hinzufügen der Gruppe
    addGroup(number, firstNameList_[number]);
    
    // Aufrufen der Gruppenspezifischen Eingaben
    getCurrentGroup()->openProperties();
  }
}

//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::addGroup(int number, QString name)
{
  CGroupInterface* newGroup;
  
  // Hinzufügen des items und aktiv setzen
  dropDown_->addItem(QString::number(number) + ": " + name);
  dropDown_->setCurrentIndex(dropDown_->count() - 1);

  // Anlegen der neuen Gruppe
  newGroup = this->newGroup(name, number);
  
  // Hinzufügen zum stacked Layout
  sLayout_->addWidget(newGroup);
  sLayout_->setCurrentWidget(newGroup);
  
  connect(getCurrentGroup()->getTable(), SIGNAL(cellDoubleClicked(int,int)), this, SLOT(editInput()));
  connect(getCurrentGroup()->getTable(), SIGNAL(cellPressed(int,int)), this, SLOT(resumeEditInput()));
}

//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::deleteGroup()
{
  // Holen der aktuellen Gruppe und den index
  CGroupInterface* delGroup = getCurrentGroup();
  int index = sLayout_->indexOf(delGroup);
  
  // Konfigurieren der Sicherheitsnachfrage
  QMessageBox msgBox;
  msgBox.setIcon(QMessageBox::Warning);
  msgBox.setText("Soll diese Gruppe gelöscht werden?");
  msgBox.setInformativeText(dropDown_->itemText(index));
  msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Cancel);
  int ret = msgBox.exec();
  
  // Löschen wenn mit "ok" bestätigt
  if(ret == QMessageBox::Ok)
  {
    dropDown_->removeItem(index);
    sLayout_->removeWidget(delGroup);
    delete delGroup;
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::changeGroup(int index)
{
  dropDown_->setCurrentIndex(index);
  sLayout_->setCurrentIndex(index);
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::changeGroupByNumber(int number)
{
  for (int i = 0; i < sLayout_->count(); i++)
  {
    CGroupInterface* gr = dynamic_cast<CGroupInterface*> (sLayout_->widget(i));
    
    if(gr->getNumber() == number)
    {
      sLayout_->setCurrentWidget(gr);
      
      return;
    }
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::buildInputLayout()
{
  // Bauen des Eingabefeldes
  // Hinzufügen der Label
  for (int i = 0; i < parameter_.size(); i++)
  {
    gLayout_->addWidget(new QLabel(parameter_.at(i)),0,i);
  }
  
  // Hinzufügen der Eingabefelder
  for (int i = 0; i < parameter_.size(); i++)
  {
    gLayout_->addWidget(new QLineEdit,1,i);
  }
  
  // Herstellung der Referenz zu den Eingabeparametern
  // TODO: Schleife über Abfrage "if QLineEdit" verbessern
  // TODO: Safe machen
  for (int i = 0; i < gLayout_->columnCount(); i++)
  {
    inputList_.push_back(dynamic_cast<QLineEdit*>(gLayout_->itemAtPosition(1,i)->widget()));
  }
  
  // Hinzufügen des Bestätigungs-Buttons
  bInputNew_ = new QPushButton("Eintrag hinzufügen");
  bInputNew_->setAutoDefault(true);
  bEdit_ = new QPushButton("Eintrag bearbeiten");
  
  // Buttons ins Grid einfügen
  gLayout_->addWidget(bEdit_,0,inputList_.size());
  gLayout_->addWidget(bInputNew_,1,inputList_.size());
  
  //Deaktivieren des Bearbeiten-Buttons
  bEdit_->setDisabled(true);

  // connections
  connect(bInputNew_, SIGNAL(clicked()), this, SLOT(addEntry()));
  connect(bInputNew_, SIGNAL(clicked()), this, SLOT(setFocus()));
  connect(bEdit_, SIGNAL(clicked()), this, SLOT(sendEditedInput()));
  connect(inputList_.at(0), SIGNAL(textEdited(QString)), this, SLOT(checkGroupName(QString)));
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::addEntry()
{
  // Holen der aktuellen Gruppe
  CGroupInterface* group = getCurrentGroup();
  
  // Tabelle wieder auf weiß setzen
  group->setWhiteTable();
  
  if (group == NULL)
  {
    // TODO: Execption
    return;
  }
  
  // auf bereits vorhandenen Eintrag prüfen
  if (checkDoubleEntry())
  {
    //Holen der Zeilennummer
    int row = getCurrentGroup()->getRow(inputList_.at(0)->text().toInt());
    
    // Überschreiben des existierenden Eintrag
    writeToTable(row);
    
    // Input für Gruppennamen wieder freigeben
    inputList_.at(1)->setDisabled(false);
    
    // Zeile auf rot setzen
    getCurrentGroup()->setRedRow(row);
    
    // Input leeren
    emptyInput();
  }
  
  else
  {
    // Eintrag hinzufügen
    group->addTableEntry(inputList_);
  
    // Input für Gruppennamen wieder freigeben
    inputList_.at(1)->setDisabled(false);

    // Input leeren
    emptyInput();
  }
  
  group->getTable()->setSortingEnabled(true);
  group->getTable()->setSortingEnabled(false);
  
}
//---------------------------------------------------------------------------------------
//TODO: In CGroupInterface auslagern
void CCentralAbstractInterface::deleteEntry()
{
  getCurrentGroup()->deleteTableEntry();
}
//---------------------------------------------------------------------------------------

CGroupInterface* CCentralAbstractInterface::getCurrentGroup()
{
    // Holen der aktuellen Gruppe
  CGroupInterface* actualGroup = dynamic_cast<CGroupInterface*>(sLayout_->currentWidget());
  
  return actualGroup;
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::editInput()
{
  // Umstellen der Button Aktivität
  changeToEditStatus(true);
  
  writeToInput();
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::resumeEditInput()
{
  // Umstellen der Button Aktivität
  changeToEditStatus(false);
  
  emptyInput();
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::emptyInput()
{
  QString empty ("");
  
  // Übertragung der Daten auf die Input Felder
  for(int i = 0; i < inputList_.size(); i++)
  { 
    inputList_.at(i)->setText(empty);
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::sendEditedInput()
{
  changeToEditStatus(false);
  
  writeToTable(getCurrentGroup()->getRow(inputList_.at(0)->text().toInt()));
  
  emptyInput();
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::changeToEditStatus(bool editStatus)
{
  // Abfrage des Status
  if(editStatus)
  {
    bInputNew_->setDisabled(true);
    bEdit_->setDisabled(false);
    bInputDelete_->setDisabled(true);
    inputList_.at(1)->setDisabled(true);
    inputList_.at(0)->setDisabled(true);
  }
  
  else
  {
    bInputNew_->setDisabled(false);
    bEdit_->setDisabled(true);
    bInputDelete_->setDisabled(false);
    inputList_.at(1)->setDisabled(false);
    inputList_.at(0)->setDisabled(false);
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::writeToTable(int row)
{
  // Ermittlung des aktuellen table
  QTableWidget* table = getCurrentGroup()->getTable();
  
  // Übertragung der Daten auf die Input Felder
  for(int i = 0; i < inputList_.size(); i++)
  {
    QString text = inputList_.at(i)->text();
    
    table->item(row,i)->setText(text);
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::writeToInput()
{
  // Ermittlung der aktivierten Zeile und des aktuellen table
  int row = getCurrentGroup()->getTable()->currentRow();
  QTableWidget* table = getCurrentGroup()->getTable();
  
  // Übertragung der Daten auf die Input Felder
  for(int i = 0; i < inputList_.size(); i++)
  {
    QString text = table->item(row,i)->text();
    
    inputList_.at(i)->setText(text);
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::checkGroupName(QString number)
{
  // Konvertierung in int
  int numb = number.toInt();

  // Bearbeitung des Namen Inputfeldes zunächst wieder freigeben
  inputList_.at(1)->setDisabled(false);

  // Eintrag im Namen Inputfeld wieder löschen
  inputList_.at(1)->setText("");

  if(secondNameList_.count(numb) > 0)
  {
    // Namen einfügen
    inputList_.at(1)->setText(secondNameList_.at(numb));
    
    // Weitere Bearbeitung sperren
    inputList_.at(1)->setDisabled(true);
  }
}
//---------------------------------------------------------------------------------------

bool CCentralAbstractInterface::checkDoubleEntry()
{
  // auf bereits vorhandenen Eintrag prüfen
  if(getCurrentGroup()->checkEntryExist(inputList_.at(0)->text().toInt()))
  {
    return true;
  }

  return false;
}
//---------------------------------------------------------------------------------------

bool CCentralAbstractInterface::checkDoubleGroup(int number)
{
  for (int i = 0; i < sLayout_->count(); i++)
  {
    if (getGroupAt(i)->getNumber() == number)
    {
      return true;
    }
  }

  return false;
}
//---------------------------------------------------------------------------------------

CGroupInterface* CCentralAbstractInterface::getGroupAt(int index)
{
  // Holen der aktuellen Gruppe
  CGroupInterface* GroupAt = dynamic_cast<CGroupInterface*>(sLayout_->widget(index));
  
  return GroupAt;
}
//---------------------------------------------------------------------------------------

int CCentralAbstractInterface::getGroupNumber()
{
  int size = 0;
  
  size = sLayout_->count();
  
  return size;
}
//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::save(std::ofstream& saveFile)
{
  //Baum öffnen
  saveFile << "CCentralAbstractInterface" << "\t";
  
  // Alle Gruppen schreiben
  for(int i = 0; i < getGroupNumber(); i++)
  { 
    getGroupAt(i)->save(saveFile);
  }
  
  // Baum schließen
  saveFile << "CCentralAbstractInterface" << "\t";
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::load(std::stringstream& stream)
{
  std::string parser;
  getline(stream, parser, '\t');
  
  // Schauen, ob Baum geöffnet wird
  if(!stream.eof() || parser == "CCentralAbstractInterface")
  { 
    while(!stream.eof())
    {
      //Nächste Zeile holen
      getline(stream, parser, '\t');
      
      // Abbruch, wenn Ende des Baumes erreicht
      if(parser == "CCentralAbstractInterface")
      {
        // Aktivieren des ersten Eintrages
        changeGroup(0);
        
        return;
      }
    
      int number;
      std::string name;
      
      getline(stream,parser,'\t');
      number = atoi(parser.c_str());
      
      getline(stream,name,'\t');
      
      // Neues groupInterface anlegen
      changeGroupByNumber(number);
        
      // Laden der openProperties
      getCurrentGroup()->loadProperties(stream);
      
      // Alle Tabelleneinträge laden
      getCurrentGroup()->loadTable(stream);
    }
  }
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::openProperties()
{  
  if(sLayout_->count() > 0)
  {
    // Öffnet Properties
    getCurrentGroup()->openProperties();
  }
  else
  {
    // Warnung ausgeben
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Noch keine Gruppe vorhanden!");
    msgBox.setInformativeText("Eigenschaften werden nicht angezeigt");
    msgBox.exec();
  }
}
//---------------------------------------------------------------------------------------
bool CCentralAbstractInterface::compare(CCentralAbstractInterface* other)
{
  // Alle Gruppen miteinander vergleichen
  for (int i = 0; i < getGroupNumber(); i++)
  {
    if(getGroupAt(i)->compare(other->getGroupAt(i)) == false)
    {
        return false;
    }
  }
  
  return true;
}
//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::setFocus()
{
  inputList_.at(0)->setFocus();
}

//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::buildNameLists()
{
  std::map<int,QString> runner;
  
  runner[1] = "Die superbesten Freunde";
  runner[2] = "Pure Manpower Since 1979";
  runner[3] = "Die gestiefelten Muskelkater";
  runner[4] = "Lillizee";
  runner[5] = "Laufen aus Leidenschaft";
  runner[6] = "Soweit die Füße tragen";
  runner[7] = "Die Mächtigen Zweihänder";
  runner[8] = "Scoutaholics";
  runner[9] = "Hard Scouts";
  runner[10] = "Jakobs Dröhnung";
  runner[11] = "Die Orber 2";
  runner[12] = "Winfried Vol.I";
  runner[13] = "Flinke Hände, stinke Füße";
  runner[14] = "These boobs are made for walking";
  runner[15] = "10 km auf 10 cm";
  runner[16] = "Geist über Materie";
  runner[18] = "Brebacher Koksritter II";
  runner[20] = "Jana und die starken Männer";
  runner[21] = "D Wolpertinger";
  runner[22] = "Glücksbärchis";
  runner[23] = "Brebacher Koksritter I";
  runner[24] = "Diesmal landen wir weiter vorn";
  runner[25] = "Zu Fuß Echt jetzt?!";
  runner[26] = "Bunkerlitzchen";
  runner[27] = "Schachtaffen";
  runner[28] = "Kurfürstlicher Dackelklub";
  runner[29] = "Läuft. Zwar rückwärts und bergab, aber läuft!";
  runner[30] = "Walking Class Heroes";
  runner[31] = "diedieauchmaljüngerwaren";
  runner[32] = "Fieselschweiflinge";
  runner[33] = "Ansgarer Fahrtenkomitee";
  runner[34] = "Wie Phoenix aus der Asche - BonnaTom";
  runner[35] = "Die Orber 1";
  runner[36] = "Team LSK";
  runner[37] = "Die rasenden Schnecken";
  runner[38] = "Tempo, kleine Schnecke!";
  runner[39] = "Die Essener Stadtmusikanten";
  runner[40] = "Altersresidenz Nibelungenhort";
  runner[41] = "Die Hobby Mannschaft";
  runner[42] = "Bembelbrigade Bernem Sektion babbischer Babbsack";
  runner[43] = "BL&friENds";
  runner[44] = "Team Muckefuck - Beware of the Bär !";
  runner[45] = "Es tat Nivea als beim ersten Mal";
  runner[46] = "Leiterrunde Senden";
  runner[47] = "Team Waschmaschine";
  runner[48] = "Hiltrup 1";
  runner[49] = "Omas von der Müllhalde";
  runner[50] = "Echoverpeilung - Nacktmull und Schubkarre";
  runner[51] = "Reichen wir nach";
  runner[52] = "Roter Milan";
  runner[53] = "Frische Brise";
  runner[54] = "Humpelstilzchen Road Ranners";
  runner[55] = "Humpelstilzchen Hy huuh";
  runner[56] = "Beethovens 5. - Klein Bon(n)um";
  runner[57] = "L.I.S.A. --> Laufen Ist Schon Anstrengend";
  runner[58] = "Jagdwasserteilchen";
  runner[59] = "Rubbeldiekatz";
  runner[60] = "Dat Lizzy";
  runner[61] = "Saar Heroes";
  runner[62] = "Pfadfinder vorm Kino";
  runner[63] = "Rover DV Berlin";
  runner[64] = "RoveRatten NK44";
  runner[65] = "Bärliner Fußpilsner";
  runner[66] = "Attacke Pobacke";
  runner[67] = "Zipfelstürmer";
  runner[68] = "Dampfsocken";
  runner[69] = "Uns qualmts aus de Schlabbe un de Strümpf";
  runner[70] = "Klabusterbeerenbande";
  runner[71] = "Die Physiker";
  runner[72] = "Die Bilanz";
  runner[73] = "Vaya Con Tioz";
  runner[74] = "Tramps vun de Palz";
  runner[75] = "Spessarträuber";
  runner[76] = "!";
  runner[77] = "Haariger Ulf";
  runner[78] = "6 Rosen für ein Halleluja";
  runner[79] = "Badische Lewwerknepp";
  runner[80] = "Team Barbie";
  runner[81] = "Die Wanderperiode";
  runner[82] = "Die Ziegen";
  runner[83] = "Nord meets Süd";
  runner[84] = "Die Truthähne";
  runner[86] = "Die Herbys";
  runner[87] = "Lemgo? - Ja!";
  runner[88] = "Biberbrüder";
  runner[89] = "Die Andertheker";
  runner[90] = "Highlight - Wir gehen Pömpeln";
  runner[91] = "Stadtpfadfinder";
  runner[92] = "Team Horst";
  runner[93] = "Fränkische Pflaumen";
  runner[94] = "Fichtelgebirgs-Gnome";
  runner[95] = "Die Friesengeister - ist denn noch Bolognese da??";
  runner[96] = "Team Käppchen";
  runner[97] = "Fred Jo on tour";
  runner[98] = "Love and Hope";
  runner[99] = "Knotenente";
  runner[100] = "Team Wadlbeisser";
  runner[101] = "Waden sind der neue Bizeps";
  runner[102] = "Bembelritter";
  runner[103] = "Auch auf Fleisch kann man laufen!!";
  runner[104] = "Lohnschdener Humpelstilzchen";
  runner[105] = "Die Schnabeltiere";
  runner[106] = "Team Nastberg";
  runner[107] = "Größenpunktwahn";
  runner[108] = "Ghostbusters";
  runner[109] = "Rochus!";
  runner[110] = "Pöbel Peter";
  runner[111] = "Die Knoteriche";
  runner[112] = "Bloodhound Gang";
  runner[113] = "Mc Roverz";
  runner[114] = "The Expendables";
  runner[115] = "42";
  runner[116] = "Os ilium - Am Anfang war das Bier";
  runner[117] = "Barfuß";
  runner[118] = "Your moms favorite team";
  runner[119] = "Die Mollsenbande";
  runner[120] = "Die Minions";
  runner[121] = "Hääschdner Päddler";
  runner[122] = "Sejerländer Lällese";
  runner[123] = "Burgfalken";
  
  std::map<int,QString> station;
  station[1] = "Bembelbrigarde Bernem Sektion Hibbelischer Hutschebebbes";
  station[2] = "@tom H²O - Back to the roots";
  station[3] = "Wanderpanda / Monster DV";
  station[4] = "Ist das ne Gruppe oder kann das weg?";
  station[5] = "abgespaced - jetzt gehts auf Safari";
  station[6] = "Stamm Maximilian Kolbe";
  station[7] = "Hélder Câmara";
  station[8] = "Das das verrückte Labyrinth";
  station[9] = "Entspannung auf hohem Nivau";
  station[10] = "Glück Auf!";
  station[11] = "Insomnia";
  station[12] = "Quest of the Gnapf";
  station[13] = "Todesfluch des Stachelhalsbandes";
  station[14] = "Bezirk Paderborn im Legofieber";
  station[15] = "Denn sie wissen nicht was sie tun";
  station[16] = "Das Beste kommt zum Schluss";
  
  assignLists(runner, station);
}

