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
#include <QCheckBox>

#include "CGroupInterface.h"
 
class CRunnerInterface : public CGroupInterface
{
 
  public:
    CRunnerInterface(QStringList parameter, QString text, int number);
    
// Memberfunktionen:
    // Gibt den Status der Disqualifizierung zurück
    bool isdisqualified();
    // Gibt die Anzahl der Läufer am Start zurück
    int runnerAtStart();
    // Anzahl der Taxischeine im Ziel
    int taxiTicket();
    // Gibt die benötigte Zeit zurück
    unsigned int usedTime();
 
  private:
// Widgets:
    // Disqualifiziert?
    QCheckBox* disqualified_;
    // Läufer am Start
    QLineEdit* runnerAtStart_;
    // Taxischeine im Ziel
    QLineEdit* taxiTicket_;
    // Startzeit
    QDateTimeEdit* startTime_;
    // Zielzeit
    QDateTimeEdit* destinationTime_;
    
  protected:
    
  public slots:
    
  signals:

    
};
 
#endif // CRunnerInterface_H