#pragma once
#include "irandomgenerator.h"
#include "NormalRandomGenerator.h"

class JohnsonSURandomGenerator :
    public IRandomGenerator
{
public:
    JohnsonSURandomGenerator(void);
    ~JohnsonSURandomGenerator(void);

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

