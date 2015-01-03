#include "CCentralRunnerInterface.h"

CCentralRunnerInterface::CCentralRunnerInterface () : CCentralAbstractInterface()
{
  // Festlegung der benötigten Parameter
  parameter_ = QStringList() << "Stationsnr." << "Stationsname" << "Punkte 'Spielidee'" 
  << QString(QStringLiteral("Punkte 'Spielausführung'")) << QString(QStringLiteral("Punkte 'Atmosphäre'"));

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
}
//---------------------------------------------------------------------------------------

CGroupInterface* CCentralRunnerInterface::newGroup(QString name, int number)
{
  CGroupInterface* newGroup = new CRunnerInterface(parameter_, name, number);

  return newGroup;
}