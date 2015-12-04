#pragma once
#include "irandomgenerator.h"
#include "UniformRandomGenerator.h"

class ExponentalRandomGenerator :
    public IRandomGenerator
{
public:
    ExponentalRandomGenerator(void);
    ~ExponentalRandomGenerator(void);

public:
    void setStartConditions(double lambda, double mu, double multiplyConst, double startValue);
    virtual double generateRandomNumber();
    void setUniformRandomGenerator(UniformRandomGenerator uniformRnd);
    UniformRandomGenerator getUniformRandomGenerator();

private:
    UniformRandomGenerator _uniformRndGen;
    double _lambda;
    double _mu;
};

