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
#include <map>
 
 using namespace std;
 
class CGroup
{
 
public:
  
// Konstruktoren:
    CGroup(string name, int number);
    
// Memberfunktionen:

  private:

//Membervariablen:
    // Gruppenname
    string name_;
    // Gruppennummer;
    int number_;

//Memberfunktionen:
    
protected:
 
};
 
#endif // CGROUP_H