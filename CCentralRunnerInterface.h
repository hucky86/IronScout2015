// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CCentralRunnerInterface
// 
// Beschreibung:    Zentrales Widget zur Verwaltung der Ein- und Ausgaben.
//                  Schnittstelle für Läufer.
// 
//************************************************************************

#ifndef CCENTRALRUNNERINTERFACE_H
#define CCENTRALRUNNERINTERFACE_H

#include <QString>

#include "CCentralAbstractInterface.h"

class CCentralRunnerInterface : public CCentralAbstractInterface
{
  Q_OBJECT
 
  public:
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralRunnerInterface();

  private:

// Layouts:
    
//Membervariablen:
    
//Memberfunktionen:
    void buildInputValidators();
    virtual CGroupInterface* newGroup(QString name, int number);
    // Ordnet dem Interface die Gruppenlisten zu
    virtual void assignLists(std::map<int,QString> runner,std::map<int,QString> station);

private slots:
    
signals:

};

#endif // CCENTRALRUNNERINTERFACE_H
