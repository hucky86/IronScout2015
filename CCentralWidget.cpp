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
      newGroup = new CStation(parameterStation_, text);
    }
    
    else if(analysis_ == "Läufer")
    {
      newGroup = new CRunner(text);
    }
    
    // neue Gruppe anlegen und dem QStackedLayout hinzufügen
    //CGroup* newGroup = new CGroup(text);
    groupList_.append(newGroup);
  
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
  QStringList p;
  
  if (analysis_ == "Station")
  {
    p = parameterStation_;
  }
  
  else if (analysis_ == "Läufer")
  {
    //TODO:
  }
  
  else
  {
    //TODO: Ausnahmefehlerbehandlung
  }
  
  // Bauen des Eingabefeldes
  // Hinzufügen der Label
  for (int i = 0; i < p.size(); i++)
  {
    gLayout_->addWidget(new QLabel(p.at(i)),0,i);
  }
  
  // Hinzufügen der Eingabefelder
  for (int i = 0; i < p.size(); i++)
  {
    gLayout_->addWidget(new QLineEdit,1,i);
  }
  
  // Hinzufügen des Bestätigungs-Buttons
  inputButton_ = new QPushButton("Eintrag hinzufügen");
  gLayout_->addWidget(inputButton_,1,p.size());
}

QStringList CCentralWidget::parameterStation_ = QStringList() << "Laeufername" << "#" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
QStringList CCentralWidget::parameterRunner_ = QStringList() << "Stationsnr." << "Stationsname" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";



