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
#include "CGroup.h"
#include "CGroupInterface.h"
#include "CStationInterface.h"
#include "CCentralRunnerInterface.h"

class CAnalysisRunner : public CAnalysis
{
 
public:
  
// Konstruktoren:
  CAnalysisRunner(CCentralAbstractInterface* firstInterface, CCentralAbstractInterface* secondInterface);
    
// Memberfunktionen:
  
private:
//Membervariablen:

//Memberfunktionen:
  // Neue Gruppe anlegen
  virtual CGroup* newGroup (string name, int number);
  
protected:
 
};

#endif // CANALYSISRUNNER_H