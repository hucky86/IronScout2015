#ifndef CRUNNER_H
#define CRUNNER_H

#include "CGroup.h"
 
class CRunner : public CGroup
{
 
  public:
    CRunner(QString name);

 
  private:
    
  protected:
  
    void buildTable ();
    
};
 
#endif // CRUNNER_H