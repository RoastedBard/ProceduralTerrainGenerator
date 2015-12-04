#include "PerlinNoise.h"


PerlinNoise::PerlinNoise(void)
{
    _noiseSize = 0;
    _noiseZoomFactor = 0;
}


PerlinNoise::~PerlinNoise(void)
{
}

QImage PerlinNoise::generatePerlinNoise(int noiseSize, int noiseZoomFactor, IRandomGenerator *generator)
{
    _noiseSize = noiseSize;
    _noiseZoomFactor = noiseZoomFactor;

    _fillNoiseArray(generator, _noiseSize);
    _makeTexture(_noiseZoomFactor);

    return _perlinTexture;
}

void PerlinNoise::_fillNoiseArray(IRandomGenerator *generator, int noiseSize)
{
    _noiseArray.resize(noiseSize);
    for(int i = 0; i < _noiseArray.size(); i++)
        _noiseArray[i].resize(noiseSize);

    for(int i = 0; i < _noiseArray.size(); i++)
    {
        for(int j = 0; j < _noiseArray.size(); j++)
        {
            double dValue = generator->generateRandomNumber();
            int iValue = (int)dValue;
            double value = dValue - iValue;

            _noiseArray[i][j] = value;
        }
    }

}

void PerlinNoise::_makeTexture(int noiseZoomFactor)
{
    QImage resultTexture(_noiseSize, _noiseSize, QImage::Format_RGB888);

    for (int i = 0; i < _noiseSize; i++)
    {
        for (int j = 0; j < _noiseSize; j++)
        {
            int perlinColor =  abs(_turbulence(i, j));
            QRgb color = qRgb(perlinColor, perlinColor, perlinColor);
            resultTexture.setPixel(i, j, color);
        }
    }

    _perlinTexture = resultTexture;
}

double PerlinNoise::_turbulence(int x, int y)
{
    double size = _noiseZoomFactor;

    double value = 0.0, initialSize = size;
    
    while (size >= 1)
    {
        value += _smoothNoise(x / size, y / size) * size;
        size /= 2.0;
    }
    
    return (128.0 * value / initialSize);
}

double PerlinNoise::_smoothNoise(double x, double y)
{
    //get fractional part of x and y
   double fractX = x - int(x);
   double fractY = y - int(y);
   
   //wrap around
   int x1 = (int(x) + _noiseSize) % _noiseSize;
   int y1 = (int(y) + _noiseSize) % _noiseSize;
   
   //neighbor values
   int x2 = (x1 + _noiseSize- 1) % _noiseSize;
   int y2 = (y1 + _noiseSize - 1) % _noiseSize;

   //smooth the noise with bilinear interpolation
   double value = 0.0;
   value += fractX       * fractY       * _noiseArray[x1][y1];
   value += fractX       * (1 - fractY) * _noiseArray[x1][y2];
   value += (1 - fractX) * fractY       * _noiseArray[x2][y1];
   value += (1 - fractX) * (1 - fractY) * _noiseArray[x2][y2];

   return value;
}
