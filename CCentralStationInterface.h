// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CCentralStationInterface
// 
// Beschreibung:    Zentrales Widget zur Verwaltung der Ein- und Ausgaben.
//                  Schnittstelle für Stationen.
// 
//************************************************************************


#ifndef CCENTRALSTATIONINTERFACE_H
#define CCENTRALSTATIONINTERFACE_H

#include <QString>

#include "CCentralAbstractInterface.h"

class CCentralStationInterface : public CCentralAbstractInterface
{
  Q_OBJECT
 
  public:
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralStationInterface(QString analysis);
 
  private:
  
// Widgets:

// Layouts:
    
//Membervariablen:
    
//Memberfunktionen:
    void buildInputValidators();

private slots:
    
signals:

};

#endif // CCENTRALSTATIONINTERFACE_H