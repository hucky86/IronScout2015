#include "CAnalysisRunner.h"

CAnalysisRunner::CAnalysisRunner(CCentralAbstractInterface* interface):CAnalysis(interface)
{
  // Cast zum entsprechenden CCentralStationInterface
  stationInterface_ = dynamic_cast<CCentralStationInterface*>(interface);
}
//---------------------------------------------------------------------------------------

void CAnalysisRunner::getData()
{
  // Holen der Daten und Abspeichern
  for(map<int, CGroup*>::const_iterator it = groupList_.begin(); it != groupList_.end(); it++)
  {
    // Durch alle Stationen iterieren
    for(int i = 0; i < stationInterface_->getGroupNumber(); i++)
    {
      CGroupInterface* station = stationInterface_->getGroupAt(i);
      
      // Durch alle Einträge der Station iterieren, um Gruppe zu finden
      for(int j = 0; j < station->getNumber(); j++)
      {
        // Wenn die Gruppe gefunden wurde
        if(station->getNumberAt(j) == it->second->getNumber())
        {
          // Abspeichern der Daten
          
        }
      }
    }
  }
}
//---------------------------------------------------------------------------------------

CGroup* CAnalysisRunner::newGroup(string name, int number)
{
  return new CRunner(name, number);
}


