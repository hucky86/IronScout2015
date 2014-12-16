
#ifndef CGROUP_H
#define CGROUP_H

#include <QLabel>
#include "CTable.h"
 
class CGroup
{
 
  public:
    CGroup(QString name);
    
    CTable* getTable();
    QString getName();

 
  private:
    
    // Gruppenname
    const QString name_;
    
    // Gruppennummer
    int number_;
    
    // Zugehoerige Tabelle mit allen Informationen
    CTable* table_;
    
};
 
#endif // CGROUP_H