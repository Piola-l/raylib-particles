#pragma once
#include <raylib.h>

class Particle
{
public:
    Particle();
    void Update();
    void Draw() const;
    int x;
    int y;
    Vector2 speed;

private:
    float radius;
};