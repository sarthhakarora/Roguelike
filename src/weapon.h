#ifndef WEAPON_H
#define WEAPON_H

#include "raylib.h"
#include "raymath.h"
#include "enemy.h" 

#include <iostream>
#include <vector>

class Weapon {
public:
    struct weaponStats
    {
        float width;
        float height;
        float x;
        float y;
        float angle;
        Vector2 direction;
        Texture2D texture;
        Rectangle src;
        Rectangle dest;
        
    };

    struct projectileStats
    {
        float width;
        float height;
        float x;
        float y;
        float angle;
        float speed;
        Vector2 direction;
        Vector2 velocity;
        Texture2D texture;
        Rectangle src;
        Rectangle dest;
    };
    
    
    Vector2 worldMousePos = {};

    Texture2D bowTexture = LoadTexture("../assets/Tiles/Colored/bow.png");
    weaponStats weapon;
    
    Texture2D arrowTexture = LoadTexture("../assets/Tiles/Colored/tile_0073.png");
    std::vector<projectileStats> projectileList;
    projectileStats projectile;
    int maxProjCount = 10000;

    void BowDraw();
    void BowUpdate(Vector2 playerPos, Vector2 mousePos, Vector2 cameraPos);

    void ArrowDraw(Vector2 playerPos);
    void ArrowUpdate(Vector2 playerPos, std::vector<Enemy::enemyStats>& enemyList);
};

#endif 