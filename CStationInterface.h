// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CStationInterface
// 
// Beschreibung:    Verwaltung des Interfaces der Ein- und Ausgabe für 
//                  Stationsgruppen.
//                  
//************************************************************************

#ifndef CStationInterface_H
#define CStationInterface_H

#include <QLineEdit>
#include <QCheckBox>

#include "CGroupInterface.h"
 
class CStationInterface : public CGroupInterface
{
 
  public:
    CStationInterface(QStringList parameter, QString text, int number);
    
  private:
//Widgets:
    // Disqualifiziert?
    QCheckBox* disqualified_;
    // Anzahl der Personen an der Station
    QLineEdit* numberPeople_;

    
  public slots:
    
  signals:
    
};
 
#endif // CStationInterface_H