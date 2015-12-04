#pragma once
#include "irandomgenerator.h"
#include "NormalRandomGenerator.h"

class LogarifmNormalRandomGenerator :
    public IRandomGenerator
{
public:
    LogarifmNormalRandomGenerator(void);
    ~LogarifmNormalRandomGenerator(void);

public:
    void setStartConditions(double sigma, double mu, double multiplyConst, double startValue);
    virtual double generateRandomNumber();
    void setNormalRandomGenerator(NormalRandomGenerator normRnd);
    NormalRandomGenerator getNormalRandomGenerator();

private:
    NormalRandomGenerator _normRnd;
    double _sigma;
    double _mu;
};

