#pragma once
#include "irandomgenerator.h"
#include "UniformRandomGenerator.h"

class NormalRandomGenerator :
    public IRandomGenerator
{
public:
    NormalRandomGenerator(void);
    ~NormalRandomGenerator(void);

public:
    void setStartConditions(double multiplyConst, double startValue);
    virtual double generateRandomNumber();
    void setUniformRandomGenerator(UniformRandomGenerator uniformRnd);
    UniformRandomGenerator getUniformRandomGenerator();

private:
    UniformRandomGenerator _uniformRndGen;
};

