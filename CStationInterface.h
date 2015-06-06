// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CStationInterface
// 
// Beschreibung:    Verwaltung des Interfaces der Ein- und Ausgabe für 
//                  Stationsgruppen.
//                  
//************************************************************************

#ifndef CStationInterface_H
#define CStationInterface_H

#include <QLineEdit>
#include <fstream>
#include <string>
#include <sstream>

#include "CGroupInterface.h"
 
class CStationInterface : public CGroupInterface
{
 
  public:
    CStationInterface(QStringList parameter, QString text, int number);
    
    // Gibt die Anzahl der Läufer, die an der Station angekommen sind
    int getNumberRunnerAt(int row);
    // Gibt zurück, ob Joker benutzt wurde
    bool getJokerAt(int row);
    // Gibt Punkte zur Bewertung "Spiel" zurück
    int getPointsAt(int row);
    // Gibt Punkte zur Bewertung "Teamwork" zurück
    int getTeamworkAt(int row);
    // Gibt die Anzahl der Stationsmitglieder zurück
    int getNumberPeople();
    // Speichert Gruppenspezifische Daten
    virtual void saveProperties(std::ofstream& saveFile);
    // Laden Gruppenspezifischer Daten
    virtual void loadProperties(std::stringstream& stream);
    
  private:
//Widgets:
    // Anzahl der Personen an der Station
    QLineEdit* numberPeople_;

    
  public slots:
    
  signals:
    
};
 
#endif // CStationInterface_H