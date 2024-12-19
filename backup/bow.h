#ifndef BOW_H
#define BOW_H

#include "raylib.h"

#include <vector>

class Bow {
public:
    // Bow stats 

    float width = 40.0f;
    float height = 40.0f;
    Vector2 bowDirection = {0,0};
    Texture2D Texture = LoadTexture("../assets/Tiles/Colored/bow.png");
    Rectangle src = {0, 0, 8.0f, 8.0f};
    Rectangle dest = {0, 0, width, height};
    float angle = 0.0f;

    // Arrow stats
    float arrowWidth = 40.0f; 
    float arrowHeight = 40.0f; 
    float arrowSpeed = 7.0f;
    Texture2D ArrowTexture = LoadTexture("../assets/Tiles/Colored/tile_0073.png");


    struct projectile
    {
    Vector2 postion;       // Position for calculations
    Vector2 velocity;      // Velocity vector
    Vector2 direction;     // Direction vector
    float arrowAngle;      // Angle calculated for movement
    float actualAngle;     // Actual rotation angle for rendering
    Rectangle dest;        // Destination rectangle for rendering
    };



    std::vector<projectile> projectiles;
    projectile arrows;

    void BowMovement(Vector2 cameraPos, Vector2 mousePos, Vector2 playerPos); 
    void ArrowMovement(Vector2 playerPos, Vector2 mousePos);
    void Draw();
};

#endif
