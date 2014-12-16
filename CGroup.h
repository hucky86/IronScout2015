
#ifndef CGROUP_H
#define CGROUP_H

#include <QString>
#include "CTable.h"
 
class CGroup
{
 
  public:
    CGroup();
    
    CTable* getTable();

 
  private:
    
    // Gruppenname
    QString name_;
    
    // Gruppennummer
    int number_;
    
    // Zugehoerige Tabelle mit allen Informationen
    CTable* table_;
    
};
 
#endif // CGROUP_H