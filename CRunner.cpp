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
  joker_.push_back(station->getJokerAt(row));
  
  // Anzahl der Läufer bei Station
  nRunner_.push_back(station->getNumberRunnerAt(row));
}
//---------------------------------------------------------------------------------------

void CRunner::setGroupEntries(CGroupInterface* interface)
{
  // Cast zu einem RunnerInterface
  CRunnerInterface* runner = dynamic_cast<CRunnerInterface*>(interface);
  
  // Disqualifiziert
  disqualified_ = runner->isdisqualified();
  
  // Läufer beim Start
  runnerAtStart_ = runner->runnerAtStart();
  
  // Benötigte Zeit
  time_ = runner->usedTime();
  
  // Benutzte Taxischeine
  taxiTicket_ = runner->taxiTicket();
  
  // unbemannte Stationen
  uncrewedStations_ = runner->uncrewedStations();
}
//---------------------------------------------------------------------------------------

void CRunner::evaluate()
{
  int point1;
  int point2;
  bool joker_reminder = false;
  
  // Durch alle erreichten Stationen
  for (int i = 0; i < points_.size(); i++)
  {
    // Punkte für das Erreichen
    point1 = 30 - ((runnerAtStart_ - nRunner_.at(i)) * 10);
    
    // Es gibt kein Punktabzug
    if (point1 < 0)
    {
      point1 = 0;
    }
    
    // Wenn ein Joker benutzt wurde
    if (joker_.at(i))
    {
      if(joker_reminder == false)
      {
        // Erster Joker
        point2 = 40;
        
        joker_reminder = true;
      }
      else
      {
        // Zweiter Joker
        point2 = 20;
      }
    }
    
    // Wenn der Joker nicht benutzt wurde
    else
    {
      point2 = points_.at(i) + teamwork_.at(i);
    }
    
    // Addieren
    pointSum_ += (point1 + point2);
  }
  
  // Abzüge für fehlende Taxischeine
  pointSum_ -= (((runnerAtStart_ - 3) - taxiTicket_) * 40); 
  
  // TODO: unbemannte Posten aufnehmen
  for(int i = 0; i < uncrewedStations_.size(); i++)
  {
    if(uncrewedStations_.at(i))
    {
      pointSum_ += 30;
    }
  }

}

