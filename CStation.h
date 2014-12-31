// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CStation
// 
// Beschreibung:    Verwaltung des Interfaces der Ein- und Ausgabe für 
//                  Stationsgruppen.
//                  
//************************************************************************

#ifndef CSTATION_H
#define CSTATION_H

#include <QLineEdit>
#include <QCheckBox>

#include "CGroup.h"
 
class CStation : public CGroup
{
 
  public:
    CStation(QStringList parameter, QString text, int number);
    
  private:
//Widgets:
    // Disqualifiziert?
    QCheckBox* disqualified_;
    // Anzahl der Personen an der Station
    QLineEdit* numberPeople_;

    
  public slots:
    
  signals:
    
};
 
#endif // CSTATION_H