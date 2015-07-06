#include "CStation.h"
#include "CRunner.h"

CStation::CStation(string name, int number) : CGroup(name, number)
{
  
}
//---------------------------------------------------------------------------------------

void CStation::setTableEntries(CGroupInterface* interface, int row)
{
  // Cast zu einem StationInterface
  CRunnerInterface* runner = dynamic_cast<CRunnerInterface*>(interface);
  
  // Spielpunkte
  gameIdea_.push_back(runner->getGameIdeaAt(row));
  
  // Teamwork
  gameDesign_.push_back(runner->getGameDesignAt(row));
  
  // Joker
  atmophere_.push_back(runner->getAtmosphereAt(row));
}
//---------------------------------------------------------------------------------------

void CStation::setGroupEntries(CGroupInterface* interface)
{
  // Cast zu einem RunnerInterface
  CStationInterface* station = dynamic_cast<CStationInterface*>(interface);
  
  // Disqualifiziert
  disqualified_ = station->isdisqualified();
  
  // Läufer beim Start
  peopleAtStation_ = station->getNumberPeople();
}
//---------------------------------------------------------------------------------------

void CStation::evaluate()
{

}