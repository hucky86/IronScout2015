#ifndef CSTATION_H
#define CSTATION_H

#include <QHeaderView>

#include "CGroup.h"
 
class CStation : public CGroup
{
 
  public:
    CStation(QString name);

  private:
    void buildTable();
    
};
 
#endif // CSTATION_H