#include "CRunnerInterface.h"

CRunnerInterface::CRunnerInterface(QStringList parameter, QString text, int number):CGroupInterface(parameter, text, number)
{
  buildProperties();
  
  buildUncrewedStation();
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

int CRunnerInterface::usedTime()
{
  int time = startTime_->dateTime().secsTo(destinationTime_->dateTime());
  QDateTime latestTime = QDateTime(QDate(2015,10,9), QTime(18,0));
  
  if(startTime_->dateTime() > latestTime)
  {
    time += latestTime.secsTo(startTime_->dateTime());
  }
  
  return time;
}
//---------------------------------------------------------------------------------------

std::vector<Qt::CheckState> CRunnerInterface::uncrewedStations()
{
  std::vector<Qt::CheckState> uncrewedStation;
  
  for(int i = 0; i < uncrewedStation_.size(); i++)
  {
    uncrewedStation.push_back(uncrewedStation_.at(i)->checkState());
  }
  
  return uncrewedStation;
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
  gLayout_->addWidget(new QLabel("Läufer am Start"),0,0);
  gLayout_->addWidget(runnerAtStart_,0,1);
  gLayout_->addWidget(new QLabel("Startzeit"),1,0);
  gLayout_->addWidget(startTime_,1,1);
  gLayout_->addWidget(new QLabel("Taxischeine im Ziel"),2,0);
  gLayout_->addWidget(taxiTicket_,2,1);
  gLayout_->addWidget(new QLabel("Ankunftszeit"),3,0);
  gLayout_->addWidget(destinationTime_,3,1);
  gLayout_->addWidget(new QLabel("Disqualifiziert"),4,0);
  gLayout_->addWidget(disqualified_,4,1);
  gLayout_->addWidget(new QLabel("Unbemannte Posten erreicht und beantwortet?"),5,0);
  
  properties_->setLayout(gLayout_);
}
//---------------------------------------------------------------------------------------

void CRunnerInterface::buildUncrewedStation()
{
  // Anzahl der unbemannten Posten
  int nUncrewedStations = 8;
  int infos = gLayout_->rowCount();
  
  // Für jede unbemannte Station ein Eintrag
  for (int i = 0; i < nUncrewedStations; i++)
  { 
    // Anlegen der Referenzen
    uncrewedStation_.push_back(new QCheckBox);
    
    // Anlegen der Einträge
    int row = i+infos;
    QString text = "Nr " + QString::number(i+1) + ":";
    
    gLayout_->addWidget(new QLabel(text),row,0);
    gLayout_->addWidget(uncrewedStation_.back(),row,1);
    uncrewedStation_.back()->setTristate();
  }
  
  gLayout_->addWidget(ok_,infos+nUncrewedStations+1,0);
  
}
//---------------------------------------------------------------------------------------

void CRunnerInterface::saveProperties(std::ofstream& saveFile)
{
  std::string startTime;
  std::string destinationTime;
  
  startTime = startTime_->dateTime().toString().toStdString();
  destinationTime = destinationTime_->dateTime().toString().toStdString();
  
  saveFile << isdisqualified() << "\t" << startTime << "\t" << destinationTime << "\t"
    << runnerAtStart() << "\t" << taxiTicket() << "\t";
    
    for(int i = 0; i < uncrewedStation_.size(); i++)
    {
      saveFile << uncrewedStation_.at(i)->checkState();
      saveFile << "\t";
    }
}
//---------------------------------------------------------------------------------------

void CRunnerInterface::loadProperties(std::stringstream& stream)
{
  std::string parser;
  
  // Disqualifiziert?
  getline(stream,parser,'\t');
  disqualified_->setChecked(strcasecmp("true",parser.c_str()) == 0);
  
  //Startzeit
  getline(stream,parser,'\t');
  startTime_->setDateTime(QDateTime::fromString(QString(parser.c_str())));
  
  //Ankunftszeit
  getline(stream,parser,'\t');
  destinationTime_->setDateTime(QDateTime::fromString(QString(parser.c_str())));
  
  //Läufer am Start
  getline(stream,parser,'\t');
  runnerAtStart_->setText(QString(parser.c_str()));
  
  //Taxi Scheine im Ziel
  getline(stream,parser,'\t');
  taxiTicket_->setText(QString(parser.c_str()));
  
  // unbemannte Posten
  for(int i = 0; i < uncrewedStation_.size(); i++)
  {
    getline(stream,parser,'\t');
    
    uncrewedStation_.at(i)->setCheckState(static_cast<Qt::CheckState>((atoi(parser.c_str()))));
  }
}
//---------------------------------------------------------------------------------------

int CRunnerInterface::getGameIdeaAt(int row)
{  
  int idea = table_->item(row,2)->text().toInt();
  
  return idea;
}
//---------------------------------------------------------------------------------------

int CRunnerInterface::getGameDesignAt(int row)
{
 int design = table_->item(row,3)->text().toInt();
  
  return design;
}
//---------------------------------------------------------------------------------------

int CRunnerInterface::getAtmosphereAt(int row)
{
  int atmosphere = table_->item(row,4)->text().toInt();
  
  return atmosphere;
}
//---------------------------------------------------------------------------------------

bool CRunnerInterface::compareProperties(CGroupInterface* other)
{
  CRunnerInterface* otherRunner = dynamic_cast<CRunnerInterface*>(other);
  
  if(this->runnerAtStart() != otherRunner->runnerAtStart() ||
     this->taxiTicket() != otherRunner->taxiTicket() ||
     this->usedTime() != otherRunner->usedTime() ||
     this->compareUncrewedStations(otherRunner) == false)
  {
    return false;
  }
  
  return true;
}
//---------------------------------------------------------------------------------------

bool CRunnerInterface::compareUncrewedStations(CRunnerInterface* otherRunner)
{
  for(int i = 0; i < this->uncrewedStation_.size(); i++)
  {
    if(this->uncrewedStation_[i]->checkState() != otherRunner->uncrewedStation_[i]->checkState())
    {
      return false;
    }
  }
  
  return true;
}





