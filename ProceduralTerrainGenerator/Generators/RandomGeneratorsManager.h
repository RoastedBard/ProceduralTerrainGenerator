#ifndef _RANDOMGENERATORSMANAGER_H_
#define _RANDOMGENERATORSMANAGER_H_

#include "UniformRandomGenerator.h"
#include "NormalRandomGenerator.h"
#include "ExponentalRandomGenerator.h"
#include "LogarifmNormalRandomGenerator.h"
#include "JohnsonSVRandomGenerator.h"
#include "JohnsonSURandomGenerator.h"

class RandomGeneratorsManager
{
public:
    RandomGeneratorsManager(void);
    ~RandomGeneratorsManager(void);

public:
    IRandomGenerator* getCurrent(int curr);

public:
    UniformRandomGenerator      uniformRndGen;
    NormalRandomGenerator        normalRndGen;
    ExponentalRandomGenerator       expRndGen;
    LogarifmNormalRandomGenerator   logRndGen;
    JohnsonSVRandomGenerator  johnsonSvRndGen;
    JohnsonSURandomGenerator  johnsonSuRndGen;
};

#endif
