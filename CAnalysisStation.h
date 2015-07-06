// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CAnalysisStation
// 
// Beschreibung:    Stellt Schnittstelle für Auswerteroutinen zur
//                  Verfügung. Abgeleitet von CAnalysis zur Auswertung der
//                  Stationsgruppen.
// 
//************************************************************************


#ifndef CANALYSISSTATION_H
#define CANALYSISSTATION_H

#include "CAnalysis.h"
#include "CStation.h"

class CAnalysisStation : public CAnalysis
{
 
public:
  
// Konstruktoren:
  CAnalysisStation(CCentralAbstractInterface* firstInterface, CCentralAbstractInterface* secondInterface);
    
// Memberfunktionen:
  
private:
//Membervariablen:

//Memberfunktionen:
  // Neue Gruppe anlegen
  virtual CGroup* newGroup (string name, int number);
  
protected:
 
};

#endif // CANALYSISSTATION_H