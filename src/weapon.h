#ifndef WEAPON_H
#define WEAPON_H

#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <vector>

class Weapon {
public:
    struct projectile
    {
        float width;
        float height;
        float angle;
        Texture2D texture;
        Rectangle src;
        Rectangle dest;
        
    };

    Texture2D bowTexture = LoadTexture("../assets/Tiles/Colored/bow.png");
    
    projectile proj;
    
    void Draw();
    void Update(Vector2 playerPos, Vector2 mousePos);
};

#endif 