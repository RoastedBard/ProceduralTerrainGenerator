#ifndef _PERLINNOISE_H_
#define _PERLINNOISE_H_

#include <qimage.h>
#include "Generators\IRandomGenerator.h"

class PerlinNoise
{
public:
    PerlinNoise(void);
    ~PerlinNoise(void);

public:
    QImage generatePerlinNoise(int noiseSize, int noiseZoomFactor, IRandomGenerator *generator);

private:
    void _fillNoiseArray(IRandomGenerator *generator, int noiseSize);
    void _makeTexture(int noiseZoomFactor);
    double _turbulence(int x, int y);
    double _smoothNoise(double x, double y);

private:
    QImage _perlinTexture;
    std::vector< std::vector<double> > _noiseArray;
    int _noiseSize;
    int _noiseZoomFactor;
};

#endif
