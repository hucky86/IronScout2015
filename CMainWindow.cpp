
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
  
  // Hinzufügen des Eintrages "Eingabemodus"
  QMenu* modus = new QMenu("Eingabemodus");
  
  modus->addAction("Stationsbögen eingeben", this, SLOT(changeToStation()));
  modus->addAction("Läuferbögen eingeben", this, SLOT(changeToRunner()));

  // Hinzufügen des Eintrages "Auswertung"
  QMenu* analysis = new QMenu("Auswertung");

  analysis->addAction("Stationen auswerten", this, SLOT(analyseStation()));
  analysis->addAction("Läufer auswerten", this, SLOT(analyseRunner()));
  
  //Hizufügen des Eintrages "Vergleiche"
  QMenu* compare = new QMenu("Vergleichen");
  
  compare->addAction("Datenbanken vergleichen", this, SLOT(compareDatabase()));
  
  mbar->addMenu(fileMenu);
  mbar->addMenu(modus);
  mbar->addMenu(analysis);
  mbar->addMenu(compare);
  
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
  
  ofstream saveFile;
  saveFile.open(path.toStdString().c_str());
  
  centralStation_->save(saveFile);
  centralRunner_->save(saveFile);
  
  saveFile.close();
}
//---------------------------------------------------------------------------------------

void CMainWindow::loadFile()
{
  QString path = QFileDialog::getOpenFileName();
  
  std::ifstream loadFile(path.toStdString().c_str(), std::ifstream::binary);
  std::stringstream stream; 
  stream << loadFile.rdbuf();
  
  centralStation_->load(stream);
  centralRunner_->load(stream);
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

void CMainWindow::analyseRunner()
{
  // Auswertung der Läufergruppen
  CAnalysisRunner runnerAnalyse(centralStation_, centralRunner_);
  
  // Zunächst Map löschen
  runnerAnalyse.deleteGroups();
  
  // Gruppenstruktur aufbauen
  runnerAnalyse.buildGroups();
  
  // Daten holen
  runnerAnalyse.getData();
  
  // Auswerten
  runnerAnalyse.evaluate();
  
  // Schreiben der Ergebnisse
  runnerAnalyse.writeResult();
}
//---------------------------------------------------------------------------------------

void CMainWindow::analyseStation()
{
  // Auswertung der Läufergruppen
  CAnalysisStation stationAnalyse(centralRunner_, centralStation_);
  
  // Zunächst Map löschen
  stationAnalyse.deleteGroups();
  
  // Gruppenstruktur aufbauen
  stationAnalyse.buildGroups();
  
  // Daten holen
  stationAnalyse.getData();
  
  // Auswerten
  stationAnalyse.evaluate();
  
  // Schreiben der Ergebnisse
  stationAnalyse.writeResult();
}
//---------------------------------------------------------------------------------------

void CMainWindow::compareDatabase()
{
  QString path = QFileDialog::getOpenFileName();
  
  std::ifstream loadFile(path.toStdString().c_str(), std::ifstream::binary);
  std::stringstream stream; 
  stream << loadFile.rdbuf();
  
  CCentralStationInterface* centralStation = new CCentralStationInterface;
  CCentralRunnerInterface* centralRunner = new CCentralRunnerInterface; 
  
  centralStation->load(stream);
  centralRunner->load(stream);
  
  centralStation_->compare(centralStation);
  centralRunner_->compare(centralRunner);
  
  delete centralStation;
  delete centralRunner;
}
