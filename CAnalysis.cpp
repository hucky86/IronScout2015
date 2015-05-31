#include "CAnalysis.h"

CAnalysis::CAnalysis(CCentralAbstractInterface* firstInterface, CCentralAbstractInterface* secondInterface)
{
  firstInterface_=firstInterface;
  secondInterface_=secondInterface;
}
//---------------------------------------------------------------------------------------

void CAnalysis::buildGroups()
{
  // Durch alle Gruppen iterieren und groupList_ anlegen
  for (int i=0; i < firstInterface_->getGroupNumber(); i++)
  {
    CGroupInterface* group = firstInterface_->getGroupAt(i);
    
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
//---------------------------------------------------------------------------------------

void CAnalysis::deleteGroups()
{
  // Zunächst alle Pointer löschen
  for (map<int, CGroup*>::const_iterator it = groupList_.begin(); it != groupList_.end(); it++)
  {
    delete it->second;
  }
  
  // Gruppenliste löschen
  groupList_.clear();
}
//---------------------------------------------------------------------------------------

void CAnalysis::getData()
{
  //TODO: Überprüfung ob auch zu jedem Eintrag in firstInterface ein Entrag in secondInterface vorliegt!
    
  // Holen der Daten aus den Tabelleneinträgenn und Abspeichern
  // Durch alle bereits gefundenen Gruppen
  for(map<int, CGroup*>::const_iterator it = groupList_.begin(); it != groupList_.end(); it++)
  {
    // Durch alle Stationen iterieren
    for(int i = 0; i < firstInterface_->getGroupNumber(); i++)
    {
      CGroupInterface* group = firstInterface_->getGroupAt(i);
      
      // Durch alle Einträge der Station iterieren, um Gruppe zu finden
      for(int row = 0; row < group->getRowCount(); row++)
      {
        // Wenn die Gruppe gefunden wurde
        if(group->getNumberAt(row) == it->second->getNumber())
        {
          // Abspeichern der Daten
          it->second->setTableEntries(group, row);
        }
      }
    }
    
    // Durch alle Läuferbögen iterieren und Gruppenspezifische Einträge holen
    for (int i = 0; i < secondInterface_->getGroupNumber(); i++)
    {
      CGroupInterface* group = secondInterface_->getGroupAt(i);
      
      // Wenn Gruppe gefunden
      if(group->getNumber() == it->second->getNumber())
      {
        //Abspeichern der Daten
        it->second->setGroupEntries(group);
      }
    }
  }
}
//---------------------------------------------------------------------------------------

void CAnalysis::evaluate()
{
  // Durch alle Gruppen
  for (map<int, CGroup*>::iterator it = groupList_.begin(); it != groupList_.end(); it++)
  {
    it->second->evaluate();
  }
}

