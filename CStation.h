// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CStation
// 
// Beschreibung:    Speichert Daten zur Auswertung einer Stationsgruppe.
//                  Abgeleitet von CGroup.
//                  
//************************************************************************

#ifndef CSTATION_H
#define CSTATION_H

#include "CGroup.h"
#include "CRunnerInterface.h"

using namespace std;
 
class CStation : public CGroup
{
 
public:
  
// Konstruktoren:
    CStation(string name, int number);
// Memberfunktionen:
    void setTableEntries(CGroupInterface* interface, int row);
    void setGroupEntries(CGroupInterface* interface);
    void evaluate();

private:
//Membervariablen:
  int peopleAtStation_;
  // Punkte Spielidee
  vector<int> gameIdea_;
  // Punkte Spielausführung
  vector<int> gameDesign_;
  // Punkte Atmosphäre
  vector<int> atmophere_;

//Memberfunktionen:
    
protected:
 
};
 
#endif // CSTATION_H