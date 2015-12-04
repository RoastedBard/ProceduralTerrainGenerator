#pragma once
class IRandomGenerator
{
public:
    virtual ~IRandomGenerator(void){}

public:
    virtual double generateRandomNumber() = 0;
};

