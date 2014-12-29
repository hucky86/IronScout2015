
#include "CMainWindow.h"

CMainWindow::CMainWindow()
{ 
  menu_ = createMenuBar();
  centralWidget_ = new QWidget;
  centralLayout_ = new QStackedLayout;
  centralStation_ = new CCentralStationInterface;
  centralRunner_ = new CCentralRunnerInterface;
  
  setMenuBar(menu_);
  centralLayout_->addWidget(centralStation_);
  centralLayout_->addWidget(centralRunner_);
  
  centralWidget_->setLayout(centralLayout_);
  setCentralWidget(centralWidget_);
  setWindowTitle("IronScout 2015 Selm");
}
//---------------------------------------------------------------------------------------

CMainWindow::~CMainWindow()
{

}
//---------------------------------------------------------------------------------------

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
//---------------------------------------------------------------------------------------

void CMainWindow::closeWindow()
{
  //Speichern der Daten aufrufen
  emit saveFile();
  // Schließen des Hauptfensters
  emit close();
}
//---------------------------------------------------------------------------------------

void CMainWindow::saveFile()
{
  QString path = QFileDialog::getSaveFileName();
  
  ofstream file;
  file.open(path.toStdString().c_str());
  
  QString test ("bla12");
  int foo = test.toInt();
  
  file.close();
}
//---------------------------------------------------------------------------------------

void CMainWindow::loadFile()
{
  QString path = QFileDialog::getOpenFileName();
  
  //TODO: Algorithmus zum Laden einfügen
  qDebug() << path;
}
//---------------------------------------------------------------------------------------

void CMainWindow::changeToStation()
{
  if(centralLayout_->currentWidget() != centralStation_)
  {
    centralLayout_->setCurrentWidget(centralStation_);
  }
}
//---------------------------------------------------------------------------------------

void CMainWindow::changeToRunner()
{
  if(centralLayout_->currentWidget() != centralRunner_)
  {
    centralLayout_->setCurrentWidget(centralRunner_);
  }
}
//---------------------------------------------------------------------------------------


