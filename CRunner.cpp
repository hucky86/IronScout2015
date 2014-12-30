
#include "CRunner.h"

CRunner::CRunner(QStringList parameter, QString text, int number):CGroup(parameter, text, number)
{
  // Widget für Gruppenspezifische Eingaben
  properties_ = new QWidget;
  gLayout_ = new QGridLayout;
  
  // Disqualifiziert?
  disqualified_ = new QCheckBox;
  // Läufer am Start
  runnerAtStart_ = new QLineEdit;
  // Taxischeine im Ziel
  taxiTicket_ = new QLineEdit;
  // Startzeit
  startTime_ = new QDateTimeEdit;
  // Zielzeit
  destinationTime_ = new QDateTimeEdit;
  
  // Zusammenbau des Gruppenspezifischen Widget
  gLayout_->addWidget(new QLabel("Disqualifiziert"),0,0);
  gLayout_->addWidget(disqualified_,0,1);
  gLayout_->addWidget(new QLabel("Läufer am Start"),1,0);
  gLayout_->addWidget(runnerAtStart_,1,1);
  gLayout_->addWidget(new QLabel("Taxischeine im Ziel"),2,0);
  gLayout_->addWidget(taxiTicket_,2,1);
  gLayout_->addWidget(new QLabel("Startzeit"),3,0);
  gLayout_->addWidget(startTime_,3,1);
  gLayout_->addWidget(new QLabel("Ankunftszeit"),4,0);
  gLayout_->addWidget(destinationTime_,4,1);
  gLayout_->addWidget(ok_,5,0);
  
  properties_->setLayout(gLayout_);
}

void CRunner::openProperties()
{
  properties_->setWindowFlags(Qt::WindowStaysOnTopHint);
  properties_->show();
}

