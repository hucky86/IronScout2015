#include "CAnalysis.h"

CAnalysis::CAnalysis(CCentralAbstractInterface* interface)
{
  // Durch alle Gruppen iterieren und groupList_ anlegen
  for (int i=0; i < interface->getGroupNumber(); i++)
  {
    CGroupInterface* group = interface->getGroupAt(i);
    
    // Durch alle Gruppeneinträge iterieren
    for (int j=0; j < group->getRowCount(); j++)
    {
      int number = group->getTable()->item(j,0)->text().toInt();
      string name = group->getTable()->item(j,1)->text().toStdString();
      
      // Überprüfung, ob Gruppe vorhanden ist
      if (groupList_.find(number) != groupList_.end())
      {
        groupList_.insert(groupList_.begin(),pair<int, CGroup> (number, CGroup(name, number)));
      }
    }
  }
}
