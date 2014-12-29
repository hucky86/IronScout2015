// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CCentralRunnerInterface
// 
// Beschreibung:    Zentrales Widget zur Verwaltung der Ein- und Ausgaben.
//                  Schnittstelle für Läufer.
// 
//************************************************************************

#ifndef CCENTRALRUNNERINTERFACE_H
#define CCENTRALRUNNERINTERFACE_H

#include <QString>

#include "CCentralAbstractInterface.h"

class CCentralRunnerInterface : public CCentralAbstractInterface
{
  Q_OBJECT
 
  public:
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralRunnerInterface(QString analysis);

  private:
  
// Widgets:

// Layouts:
    
//Membervariablen:
    
//Memberfunktionen:
    void buildInputValidators();

private slots:
    
signals:

};

#endif // CCENTRALRUNNERINTERFACE_H
