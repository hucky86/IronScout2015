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
#include "CCentralStationInterface.h"
#include "CRunner.h"

class CAnalysisRunner : public CAnalysis
{
 
public:
  
// Konstruktoren:
  CAnalysisRunner(CCentralAbstractInterface* interface);
    
// Memberfunktionen:
  // Holt alle Daten aus dem Interface
  virtual void getData();

private:
//Membervariablen:
  CCentralStationInterface* station_;

//Memberfunktionen:
  // Neue Gruppe anlegen
  virtual CGroup* newGroup (string name, int number);
  
protected:
 
};

#endif // CANALYSISRUNNER_H