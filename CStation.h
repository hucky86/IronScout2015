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

#include "CGroup.h"
 
class CStation : public CGroup
{
 
  public:
    CStation(QStringList parameter, QString text, int number);

    // Aufrufen der Eingabeaufforderung der Gruppenspezifischen Eingaben
    virtual void openProperties();
    
  private:
    
  public slots:
    
  signals:
    
};
 
#endif // CSTATION_H