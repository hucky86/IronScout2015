#include "CCentralRunnerInterface.h"

CCentralRunnerInterface::CCentralRunnerInterface (QString analysis) : CCentralAbstractInterface(analysis)
{
  // Festlegung der benötigten Parameter
  parameter_ = QStringList() << "Stationsnr." << "Stationsname" << "Punkte 'Spielidee'" 
  << "Punkte 'Spielausführung'" << "Punkte 'Atmosphäre'" << "Punkte Gesamt";

  buildInputLayout();
  buildInputValidators();
}
//---------------------------------------------------------------------------------------

void CCentralRunnerInterface::buildInputValidators()
{
  inputList_.at(0)->setValidator(new QIntValidator(0, 200, inputList_.at(0)));
  inputList_.at(2)->setValidator(new QIntValidator(0, 40, inputList_.at(2)));
  inputList_.at(3)->setValidator(new QIntValidator(0, 30, inputList_.at(3)));
  inputList_.at(4)->setValidator(new QIntValidator(0, 30, inputList_.at(4)));
  inputList_.at(5)->setValidator(new QIntValidator(0, 100, inputList_.at(5)));

  inputList_.at(5)->setDisabled(true);
}