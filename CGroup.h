// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CGroup
// 
// Beschreibung:    Abstrakte Basisklasse des Interfaces der Ein- und 
//                  Ausgabe für Gruppen. Abgeleitete Klassen CRunner und
//                  CStation. 
//                  
//************************************************************************

#ifndef CGROUP_H
#define CGROUP_H

#include <QLabel>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QLineEdit>
#include <QFlag>
#include <QAbstractItemView>
 
class CGroup : public QWidget
{
  Q_OBJECT
 
public:
  
// Konstruktoren:
    CGroup(QStringList parameter, QString name, int number);
    
// Memberfunktionen:
    // get Funktionen
    QTableWidget* getTable();
    // Hinzufügen eines Tabelleneintrages
    void addTableEntry (const QList<QLineEdit*> list);
    // Löschen des aktuellen Tabelleneintrages
    void deleteTableEntry ();
    // Prüft ob eine Gruppe bereits vorhanden ist
    bool checkGroupExist(int number);
    // Gibt die Zeile mit zu einer Gruppennummer zurück
    int getRow (int number);
    // Markiert die gesamte Zeile rot
    void setRedRow(int row);
    // Setzt die gesamte Tabelle weiß
    void setWhiteTable();
    // Aufrufen der Eingabeaufforderung der Gruppenspezifischen Eingaben
    virtual void openProperties() = 0;

  private:

//Membervariablen:
    // Gruppenname
    QLabel* description_;
    // Gruppennummer
    int number_;
    // Liste mit den Eingabeparametern
    QStringList parameter_;
    
//Memberfunktionen:
    // Gekapselte Funktion zum Aufbau des QTableWidget
    void buildTable ();

// Layouts:
    // Layout für Name und Tabelle
    QVBoxLayout* vLayout_;
    
protected:
  
//Widgets:
    // Table Widget zur Speicherung aller Eingaben
    QTableWidget* table_;
    // Widget zu Eingabe der Gruppenspezifischen Parameter
    QWidget* properties_;
    // OK Bestätigung der properties
    QPushButton* ok_;
    
// Layouts:
    // Grid Layout für die properties
    QGridLayout* gLayout_;
    
public slots:
    // Properties Fenster wieder schließen
    void closeProperties ();
  
signals:
    
};
 
#endif // CGROUP_H