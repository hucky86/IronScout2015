#include "CCentralWidget.h"

CCentralWidget::CCentralWidget(QString analysis)
{ 
  // Auswertung Station oder Läufer
  analysis_ = analysis;
  
  // Anlegen der Layouts
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  gLayout_ = new QGridLayout;
  
  // Anlegen der Widgets
  dropDown_ = new QComboBox;
  button_ = new QPushButton("Neu: " + analysis_);
  buildInputLayout();
  
  // Konfigurieren der Layouts
  hLayout_->addWidget(dropDown_);
  hLayout_->addWidget(button_);
  
  vLayout_->addLayout(hLayout_);
  vLayout_->addLayout(gLayout_);
  vLayout_->addLayout(sLayout_);
    
  this->setLayout(vLayout_);
  
  // setzen der connections
  connect(button_, SIGNAL(clicked()), this, SLOT(addGroup()));
  connect(dropDown_, SIGNAL(activated(int)), this, SLOT(changeGroup(int)));
  connect(inputButton_, SIGNAL(clicked()), this, SLOT(addEntry()));
}

void CCentralWidget::addGroup()
{
  bool ok;
  CGroup* newGroup;

  // Eingabeauforderung des neuen Stationsnamens
  QString text = QInputDialog::getText(this, tr("Erstellung einer neuen: ") + analysis_,
                                       tr("neuer Name:"), QLineEdit::Normal,QString(),&ok);
  // Wenn durch "ok" bestätigt
  if (ok)
  {
    // Hinzufügen des items und aktiv setzen
    dropDown_->addItem(text);
    dropDown_->setCurrentIndex(dropDown_->count() - 1);
    
    if(analysis_ == "Station")
    {
      newGroup = new CStation(parameter_, text);
    }
    
    else if(analysis_ == "Läufer")
    {
      newGroup = new CRunner(parameter_, text);
    }
  
    sLayout_->addWidget(newGroup);
    sLayout_->setCurrentWidget(newGroup);
  }
}

void CCentralWidget::changeGroup(int index)
{
  sLayout_->setCurrentIndex(index);
}

void CCentralWidget::buildInputLayout()
{
  QStringList parameterStation_ = QStringList() << "Laeufername" << "#" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
  QStringList parameterRunner_ = QStringList() << "Stationsnr." << "Stationsname" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
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
  
  // Hinzufügen des Bestätigungs-Buttons
  inputButton_ = new QPushButton("Eintrag hinzufügen");
  gLayout_->addWidget(inputButton_,1,parameter_.size());
}

void CCentralWidget::addEntry()
{
  // Holen der aktuellen Gruppe
  CGroup* actualGroup = dynamic_cast<CGroup*>(sLayout_->currentWidget());
  
  if (actualGroup == NULL)
  {
    // TODO: Execption
    return;
  }
  
  // Neue Zeile hinzufügen
  actualGroup->table_->insertRow(actualGroup->table_->rowCount());
  
  for (int i = 0; i < gLayout_->columnCount()-1; i++)
  {
    // Anlegen des QLineEdit
    QLineEdit* input = dynamic_cast<QLineEdit*>(gLayout_->itemAtPosition(1,i)->widget());
    
    if (input == NULL)
    {
      // TODO: Execption; Programm schließen
    }
    
    // Holen des TableWidgetItem
    QTableWidgetItem* p = new QTableWidgetItem;
    
    // Einfügen in die Tabelle
    actualGroup->table_->setItem(actualGroup->table_->rowCount() - 1, i, p);
    p->setText(input->text());
  }
}



