#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "particle.h"

const int totalParticles = 20000;
const int particleRandMax = 3;
const int particleSpeedDivision = 5; // slower speed

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    srand(1);
    //--------------------------------------------------------------------------------------

    // Create particles
    Particle particles[totalParticles];
    for (int i = 0; i < totalParticles; i++) {
        particles[i] = Particle();
        particles[i].x = rand() % screenWidth;
        particles[i].y = rand() % screenHeight;
        particles[i].speed.x = 0;
        particles[i].speed.y = 0;
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        Vector2 mousePos = GetMousePosition();

        // Update particles
        for (int i = 0; i < totalParticles; i++) {
            Particle& p = particles[i];
            p.speed.x = rand() % particleRandMax;
            //p.speed.y = rand() % particleRandMax;
            p.x = Lerp(p.x, mousePos.x, p.speed.x / particleSpeedDivision);
            p.y = Lerp(p.y, mousePos.y, p.speed.x / particleSpeedDivision);
            p.Update();
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            for (int i = 0; i < totalParticles; i++) {
                particles[i].Draw();
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}