// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CAnalysisRunner
// 
// Beschreibung:    Stellt Schnittstelle für Auswerteroutinen zur
//                  Verfügung. Abgeleitet von CAnalysis zur Auswertung der
//                  Läufergruppen.
// 
//************************************************************************


#ifndef CANALYSISRUNNER_H
#define CANALYSISRUNNER_H

#include "CAnalysis.h"

class CAnalysisRunner : public CAnalysis
{
 
public:
  
// Konstruktoren:
  CAnalysisRunner(CCentralAbstractInterface* interface);
    
// Memberfunktionen:

private:
//Membervariablen:

//Memberfunktionen:
  // Holt alle Daten aus dem Interface
  virtual void getData();
  
protected:
 
};

#endif // CANALYSISRUNNER_H