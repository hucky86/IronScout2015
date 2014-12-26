// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CMainWindow
// 
// Beschreibung:    Interface zur Verwaltung des Programms. Verwaltung
//                  der Menüleiste sowie des CCentralWidget.
//                  
//************************************************************************

#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <qstring.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QTableWidget>
#include <QStackedLayout>
#include <QWidget>

#include <iostream>
#include <fstream>

#include "CCentralWidget.h"
using namespace std;

class CMainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  
// Konstruktoren:
  CMainWindow();
  ~CMainWindow();
  
private:
  
// Widgets:
  // Basis-Widget
  QWidget* centralWidget_;
  // Stationsauswertung
  CCentralWidget* centralStation_;
  // Läuferauswertung
  CCentralWidget* centralRunner_;
  QMenuBar* menu_;
  
//Layouts:
  // Hält Stations- und Läuferauswertung
  QStackedLayout* centralLayout_;

// Memberfunktionen:
  // Menüleiste erzeugen
  QMenuBar* createMenuBar ();

private slots:
  void closeWindow();
  void saveFile();
  void loadFile();
  void changeToStation();
  void changeToRunner();
  
  
signals:
  
};

#endif // CMAINWINDOW_H