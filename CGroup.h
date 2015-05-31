// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CGroup
// 
// Beschreibung:    Abstrakte Basisklasse für gespeicherte Daten einer 
//                  Gruppe für die Ausertung. Abgeleitete Klassen CRunner
//                  und CStation.
//                  
//************************************************************************

#ifndef CGROUP_H
#define CGROUP_H

#include <iostream>
#include <fstream>

#include "CGroupInterface.h"
 
 using namespace std;
 
class CGroup
{
 
public:
  
// Konstruktoren:
    CGroup(string name, int number);
    
// Memberfunktionen:
    // Rückgabe der Gruppennummer
    int getNumber();
    
    string getName();
    
    // Setzen der Tabelleneinträge
    virtual void setTableEntries(CGroupInterface* interface, int row) = 0;
    // Setzen der Gruppenspezifischen Einträge
    virtual void setGroupEntries(CGroupInterface* interface) = 0;
    // Starten der Auswertung
    virtual void evaluate() = 0;
    
    // Membervariablen:
    int pointSum_;

  private:

//Membervariablen:
    // Gruppenname
    string name_;
    // Gruppennummer;
    int number_;

//Memberfunktionen:
    
protected:
    // Disqualifiziert
    bool disqualified_;
 
};
 
#endif // CGROUP_H