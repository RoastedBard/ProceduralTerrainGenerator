#pragma once

struct Vertex3f
{
    float x;
    float y;
    float z;

    Vertex3f()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vertex3f(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void setAll(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};