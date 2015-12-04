#include "UniformRandomGenerator.h"
#include <qmessagebox.h>

double UniformRandomGenerator::_lastGenerated = -1;

UniformRandomGenerator::UniformRandomGenerator(void)
{
    _multiplyConst = -1;
}


UniformRandomGenerator::~UniformRandomGenerator(void)
{
}

void UniformRandomGenerator::setStartConditions(double multiplyConst, double startValue)
{
    if (startValue < 0 || startValue > 1)
    {
        QMessageBox msgBox;
        msgBox.setText("Value Si should be in a range [0; 1]!\n");
        msgBox.exec();
        return;
    }

    if (_multiplyConst != multiplyConst)
    {
        _multiplyConst = multiplyConst;
    }

    if (_lastGenerated == -1)
    {
        _lastGenerated = startValue;
    }
}

double UniformRandomGenerator::generateRandomNumber()
{
    if (_multiplyConst == -1 || _lastGenerated == -1)
        return 0;
                
    double newRand = _multiplyConst * _lastGenerated;
    
    //Выделение дробной части
    int i = (int)newRand;
    double fract = newRand - i;
    
    _lastGenerated = fract;
    
    return fract;
}