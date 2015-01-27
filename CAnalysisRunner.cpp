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

