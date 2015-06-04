
#include "CRunnerInterface.h"

CRunnerInterface::CRunnerInterface(QStringList parameter, QString text, int number):CGroupInterface(parameter, text, number)
{
  buildProperties();
  
  buildUncrewedStation();
}
//---------------------------------------------------------------------------------------

bool CRunnerInterface::isdisqualified()
{
  bool disqualified = disqualified_->isChecked();
  
  return disqualified;
}
//---------------------------------------------------------------------------------------

int CRunnerInterface::runnerAtStart()
{
  return runnerAtStart_->text().toInt();
}
//---------------------------------------------------------------------------------------

int CRunnerInterface::taxiTicket()
{
  return taxiTicket_->text().toInt();
}
//---------------------------------------------------------------------------------------

unsigned int CRunnerInterface::usedTime()
{
  unsigned int time = destinationTime_->time().minute() - startTime_->time().minute();
  
  return time;
}
//---------------------------------------------------------------------------------------

void CRunnerInterface::buildProperties()
{
  // Widget für Gruppenspezifische Eingaben
  properties_ = new QWidget;
  gLayout_ = new QGridLayout;
  
  // Disqualifiziert?
  disqualified_ = new QCheckBox;
  // Läufer am Start
  runnerAtStart_ = new QLineEdit;
  runnerAtStart_->setValidator(new QIntValidator(4, 10, this));
  // Taxischeine im Ziel
  taxiTicket_ = new QLineEdit;
  taxiTicket_->setValidator(new QIntValidator(0, 10, this));
  // Startzeit
  startTime_ = new QDateTimeEdit;
  startTime_->setDateTime(QDateTime(QDate(2015,10,9), QTime(13,0)));
  // Zielzeit
  destinationTime_ = new QDateTimeEdit;
  destinationTime_->setDateTime(QDateTime(QDate(2015,10,10), QTime(20,0)));
  
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
  gLayout_->addWidget(new QLabel("Unbemannte Posten erreicht und beantwortet?"),5,0);
  
  properties_->setLayout(gLayout_);
}
//---------------------------------------------------------------------------------------

void CRunnerInterface::buildUncrewedStation()
{
  // Anzahl der unbemannten Posten
  int nUncrewedStations = 10;
  int infos = gLayout_->rowCount();
  
  // Für jede unbemannte Station ein Eintrag
  for (int i = 1; i < nUncrewedStations; i++)
  {
    // Anlegen der Referenzen
    uncrewedStation_.push_back(new QCheckBox);
    
    // Anlegen der Einträge
    int row = i+infos;
    QString text = "Nr " + QString::number(i) + ":";
    
    gLayout_->addWidget(new QLabel(text),row,0);
    gLayout_->addWidget(uncrewedStation_.back(),row,1);
  }
  
  gLayout_->addWidget(ok_,infos+nUncrewedStations,0);
  
}


