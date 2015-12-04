#include "JohnsonSVRandomGenerator.h"
#include <cmath>
#include <qmessagebox.h>

JohnsonSVRandomGenerator::JohnsonSVRandomGenerator(void)
{
    _epsilon = 0;
    _eta = 0;
    _lambda = 0;
    _gamma = 0;
}


JohnsonSVRandomGenerator::~JohnsonSVRandomGenerator(void)
{
}

void JohnsonSVRandomGenerator::setStartConditions(double lambda, double eta, double epsilon, double gamma, double multiplyConst, double startValue)
{
    QMessageBox msgBox;

    if (lambda < 0)
    {
        msgBox.setText("'Lambda' must be greater than zero!\n");
        msgBox.exec();
        return;
    }
    if (eta < 0)
    {
        msgBox.setText("'Eta' must be greater than zero!\n");
        msgBox.exec();
        return;
    }

    if (_lambda != lambda)
    {
        _lambda = lambda;
    }

    if (_eta != eta)
    {
        _eta = eta;
    }

    if (_epsilon != epsilon)
    {
        _epsilon = epsilon;
    }

    if (_gamma != gamma)
    {
        _gamma = gamma;
    }

    _normRnd.setStartConditions(multiplyConst, startValue);
}

double JohnsonSVRandomGenerator::generateRandomNumber()
{
    double normRndNum = _normRnd.generateRandomNumber();

    double result = (_epsilon + (_epsilon + _lambda) * exp((normRndNum - _gamma) / _eta)) / (1 + exp((normRndNum - _gamma) / _eta));

    return result;
}

void JohnsonSVRandomGenerator::setNormalRandomGenerator(NormalRandomGenerator normRnd)
{
    _normRnd = normRnd;
}

NormalRandomGenerator JohnsonSVRandomGenerator::getNormalRandomGenerator()
{
    return _normRnd;
}
