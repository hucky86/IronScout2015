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
#include "CGroupInterface.h"

class CAnalysisRunner : public CAnalysis
{
 
public:
  
// Konstruktoren:
  CAnalysisRunner(CCentralAbstractInterface* interface);
    
// Memberfunktionen:

private:
//Membervariablen:

//Memberfunktionen:
  // Neue Gruppe anlegen
  virtual CGroup* newGroup (string name, int number);
  // Speichert Daten in groupList_ einer Gruppe ab
  virtual void mapData();
  
protected:
 
};

#endif // CANALYSISRUNNER_H