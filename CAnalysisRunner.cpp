#include "CAnalysisRunner.h"

CAnalysisRunner::CAnalysisRunner(CCentralAbstractInterface* interface):CAnalysis(interface)
{

}
//---------------------------------------------------------------------------------------

CGroup* CAnalysisRunner::newGroup(string name, int number)
{
  return new CRunner(name, number);
}
//---------------------------------------------------------------------------------------

void CAnalysisRunner::mapData()
{

}


