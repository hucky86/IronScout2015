#include "CStationInterface.h"

CStationInterface::CStationInterface(QStringList parameter, QString text, int number):CGroupInterface(parameter, text, number)
{  
  // Widget für Gruppenspezifische Eingaben
  properties_ = new QWidget;
  gLayout_ = new QGridLayout;
  
  // Disqualifiziert?
  disqualified_ = new QCheckBox;
  // Anzahl Personen an der Station
  numberPeople_ = new QLineEdit;
  numberPeople_->setValidator(new QIntValidator(4, 12, this));
  
  // Zusammenbau des Gruppenspezifischen Widget
  gLayout_->addWidget(new QLabel("Disqualifiziert"),0,0);
  gLayout_->addWidget(disqualified_,0,1);
  gLayout_->addWidget(new QLabel("Anzahl Personen an der Station"),1,0);
  gLayout_->addWidget(numberPeople_,1,1);
  gLayout_->addWidget(ok_,2,0);
  
  properties_->setLayout(gLayout_);
}
//---------------------------------------------------------------------------------------

int CStationInterface::getNumberRunnerAt(int row)
{
  int number = table_->item(row,2)->text().toInt();
  
  return number;
}
//---------------------------------------------------------------------------------------

bool CStationInterface::getJokerAt(int row)
{
  // Text im Feld Joker holen
  std::string joker_text = table_->item(row,3)->text().toStdString();
  
  // Überprüfen ob Joker benutzt wurde
  if (joker_text == "ja")
  {
    return true;
  }
  
  else
  {
    return false;
  }
}
//---------------------------------------------------------------------------------------

int CStationInterface::getPointsAt(int row)
{
  int points = table_->item(row,4)->text().toInt();
  
  return points;
}
//---------------------------------------------------------------------------------------

int CStationInterface::getTeamworkAt(int row)
{
  int teamwork = table_->item(row,5)->text().toInt();
  
  return teamwork;
}
//---------------------------------------------------------------------------------------

int CStationInterface::getNumberPeople()
{
  return numberPeople_->text().toInt();
}

//---------------------------------------------------------------------------------------

void CStationInterface::saveProperties(std::ofstream& saveFile)
{
  saveFile << isdisqualified() << "\t" << getNumberPeople() << "\t";
}
//---------------------------------------------------------------------------------------

void CStationInterface::loadProperties(std::stringstream& stream)
{ 
  std::string parser;
  
  // Disqualifiziert?
  getline(stream,parser,'\t');
  disqualified_->setChecked(strcasecmp("true",parser.c_str()) == 0);
  
  // Mitgliederanzahl der Station
  getline(stream,parser,'\t');
  numberPeople_->setText(QString(parser.c_str()));
}



