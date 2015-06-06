// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CRunnerInterface
// 
// Beschreibung:    Verwaltung des Interfaces der Ein- und Ausgabe für 
//                  Läufergruppen.
//                  
//************************************************************************

#ifndef CRunnerInterface_H
#define CRunnerInterface_H

#include <QDateTimeEdit>

#include "CGroupInterface.h"
 
class CRunnerInterface : public CGroupInterface
{
 
  public:
    CRunnerInterface(QStringList parameter, QString text, int number);
    
// Memberfunktionen:
    // Gibt die Anzahl der Läufer am Start zurück
    int runnerAtStart();
    // Anzahl der Taxischeine im Ziel
    int taxiTicket();
    // Gibt die benötigte Zeit zurück
    unsigned int usedTime();
    // Gibt die unbemannten Stationen zurück
    std::vector<bool> uncrewedStations();
    // Baut die Eingabe für Gruppenspezifische Angaben
    void buildProperties();
    // Baut die Eingabe der unbemannten Posten
    void buildUncrewedStation();
    // Speichert Gruppenspezifische Daten
    virtual void saveProperties(std::ofstream& saveFile);
    // Laden Gruppenspezifischer Daten
    virtual void loadProperties(std::stringstream& stream);
 
  private:
// Widgets:
    // Läufer am Start
    QLineEdit* runnerAtStart_;
    // Taxischeine im Ziel
    QLineEdit* taxiTicket_;
    // Startzeit
    QDateTimeEdit* startTime_;
    // Zielzeit
    QDateTimeEdit* destinationTime_;
    // Pointer auf die unbemannten Posten
    std::vector<QCheckBox*> uncrewedStation_;
    
  protected:
    
  public slots:
    
  signals:

    
};
 
#endif // CRunnerInterface_H