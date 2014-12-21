#ifndef CSTATION_H
#define CSTATION_H

#include <QHeaderView>
#include <QLineEdit>

#include "CGroup.h"
 
class CStation : public CGroup
{
 
  public:
    CStation(QString name);

  private:
    void buildTable();
    
    QStringList parameters_;
    
};
 
#endif // CSTATION_H