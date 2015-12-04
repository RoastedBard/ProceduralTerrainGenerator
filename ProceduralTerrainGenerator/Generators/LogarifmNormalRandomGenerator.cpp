#include "LogarifmNormalRandomGenerator.h"
#include <cmath>
#include <qmessagebox.h>

LogarifmNormalRandomGenerator::LogarifmNormalRandomGenerator(void)
{
    _sigma = 0;
    _mu = 0;
}


LogarifmNormalRandomGenerator::~LogarifmNormalRandomGenerator(void)
{
}

void LogarifmNormalRandomGenerator::setStartConditions(double sigma, double mu, double multiplyConst, double startValue)
{
    QMessageBox msgBox;

    if (sigma < 0 || sigma > 1)
    {
        msgBox.setText("Value 'sigma' should be in a range [0, 1]!\n");
        msgBox.exec();
        return;
    }
    if (mu < 0 || mu > 1)
    {
        msgBox.setText("Value 'mu' should be in a range [0, 1]!\n");
        msgBox.exec();
        return;
    }

    if (_sigma != sigma)
    {
        _sigma = sigma;
    }

    if (_mu != mu)
    {
        _mu = mu;
    }

    _normRnd.setStartConditions(multiplyConst, startValue);
}

void LogarifmNormalRandomGenerator::setNormalRandomGenerator(NormalRandomGenerator normRnd)
{
    _normRnd = normRnd;
}

NormalRandomGenerator LogarifmNormalRandomGenerator::getNormalRandomGenerator()
{
    return _normRnd;
}

double LogarifmNormalRandomGenerator::generateRandomNumber()
{
    double normRndNum = _normRnd.generateRandomNumber();
    
    double result = exp(_sigma * normRndNum + _mu);
    
    return result;
}
