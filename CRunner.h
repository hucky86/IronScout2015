// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CRunner
// 
// Beschreibung:    Verwaltung des Interfaces der Ein- und Ausgabe für 
//                  Läufergruppen.
//                  
//************************************************************************

#ifndef CRUNNER_H
#define CRUNNER_H

#include "CGroup.h"
 
class CRunner : public CGroup
{
 
  public:
    CRunner(QStringList parameter, QString text, int number);

 
  private:
    
  protected:

    
};
 
#endif // CRUNNER_H