#include "particle.h"
#include <raylib.h>

Particle::Particle() 
    : x(100)
    , y(100)
    , speed(Vector2{2, -3})
    , radius(1) 
{
}

void Particle::Update() 
{
    x += speed.x;
    y += speed.y;
    
    // const int screenHeight = GetScreenHeight();
    // const int screenWidth = GetScreenWidth();
    
    // if ((x + radius >= screenWidth) || (x - radius <= 0)) {
    //     speedX *= -1;
    // }
    
    // if ((y + radius >= screenHeight) || (y - radius <= 0)) {
    //     speedY *= -1;
    // }
}

void Particle::Draw() const
{
    DrawPixel(x, y, BLACK);
    //DrawCircle(x, y, radius, BLACK);
}