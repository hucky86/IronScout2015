// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CMainWindow
// 
// Beschreibung:    Interface zur Verwaltung des Programms. Verwaltung
//                  der Menüleiste sowie des CCentralAbstractInterface.
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

#include "CCentralStationInterface.h"
#include "CCentralRunnerInterface.h"
#include "CAnalysisRunner.h"
#include "CAnalysis.h"

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
  CCentralAbstractInterface* centralStation_;
  // Läuferauswertung
  CCentralAbstractInterface* centralRunner_;
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
  void analyseRunner();
  void analyseStation();
  
  
signals:
  
};

#endif // CMAINWINDOW_H