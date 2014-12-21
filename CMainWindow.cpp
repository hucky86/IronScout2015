
#include "CMainWindow.h"

CMainWindow::CMainWindow()
{ 
  menu_ = createMenuBar();
  central_ = new CCentralWidget("Station");
  
  setMenuBar(menu_);
  setCentralWidget(central_);
  setWindowTitle("IronScout 2015 Selm");
}

CMainWindow::~CMainWindow()
{

}

QMenuBar* CMainWindow::createMenuBar()
{
  // Anlegen der Menüleiste
  QMenuBar* mbar = new QMenuBar();
  
  // Hinzufügen des Eintrages "Datei"
  QMenu* fileMenu = new QMenu("Datei");
  
  fileMenu->addAction("Datei laden", this, SLOT(loadFile()));
  fileMenu->addAction("Datei speichern", this, SLOT(saveFile()));
  fileMenu->addAction("Programm beenden", this, SLOT(closeWindow()));
  
  // Hinzufügen des Eintrages "Auswertungsmodus"
  QMenu* modus = new QMenu("Auswertungsmodus");
  
  modus->addAction("Stationsbögen auswerten", this, SLOT(changeToStation()));
  modus->addAction("Läuferbögen auswerten", this, SLOT(changeToRunner()));
  
  mbar->addMenu(fileMenu);
  mbar->addMenu(modus);
  
  return mbar;
}

void CMainWindow::closeWindow()
{
  //Speichern der Daten aufrufen
  emit saveFile();
  // Schließen des Hauptfensters
  emit close();
}

void CMainWindow::saveFile()
{
  QString path = QFileDialog::getSaveFileName();
  
  //TODO: Algorithmus zum Speichern einfügen
  qDebug() << path;
}

void CMainWindow::loadFile()
{
  QString path = QFileDialog::getOpenFileName();
  
  //TODO: Algorithmus zum Laden einfügen
  qDebug() << path;
}

void CMainWindow::changeToStation()
{
  //TODO
}

void CMainWindow::changeToRunner()
{
  //TODO
}



