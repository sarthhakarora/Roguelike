#include "weapon.h"
#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <vector>

void Weapon::BowUpdate(Vector2 playerPos, Vector2 mousePos, Vector2 cameraPos)
{
    weapon.height = 40.0f;
    weapon.width = 40.0f;
    weapon.x = playerPos.x;
    weapon.y = playerPos.y;
    weapon.src = {0.0f, 0.0f, 8.0f, 8.0f};
    weapon.dest = {weapon.x, weapon.y, weapon.width, weapon.height};
    weapon.texture = bowTexture;
    weapon.direction = Vector2Subtract((Vector2){weapon.x, weapon.y}, worldMousePos);
    weapon.angle = atan2(weapon.direction.y, weapon.direction.x) * RAD2DEG - 130.0f;

    //std::cout << weapon.x << ":" << weapon.y << "||" << playerPos.x << ":" << playerPos.y << std::endl;
}

void Weapon::BowDraw()
{
    DrawTexturePro(
        weapon.texture, 
        weapon.src, 
        weapon.dest,
        (Vector2){weapon.height/2, weapon.width/2},
        weapon.angle,
        WHITE
        );

    //void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint); // Draw a part of a texture defined by a rectangle with 'pro' parameters
}


void Weapon::ArrowDraw(Vector2 playerPos)
{
    if (IsKeyPressed(KEY_SPACE) && projectileList.size() < maxProjCount) {
        projectile.width = 40.0f;
        projectile.height = 40.0f;
        projectile.x = playerPos.x; // Start at the player's position
        projectile.y = playerPos.y; // Start at the player's position
        projectile.speed = 7.0f;
        projectile.src = {0.0f, 0.0f, 8.0f, 8.0f};
        projectile.dest = {projectile.x, projectile.y, 40.0f, 40.0f};
        projectile.texture = arrowTexture;

        projectile.direction = Vector2Subtract(GetMousePosition(), playerPos);
        projectile.angle = weapon.angle;
        projectile.velocity = Vector2Scale(Vector2Normalize(projectile.direction), projectile.speed);

        projectileList.push_back(projectile);
    }
}

void Weapon::ArrowUpdate(Vector2 playerPos)
{
    for (size_t j = 0; j < projectileList.size(); j++) {
        projectileList[j].dest.x += projectileList[j].velocity.x;
        projectileList[j].dest.y += projectileList[j].velocity.y;

        // Check if the projectile is out of bounds
        if (projectileList[j].dest.x < 0 || projectileList[j].dest.y < 0 ||
            projectileList[j].dest.x > 800 || projectileList[j].dest.y > 600) {
            projectileList.erase(projectileList.begin() + j);
            j--; // Adjust loop index after removal
            continue;
        }

        // Render the projectile
        DrawTexturePro(
            projectileList[j].texture,
            projectileList[j].src,
            projectileList[j].dest,
            (Vector2){projectileList[j].width / 2, projectileList[j].height / 2},
            projectileList[j].angle,
            WHITE
        );
    }
}

