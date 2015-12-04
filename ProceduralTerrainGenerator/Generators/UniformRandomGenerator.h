#pragma once

#include "irandomgenerator.h"

class UniformRandomGenerator :
    public IRandomGenerator
{
public:
    UniformRandomGenerator(void);
    ~UniformRandomGenerator(void);

public:
    void setStartConditions(double multiplyConst, double startValue);
    virtual double generateRandomNumber();

private:
    double        _multiplyConst;
    static double _lastGenerated;
};

