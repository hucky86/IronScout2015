// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CRunner
// 
// Beschreibung:    Speichert Daten zur Auswertung einer Läufergruppe.
//                  Abgeleitet von CGroup.
//                  
//************************************************************************

#ifndef CRUNNER_H
#define CRUNNER_H

#include <iostream>
#include <fstream>
#include <list>

#include "CGroup.h"
#include "CStationInterface.h"
#include "CRunnerInterface.h"
 
using namespace std;
 
class CRunner : public CGroup
{
 
public:
  
// Konstruktoren:
    CRunner(string name, int number);
// Memberfunktionen:
    void setTableEntries(CGroupInterface* interface, int row);
    void setGroupEntries(CGroupInterface* interface);
    void evaluate();

private:
//Membervariablen:
  // Benötigte Zeit
  int time_;
  // Läufer am Start
  int runnerAtStart_;
  // Taxischeine im Ziel
  int taxiTicket_;
  // Punkte "Spiel"
  vector<int> points_;
  // Punkte "Teamwork"
  vector<int> teamwork_;
  // "Joker" ja oder nein
  vector<bool> joker_;
  // Punkte "alle Läufer anwesend"
  vector<int> nRunner_;
  // Unbemannte Stationen
  vector<Qt::CheckState> uncrewedStations_;

//Memberfunktionen:
    
protected:
 
};
 
#endif // CRUNNER_H