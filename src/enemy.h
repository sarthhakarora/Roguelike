#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <iostream>

class Enemy {
public:
    struct enemyStats
    {
        float x;
        float y;
        float speed;
        float angle;
        int width;
        int height;
        Texture2D texture;
        Rectangle src;
        Rectangle dest;
        Vector2 velocity;
        Vector2 direction;

    };

    int maxEnemyCount = 100;
    

    Texture2D zombieTexture = LoadTexture("../assets/Tiles/Colored/tile_0011.png");

    std::vector<enemyStats> enemyList;
    enemyStats enemy;

    void spawn(Vector2 playerPos);
    void update(Vector2 cameraPos);
};

#endif