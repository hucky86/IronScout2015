#ifndef CSTATION_H
#define CSTATION_H

#include <QHeaderView>
#include <QLineEdit>

#include "CGroup.h"
 
class CStation : public CGroup
{
 
  public:
    CStation(QStringList parameter, QString name);

  private:
    void buildTable();
    
    QStringList parameter_;
    
};
 
#endif // CSTATION_H