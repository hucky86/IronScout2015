// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CAnalysis
// 
// Beschreibung:    Stellt Schnittstelle für Auswerteroutinen zur
//                  Verfügung.
// 
//************************************************************************

#ifndef CANALYSIS_H
#define CANALYSIS_H

#include <iostream>
#include <fstream>

#include "CGroup.h"
#include "CCentralAbstractInterface.h"
#include "CGroupInterface.h"

 using namespace std;
 
class CAnalysis
{
 
public:
  
// Konstruktoren:
  CAnalysis(CCentralAbstractInterface* interface);
    
// Memberfunktionen:
    // Alle Gruppen löschen
    void deleteGroups();
    // Alle Gruppen zusammen bauen
    void buildGroups();
    // Holt alle Daten aus dem Interface für die Auswertung
    virtual void getData() = 0;

  private:

//Membervariablen:

//Memberfunktionen:
    // Neue Gruppe anlegen
    virtual CGroup* newGroup (string name, int number) = 0;
    
protected:
// Membervariablen
    // Map zum Speichern der Gruppen
    map<int, CGroup*> groupList_;
    
    // Enthält alle Informationen aus der Eingabe
    CCentralAbstractInterface* interface_;
 
};

#endif // CANALYSIS_H