// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CCentralStationInterface
// 
// Beschreibung:    Zentrales Widget zur Verwaltung der Ein- und Ausgaben.
//                  Schnittstelle für Stationen.
// 
//************************************************************************


#ifndef CCENTRALSTATIONINTERFACE_H
#define CCENTRALSTATIONINTERFACE_H

#include <QString>

#include "CCentralAbstractInterface.h"

class CCentralStationInterface : public CCentralAbstractInterface
{
  Q_OBJECT
 
  public:
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralStationInterface();
 
  private:
  
// Widgets:

// Layouts:
    
//Membervariablen:
    
//Memberfunktionen:
    void buildInputValidators();
    virtual CGroupInterface* newGroup(QString name, int number);
    // Ordnet dem Interface die Gruppenlisten zu
    virtual void assignLists(std::map<int,QString> runner,std::map<int,QString> station);
    // Prüfen, ob bereits mehr als 2 Joker benutzt wurden
    void checkForOtherJokers(int number);

private slots:
    // Wenn Joker auf "ja" gesetzt wird
    void setJoker(QString text);
    
signals:

};

#endif // CCENTRALSTATIONINTERFACE_H