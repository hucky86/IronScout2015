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

  private:

//Membervariablen:
    map<int, CGroup> groupList_;

//Memberfunktionen:
    
protected:
 
};

#endif // CANALYSIS_H