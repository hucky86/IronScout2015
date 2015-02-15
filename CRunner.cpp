#include "CRunner.h"

CRunner::CRunner(string name, int number) : CGroup(name, number)
{
  
}
//---------------------------------------------------------------------------------------

void CRunner::setTableEntries(CGroupInterface* interface, int row)
{
  // Cast zu einem StationInterface
  CStationInterface* station = dynamic_cast<CStationInterface*>(interface);
  
  // Spielpunkte
  points_.push_back(station->getPointsAt(row));
  
  // Teamwork
  teamwork_.push_back(station->getTeamworkAt(row));
  
  // Joker
  teamwork_.push_back(station->getJokerAt(row));
  
  // Anzahl der Läufer bei Station
  nRunner_.push_back(station->getNumberRunnerAt(row));
}
//---------------------------------------------------------------------------------------

void CRunner::setGroupEntries(CGroupInterface* interface)
{

}

