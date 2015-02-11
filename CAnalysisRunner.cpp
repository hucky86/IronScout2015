#include "CAnalysisRunner.h"

CAnalysisRunner::CAnalysisRunner(CCentralAbstractInterface* interface):CAnalysis(interface)
{

}
//---------------------------------------------------------------------------------------

CGroup* CAnalysisRunner::newGroup(string name, int number)
{
  return new CRunner(name, number);
}
//---------------------------------------------------------------------------------------

void CAnalysisRunner::getData()
{
  // Holen der Daten aus den Tabelleneinträgenn und Abspeichern
  // Durch alle bereits gefundenen Gruppen
  for(map<int, CGroup*>::const_iterator it = groupList_.begin(); it != groupList_.end(); it++)
  {
    // Durch alle Stationen iterieren
    for(int i = 0; i < interface_->getGroupNumber(); i++)
    {
      CStationInterface* station = dynamic_cast<CStationInterface*>(interface_->getGroupAt(i));
      
      // Durch alle Einträge der Station iterieren, um Gruppe zu finden
      for(int row = 0; row < station->getNumber(); row++)
      {
        // Wenn die Gruppe gefunden wurde
        if(station->getNumberAt(row) == it->second->getNumber())
        {
          // Abspeichern der Daten
          it->second->setTableEntries(station, row);
        }
      }
    }
  }
}



