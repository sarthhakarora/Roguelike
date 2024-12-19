#include "weapon.h"
#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <vector>

void Weapon::Update(Vector2 playerPos, Vector2 mousePos)
{
    proj.height = 40.0f;
    proj.width = 40.0f;
    proj.src = {0.0f, 0.0f, 8.0f, 8.0f};
    proj.dest = {0.0f, 0.0f, proj.width, proj.height};
    proj.texture = bowTexture;
    proj.angle =  0.0f;

    proj.dest.x = playerPos.x;
    proj.dest.y = playerPos.y;

}

void Weapon::Draw()
{
    DrawTexturePro(
        proj.texture, 
        proj.src, 
        proj.dest,
        (Vector2){proj.height/2, proj.width/2},
        proj.angle,
        WHITE
        );

    //void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint); // Draw a part of a texture defined by a rectangle with 'pro' parameters
}