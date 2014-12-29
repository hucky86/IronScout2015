#include "CCentralRunnerInterface.h"

CCentralRunnerInterface::CCentralRunnerInterface () : CCentralAbstractInterface()
{
  // Festlegung der ben�tigten Parameter
  parameter_ = QStringList() << "Stationsnr." << "Stationsname" << "Punkte 'Spielidee'" 
  << QString(QStringLiteral("Punkte 'Spielausf�hrung'")) << QString(QStringLiteral("Punkte 'Atmosph�re'")) << "Punkte Gesamt";

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
//---------------------------------------------------------------------------------------

CGroup* CCentralRunnerInterface::newGroup(QString name, int number)
{
  CGroup* newGroup = new CRunner(parameter_, name, number);

  return newGroup;
}