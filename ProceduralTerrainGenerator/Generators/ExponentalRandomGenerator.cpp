#include "ExponentalRandomGenerator.h"
#include <qmessagebox.h>
#include <math.h>

ExponentalRandomGenerator::ExponentalRandomGenerator(void)
{
    _lambda = 0;
    _mu = 0; 
}


ExponentalRandomGenerator::~ExponentalRandomGenerator(void)
{
}

void ExponentalRandomGenerator::setStartConditions(double lambda, double mu, double multiplyConst, double startValue)
{
    QMessageBox msgBox;

    if (lambda < 0)
    {
        msgBox.setText("'Lambda' must be greater than zero!\n");
        msgBox.exec();
        return;
    }
    if (mu < 0 || mu > 1)
    {
        msgBox.setText("Value 'mu' should be in a range [0, 1]!\n");
        msgBox.exec();
        return;
    }

    if (_lambda != lambda)
    {
        _lambda = lambda;
    }

    if (_mu != mu)
    {
        _mu = mu;
    }

    _uniformRndGen.setStartConditions(multiplyConst, startValue);
}

void ExponentalRandomGenerator::setUniformRandomGenerator(UniformRandomGenerator uniformRnd)
{
    _uniformRndGen = uniformRnd;
}

UniformRandomGenerator ExponentalRandomGenerator::getUniformRandomGenerator()
{
    return _uniformRndGen;
}

double ExponentalRandomGenerator::generateRandomNumber()
{
    double uniformRndNum = _uniformRndGen.generateRandomNumber();
    
    double result = -(1 / _lambda) * log(1 - uniformRndNum) + _mu;

    return result;
}