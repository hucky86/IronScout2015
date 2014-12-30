// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CRunner
// 
// Beschreibung:    Verwaltung des Interfaces der Ein- und Ausgabe für 
//                  Läufergruppen.
//                  
//************************************************************************

#ifndef CRUNNER_H
#define CRUNNER_H

#include <QDateTimeEdit>
#include <QCheckBox>

#include "CGroup.h"
 
class CRunner : public CGroup
{
 
  public:
    CRunner(QStringList parameter, QString text, int number);
    
    // Aufrufen der Eingabeaufforderung der Gruppenspezifischen Eingaben
    virtual void openProperties();

 
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
 
#endif // CRUNNER_H