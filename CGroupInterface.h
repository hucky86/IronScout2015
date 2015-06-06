// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CGroupInterface
// 
// Beschreibung:    Abstrakte Basisklasse des Interfaces der Ein- und 
//                  Ausgabe für Gruppen. Abgeleitete Klassen CRunnerInterface und
//                  CStationInterface. 
//                  
//************************************************************************

#ifndef CGroupInterface_H
#define CGroupInterface_H

#include <QLabel>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QLineEdit>
#include <QFlag>
#include <QAbstractItemView>
#include <fstream>
#include <QCheckBox>
 
class CGroupInterface : public QWidget
{
  Q_OBJECT
 
public:
  
// Konstruktoren:
    CGroupInterface(QStringList parameter, QString name, int number);
    
// Memberfunktionen:
    // get Funktionen
    QTableWidget* getTable();
    // Hinzufügen eines Tabelleneintrages
    void addTableEntry (const QList<QLineEdit*> list);
    // Löschen des aktuellen Tabelleneintrages
    void deleteTableEntry ();
    // Prüft ob eine Gruppe bereits vorhanden ist
    bool checkEntryExist(int number);
    // Gibt die Zeile zu einer Gruppennummer zurück
    int getRow (int number);
    // Markiert die gesamte Zeile rot
    void setRedRow(int row);
    // Setzt die gesamte Tabelle weiß
    void setWhiteTable();
    // Aufrufen der Eingabeaufforderung der Gruppenspezifischen Eingaben
    virtual void openProperties();
    // Rückgabe der Gruppennummer
    int getNumber();
    // Gibt die Gruppennummer zu einer Zeile
    int getNumberAt(int row);
    // Gibt den Gruppennamen zu einer Zeile
    std::string getNameAt(int row);
    // Gibt die Gesamtanzahl der Tabelleneinträge zurück
    int getRowCount();
    // Gibt den Status der Disqualifizierung zurück
    bool isdisqualified();
    // Speichert relevante Daten für ein SaveFile
    void save(std::ofstream& saveFile);
    // Speichert Gruppenspezifische Daten
    virtual void saveProperties(std::ofstream& saveFile) = 0;
    // Laden Gruppenspezifischer Daten
    virtual void loadProperties(std::stringstream& stream) = 0;

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
    // Disqualifiziert?
    QCheckBox* disqualified_;
    
// Layouts:
    // Grid Layout für die properties
    QGridLayout* gLayout_;
    
public slots:
    // Properties Fenster wieder schließen
    void closeProperties ();
  
signals:
    
};
 
#endif // CGroupInterface_H