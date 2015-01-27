#include "CAnalysisRunner.h"

CAnalysisRunner::CAnalysisRunner(CCentralAbstractInterface* interface):CAnalysis(interface)
{
  // Cast zum entsprechenden CCentralStationInterface
  station_ = dynamic_cast<CCentralStationInterface*>(interface);
}
//---------------------------------------------------------------------------------------

void CAnalysisRunner::getData()
{
  // Holen der Daten und Abspeichern
}
//---------------------------------------------------------------------------------------

CGroup* CAnalysisRunner::newGroup(string name, int number)
{
  return new CRunner(name, number);
}


