#include "CAnalysis.h"

CAnalysis::CAnalysis(CCentralAbstractInterface* interface)
{
  // Durch alle Gruppen iterieren und groupList_ anlegen
  for (int i=0; i < interface->getGroupNumber(); i++)
  {
    CGroupInterface* group = interface->getGroupAt(i);
    
    // Durch alle Gruppeneinträge iterieren
  }
}
