#include "CCentralStationInterface.h"

CCentralStationInterface::CCentralStationInterface () : CCentralAbstractInterface()
{
  // Festlegung der benötigten Parameter
  parameter_ = QStringList() << "Laeufernr." << "Laeufername" << "Laeuferanzahl"
  << "Joker [ja]" << "Punkte 'Spiel'" << "Punkte 'Teamwork'";

  buildInputLayout();
  buildInputValidators();
  buildNameLists();
  buildGroupLists();
}
//---------------------------------------------------------------------------------------

void CCentralStationInterface::buildInputValidators()
{
  inputList_.at(0)->setValidator(new QIntValidator(0, 200, inputList_.at(0)));
  inputList_.at(2)->setValidator(new QIntValidator(3, 10, inputList_.at(2)));
  inputList_.at(3)->setValidator(new QRegExpValidator(QRegExp(QString("ja"), Qt::CaseSensitive, QRegExp::FixedString)));
  inputList_.at(4)->setValidator(new QIntValidator(0, 50, inputList_.at(2)));
  inputList_.at(5)->setValidator(new QIntValidator(0, 20, inputList_.at(5)));

  connect(inputList_.at(3), SIGNAL(textChanged(QString)), this, SLOT(setJoker(QString)));
}

//---------------------------------------------------------------------------------------

CGroupInterface* CCentralStationInterface::newGroup(QString name, int number)
{
  CGroupInterface* newGroup = new CStationInterface(parameter_, name, number);

  return newGroup;
}
//---------------------------------------------------------------------------------------

void CCentralStationInterface::setJoker(QString text)
{
  if(text == "ja")
  {
    inputList_.at(4)->setDisabled(true);
    inputList_.at(4)->setText(QString(""));
    inputList_.at(5)->setDisabled(true);
    inputList_.at(5)->setText(QString(""));
  }

  else
  {
    inputList_.at(4)->setDisabled(false);
    inputList_.at(5)->setDisabled(false);
  }
}
//---------------------------------------------------------------------------------------

void CCentralStationInterface::assignLists(std::map< int, QString > runner, std::map< int, QString > station)
{
  firstNameList_ = station;
  secondNameList_ = runner;
}


