#include "CCentralAbstractInterface.h"

CCentralAbstractInterface::CCentralAbstractInterface()
{ 
  // Anlegen der Layouts
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  gLayout_ = new QGridLayout;
  
  // Anlegen der Widgets
  dropDown_ = new QComboBox;
  bNew_ = new QPushButton("Neue Gruppe");
  bDelete_ = new QPushButton("Gruppe löschen");
  bInputDelete_ = new QPushButton("Eintrag löschen");
  
  // Konfigurieren der Layouts
  hLayout_->addWidget(dropDown_);
  hLayout_->addWidget(bNew_);
  hLayout_->addWidget(bDelete_);
  vLayout_->addLayout(hLayout_);
  vLayout_->addLayout(gLayout_);
  vLayout_->addLayout(sLayout_);
  vLayout_->addWidget(bInputDelete_,0,Qt::AlignRight);
  this->setLayout(vLayout_);
  
  // setzen der connections
  connect(bNew_, SIGNAL(clicked()), this, SLOT(addGroup()));
  connect(bDelete_, SIGNAL(clicked()), this, SLOT(deleteGroup()));
  connect(dropDown_, SIGNAL(activated(int)), this, SLOT(changeGroup(int)));
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::addGroup()
{
  bool ok_name;
  bool ok_number;
  CGroup* newGroup;

  // Eingabeauforderung der neuen Stationsnummer
  int number = QInputDialog::getInt(this, tr("Erstellung einer neuen Gruppe"),
                                       tr("neue Nummer:"),0,1,200,1,&ok_number);
  
  // Eingabeauforderung des neuen Stationsnamens
  QString name = QInputDialog::getText(this, tr("Erstellung einer neuen Gruppe"),
                                       tr("neuer Name:"), QLineEdit::Normal,QString(),&ok_name);
  
  // Text im stacked Layout
  QString text (QString::number(number));
  text.append(": ");
  text.append(name);
  
  // Wenn durch "ok" bestätigt
  if (ok_number && ok_name)
  { 
    // Abfrage ob Gruppe bereits vorhanden ist
    if (checkDoubleGroup(number))
    {
      // Warnung ausgeben
      QMessageBox msgBox;
      msgBox.setIcon(QMessageBox::Warning);
      msgBox.setText("Diese Gruppe ist bereits vorhanden!");
      msgBox.setInformativeText("Gruppe wird nicht hinzugefügt");
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.setDefaultButton(QMessageBox::Ok);
      msgBox.exec();

      return;
    }

    // Hinzufügen des items und aktiv setzen
    dropDown_->addItem(text);
    dropDown_->setCurrentIndex(dropDown_->count() - 1);

    // Anlegen der neuen Gruppe
    newGroup = this->newGroup(name, number);
    
    // Aufrufen der Gruppenspezifischen Eingaben
    newGroup->openProperties();
    
    // Hinzufügen zum stacked Layout
    sLayout_->addWidget(newGroup);
    sLayout_->setCurrentWidget(newGroup);
  }
  
  connect(getCurrentGroup()->getTable(), SIGNAL(cellDoubleClicked(int,int)), this, SLOT(editInput()));
  connect(getCurrentGroup()->getTable(), SIGNAL(cellPressed(int,int)), this, SLOT(resumeEditInput()));
  connect(bInputDelete_, SIGNAL(clicked()), this, SLOT(deleteEntry()));
}
//---------------------------------------------------------------------------------------
void CCentralAbstractInterface::deleteGroup()
{
  // Holen der aktuellen Gruppe und den index
  CGroup* delGroup = getCurrentGroup();
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
  sLayout_->setCurrentIndex(index);
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
  bEdit_ = new QPushButton("Eintrag bearbeiten");
  
  // Buttons ins Grid einfügen
  gLayout_->addWidget(bEdit_,0,inputList_.size());
  gLayout_->addWidget(bInputNew_,1,inputList_.size());
  
  //Deaktivieren des Bearbeiten-Buttons
  bEdit_->setDisabled(true);

  // connections
  connect(bInputNew_, SIGNAL(clicked()), this, SLOT(addEntry()));
  connect(bEdit_, SIGNAL(clicked()), this, SLOT(sendEditedInput()));
  connect(inputList_.at(0), SIGNAL(textEdited(QString)), this, SLOT(checkGroupName(QString)));
}
//---------------------------------------------------------------------------------------

void CCentralAbstractInterface::addEntry()
{
  // Holen der aktuellen Gruppe
  CGroup* group = getCurrentGroup();
  
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
  
}
//---------------------------------------------------------------------------------------
//TODO: In CGroup auslagern
void CCentralAbstractInterface::deleteEntry()
{
  getCurrentGroup()->deleteTableEntry();
}
//---------------------------------------------------------------------------------------

CGroup* CCentralAbstractInterface::getCurrentGroup()
{
    // Holen der aktuellen Gruppe
  CGroup* actualGroup = dynamic_cast<CGroup*>(sLayout_->currentWidget());
  
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
    inputList_.at(1)->setDisabled(true);
    inputList_.at(0)->setDisabled(true);
  }
  
  else
  {
    bInputNew_->setDisabled(false);
    bEdit_->setDisabled(true);
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

void CCentralAbstractInterface::setJoker(QString text)
{
  if(text == "ja")
  {
    inputList_.at(4)->setDisabled(true);
    inputList_.at(4)->setText(QString(""));
    inputList_.at(5)->setDisabled(true);
    inputList_.at(5)->setText(QString(""));
  }

  else
  {
    inputList_.at(4)->setDisabled(false);
    inputList_.at(5)->setDisabled(false);
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

  // Überprüfung in allen Gruppen, ob Nummer bereits vergeben
  for (int i = 0; i < sLayout_->count(); i++)
  {
    // Holen der Gruppe
    CGroup* actualGroup = dynamic_cast<CGroup*>(sLayout_->widget(i));

    // Überprüfung, ob Nummer "numb" in dieser Gruppe vorhanden
    for (int row = 0; row < actualGroup->getTable()->rowCount(); row++)
    {
      // Wenn "numb" gefunden
      if (actualGroup->getTable()->item(row, 0)->text().toInt() == numb)
      {
        // Namen holen
        QString name = actualGroup->getTable()->item(row, 1)->text();

        // Namen in Input setzen und weitere Bearbeitung sperren
        inputList_.at(1)->setText(name);
        inputList_.at(1)->setDisabled(true);
      }
    }
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

CGroup* CCentralAbstractInterface::getGroupAt(int index)
{
      // Holen der aktuellen Gruppe
  CGroup* GroupAt = dynamic_cast<CGroup*>(sLayout_->widget(index));
  
  return GroupAt;
}