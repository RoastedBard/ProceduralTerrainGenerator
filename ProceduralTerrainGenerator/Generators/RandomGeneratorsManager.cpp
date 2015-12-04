#include "RandomGeneratorsManager.h"
#include "RandomType.h"

RandomGeneratorsManager::RandomGeneratorsManager(void)
{
}


RandomGeneratorsManager::~RandomGeneratorsManager(void)
{
}

IRandomGenerator* RandomGeneratorsManager::getCurrent(int curr)
{
    switch (curr)
    {
    case UNIFORM_RANDOM_GENERATOR:
        return &uniformRndGen;

    case NORMAL_RANDOM_GENERATOR:
        return &normalRndGen;
    
    case EXPONENTIAL_RANDOM_GENERATOR:
        return &expRndGen;
    
    case LOGARIFM_RANDOM_GENERATOR:
        return &logRndGen;
    
    case JOHNSON_SV_RANDOM_GENERATOR:
        return &johnsonSvRndGen;
    
    case JOHNSON_SU_RANDOM_GENERATOR:
        return &johnsonSuRndGen;
    }

    return 0;
}
