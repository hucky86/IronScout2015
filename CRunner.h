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
 
using namespace std;
 
class CRunner : public CGroup
{
 
public:
  
// Konstruktoren:
    CRunner(string name, int number);
// Memberfunktionen:
    void setTableEntries(CGroupInterface* interface, int row);

private:

//Membervariablen:
  // Punkte "Spiel"
  list<int> points_;
  // Punkte "Teamwork"
  list<int> teamwork_;
  // "Joker" ja oder nein
  list<bool> joker_;
  // Punkte "alle Läufer anwesend"
  list<int> nRunner_;

//Memberfunktionen:
    
protected:
 
};
 
#endif // CRUNNER_H