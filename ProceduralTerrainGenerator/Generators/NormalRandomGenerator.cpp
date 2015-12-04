#include "NormalRandomGenerator.h"


NormalRandomGenerator::NormalRandomGenerator(void)
{
}


NormalRandomGenerator::~NormalRandomGenerator(void)
{
}

void NormalRandomGenerator::setStartConditions(double multiplyConst, double startValue)
{
    _uniformRndGen.setStartConditions(multiplyConst, startValue);
}

double NormalRandomGenerator::generateRandomNumber()
{
    double uniformSum = 0;

    for (int i = 0; i < 12; i++)
    {
        uniformSum += _uniformRndGen.generateRandomNumber();
    }

    double result = uniformSum - 6;

    return result;
}

void NormalRandomGenerator::setUniformRandomGenerator(UniformRandomGenerator uniformRnd)
{
    _uniformRndGen = uniformRnd;
}

UniformRandomGenerator NormalRandomGenerator::getUniformRandomGenerator()
{
    return _uniformRndGen;
}