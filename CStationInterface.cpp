
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



