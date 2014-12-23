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
 
class CGroup : public QWidget
{
  Q_OBJECT
 
public:
  
// Konstruktoren:
    CGroup(QStringList parameter, QString name);

// Widgets:
    // Table Widget zur Speicherung aller Eingaben
    QTableWidget* table_;
    
// Memberfunktionen:
    // get Funktionen
    QTableWidget* getTable();
    QLabel* getName();
    // Hinzufügen eines Tabelleneintrages
    void addTableEntry (const QList<QLineEdit*> list);

  private:

//Membervariablen:
    // Gruppenname
    QLabel* name_;
    // Liste mit den Eingabeparametern
    QStringList parameter_;
    
//Memberfunktionen:
    // Gekapselte Funktion zum Aufbau des QTableWidget
    void buildTable ();

// Layouts:
    // Layout für Name und Tabelle
    QVBoxLayout* vLayout_;
    
protected:
    
private slots:
  
signals:
    
};
 
#endif // CGROUP_H