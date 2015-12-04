#pragma once
#include "irandomgenerator.h"
#include "NormalRandomGenerator.h"

class JohnsonSVRandomGenerator :
    public IRandomGenerator
{
public:
    JohnsonSVRandomGenerator(void);
    ~JohnsonSVRandomGenerator(void);

public:
    void setStartConditions(double lambda, double eta, double epsilon, double gamma, double multiplyConst, double startValue);
    virtual double generateRandomNumber();
    void setNormalRandomGenerator(NormalRandomGenerator normRnd);
    NormalRandomGenerator getNormalRandomGenerator();

private:
    NormalRandomGenerator _normRnd;
    double _epsilon;
    double _eta;
    double _lambda;
    double _gamma;
};

