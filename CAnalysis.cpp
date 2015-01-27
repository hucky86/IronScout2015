#include "CAnalysis.h"

CAnalysis::CAnalysis(CCentralAbstractInterface* interface)
{
  interface_=interface;
}
//---------------------------------------------------------------------------------------

void CAnalysis::buildGroups()
{
  // Durch alle Gruppen iterieren und groupList_ anlegen
  for (int i=0; i < interface_->getGroupNumber(); i++)
  {
    CGroupInterface* group = interface_->getGroupAt(i);
    
    // Durch alle Gruppeneinträge iterieren
    for (int j=0; j < group->getRowCount(); j++)
    {
      int number = group->getTable()->item(j,0)->text().toInt();
      string name = group->getTable()->item(j,1)->text().toStdString();
      
      // Überprüfung, ob Gruppe vorhanden ist
      if (groupList_.count(number) == 0)
      {
        groupList_.insert(groupList_.begin(),pair<int, CGroup*> (number, newGroup(name, number)));
      }
    }
  }
}

