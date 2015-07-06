#include "CAnalysisStation.h"

CAnalysisStation::CAnalysisStation(CCentralAbstractInterface* firstInterface, CCentralAbstractInterface* secondInterface)
:CAnalysis(firstInterface, secondInterface)
{

}
//---------------------------------------------------------------------------------------

CGroup* CAnalysisStation::newGroup(string name, int number)
{
  return new CStation(name, number);
}
//---------------------------------------------------------------------------------------