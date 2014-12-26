#include "CCentralWidget.h"

CCentralWidget::CCentralWidget(QString analysis)
{ 
  // Auswahl der Analyse (Station oder Läufer?)
  analysis_ = analysis;
  
  // Anlegen der Layouts
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  gLayout_ = new QGridLayout;
  
  // Anlegen der Widgets
  dropDown_ = new QComboBox;
  bNew_ = new QPushButton("Neu: " + analysis_);
  bDelete_ = new QPushButton("Löschen: " + analysis_);
  bInputDelete_ = new QPushButton("Eintrag löschen");
  buildInputLayout();
  
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
  connect(bInputNew_, SIGNAL(clicked()), this, SLOT(addEntry()));
  connect(bInputDelete_, SIGNAL(clicked()), this, SLOT(deleteEntry()));
  connect(bEdit_, SIGNAL(clicked()), this, SLOT(sendEditedInput()));
}
//---------------------------------------------------------------------------------------

void CCentralWidget::addGroup()
{
  bool ok_name;
  bool ok_number;
  CGroup* newGroup;

  // Eingabeauforderung der neuen Stationsnummer
  int number = QInputDialog::getInt(this, tr("Erstellung einer neuen: ") + analysis_,
                                       tr("neue Nummer:"),0,1,200,1,&ok_number);
  
  // Eingabeauforderung des neuen Stationsnamens
  QString name = QInputDialog::getText(this, tr("Erstellung einer neuen: ") + analysis_,
                                       tr("neuer Name:"), QLineEdit::Normal,QString(),&ok_name);
  
  // Text im stacked Layout
  QString text (QString::number(number));
  text.append(": ");
  text.append(name);

  
  // Wenn durch "ok" bestätigt
  if (ok_number && ok_name)
  {
    // Hinzufügen des items und aktiv setzen
    dropDown_->addItem(text);
    dropDown_->setCurrentIndex(dropDown_->count() - 1);
    
    // Unterscheidung ob es sich um eine Stations- oder Läuferauswertung handelt
    if(analysis_ == "Station")
    {
      newGroup = new CStation(parameter_, name, number);
    }
    
    else if(analysis_ == "Läufer")
    {
      newGroup = new CRunner(parameter_, name, number);
    }
    
    // Hinzufügen zum stacked Layout
    sLayout_->addWidget(newGroup);
    sLayout_->setCurrentWidget(newGroup);
  }
  
  connect(getCurrentGroup()->getTable(), SIGNAL(cellDoubleClicked(int,int)), this, SLOT(editInput()));
  connect(getCurrentGroup()->getTable(), SIGNAL(cellPressed(int,int)), this, SLOT(resumeEditInput()));
}
//---------------------------------------------------------------------------------------
void CCentralWidget::deleteGroup()
{  
  CGroup* delGroup = getCurrentGroup();
  int index = sLayout_->indexOf(delGroup);

  dropDown_->removeItem(index);
  sLayout_->removeWidget(delGroup);
  
  delete delGroup;
}
//---------------------------------------------------------------------------------------

void CCentralWidget::changeGroup(int index)
{
  sLayout_->setCurrentIndex(index);
}
//---------------------------------------------------------------------------------------

void CCentralWidget::buildInputLayout()
{
  // Hier werden die Parameter der Auswertung festgelegt
  // TODO: Besser als const in eigene source auslagern...
  QStringList parameterStation_ = QStringList() << "Laeufername" << "#" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
  QStringList parameterRunner_ = QStringList() << "Stationsnr." << "Stationsname" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
  // Auswertung entsprechend anlegen
  if (analysis_ == "Station")
  {
    parameter_ = parameterStation_;
  }
  
  else if (analysis_ == "Läufer")
  {
    parameter_ = parameterRunner_;
  }
  
  else
  {
    //TODO: Ausnahmefehlerbehandlung
  }
  
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
}
//---------------------------------------------------------------------------------------

void CCentralWidget::addEntry()
{
  // Holen der aktuellen Gruppe
  CGroup* group = getCurrentGroup();
  
  if (group == NULL)
  {
    // TODO: Execption
    return;
  }
  
  // Eintrag hinzufügen
  group->addTableEntry(inputList_);
  
  // Input leeren
  emptyInput();
}
//---------------------------------------------------------------------------------------
//TODO: In CGroup auslagern
void CCentralWidget::deleteEntry()
{
  getCurrentGroup()->deleteTableEntry();
}
//---------------------------------------------------------------------------------------

CGroup* CCentralWidget::getCurrentGroup()
{
    // Holen der aktuellen Gruppe
  CGroup* actualGroup = dynamic_cast<CGroup*>(sLayout_->currentWidget());
  
  return actualGroup;
}
//---------------------------------------------------------------------------------------

void CCentralWidget::editInput()
{
  // Umstellen der Button Aktivität
  changeToEditStatus(true);
  
  writeToInput();
}
//---------------------------------------------------------------------------------------

void CCentralWidget::resumeEditInput()
{
  // Umstellen der Button Aktivität
  changeToEditStatus(false);
  
  emptyInput();
}
//---------------------------------------------------------------------------------------

void CCentralWidget::emptyInput()
{
  QString empty ("");
  
  // Übertragung der Daten auf die Input Felder
  for(int i = 0; i < inputList_.size(); i++)
  { 
    inputList_.at(i)->setText(empty);
  }
}
//---------------------------------------------------------------------------------------

void CCentralWidget::sendEditedInput()
{
  changeToEditStatus(false);
  
  writeToTable();
  
  emptyInput();
}
//---------------------------------------------------------------------------------------

void CCentralWidget::changeToEditStatus(bool editStatus)
{
  // Abfrage des Status
  if(editStatus)
  {
    bInputNew_->setDisabled(true);
    bEdit_->setDisabled(false);
  }
  
  else
  {
    bInputNew_->setDisabled(false);
    bEdit_->setDisabled(true);
  }
}
//---------------------------------------------------------------------------------------

void CCentralWidget::writeToTable()
{
  // Ermittlung der aktivierten Zeile und des aktuellen table
  int row = getCurrentGroup()->getTable()->currentRow();
  QTableWidget* table = getCurrentGroup()->getTable();
  
  // Übertragung der Daten auf die Input Felder
  for(int i = 0; i < inputList_.size(); i++)
  {
    QString text = inputList_.at(i)->text();
    
    table->item(row,i)->setText(text);
  }
}
//---------------------------------------------------------------------------------------

void CCentralWidget::writeToInput()
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




