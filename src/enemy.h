#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <vector>
#include <iostream>


class Enemy {
public:
    struct enemyStats
    {
        Vector2 positon;
        Vector2 velocity;
        Vector2 enemyDirection;
        
        Texture2D Texture;
        float speed;
        float width;
        float height;

    };

    std::vector<enemyStats> enemyList;
    enemyStats enemy;

    
    void Spawn(Vector2 playerPos);
};

#endif