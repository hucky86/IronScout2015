#include "CAnalysisRunner.h"

CAnalysisRunner::CAnalysisRunner(CCentralAbstractInterface* firstInterface, CCentralAbstractInterface* secondInterface)
:CAnalysis(firstInterface, secondInterface)
{

}
//---------------------------------------------------------------------------------------

CGroup* CAnalysisRunner::newGroup(string name, int number)
{
  return new CRunner(name, number);
}
//---------------------------------------------------------------------------------------





