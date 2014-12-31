#include "CCentralStationInterface.h"

CCentralStationInterface::CCentralStationInterface () : CCentralAbstractInterface()
{
  // Festlegung der benötigten Parameter
  parameter_ = QStringList() << QString(QStringLiteral("Läufernr.")) << QString(QStringLiteral("Läufername")) << QString(QStringLiteral("Läuferanzahl")) 
  << "Joker [ja]" << "Punkte 'Spiel'" << "Punkte 'Teamwork'" << "Punkte Gesamt";

  buildInputLayout();
  buildInputValidators();
}
//---------------------------------------------------------------------------------------

void CCentralStationInterface::buildInputValidators()
{
  inputList_.at(0)->setValidator(new QIntValidator(0, 200, inputList_.at(0)));
  inputList_.at(2)->setValidator(new QIntValidator(3, 10, inputList_.at(2)));
  inputList_.at(3)->setValidator(new QRegExpValidator(QRegExp(QString("ja"), Qt::CaseSensitive, QRegExp::FixedString)));
  inputList_.at(4)->setValidator(new QIntValidator(0, 50, inputList_.at(2)));
  inputList_.at(5)->setValidator(new QIntValidator(0, 20, inputList_.at(5)));
  inputList_.at(6)->setValidator(new QIntValidator(0, 100, inputList_.at(6)));

  inputList_.at(6)->setDisabled(true);

  connect(inputList_.at(3), SIGNAL(textChanged(QString)), this, SLOT(setJoker(QString)));
}

//---------------------------------------------------------------------------------------

CGroupInterface* CCentralStationInterface::newGroup(QString name, int number)
{
  CGroupInterface* newGroup = new CStationInterface(parameter_, name, number);

  return newGroup;
}