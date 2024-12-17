#include "enemy.h"
#include "raylib.h"

#include <vector>
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time
#include "raymath.h"


/*
Features of this class
--> Spawn Enemies 
    --> Diffrent speeds
    --> Types 
    --> Textures
--> Add a basic ai to make the enemies follow you
--> Collions with player and killing enemies with the bow 
*/



void Enemy::Spawn(Vector2 playerPos)
{
    // Spawn enemies if the list has less than 10 enemies
    for (size_t i = enemyList.size(); i < 10; i++) {
        // Set enemy stats
        enemy.positon = (Vector2){(rand() % 100), (rand() % 100)};
        enemy.speed = (rand() % 3) + 2;
        enemy.height = 40.0f;
        enemy.width = 40.0f;
        enemy.Texture = enemyTexture; 
        enemy.enemyDirection = Vector2Subtract(playerPos, enemy.positon);
        enemy.angle = atan2(enemy.enemyDirection.y, enemy.enemyDirection.x) * RAD2DEG;
        enemy.velocity = Vector2Scale(Vector2Normalize(enemy.enemyDirection), enemy.speed);

        // Add the enemy to the vector 
        enemyList.push_back(enemy);
    }

    // Update and draw all enemies
    for (size_t j = 0; j < enemyList.size(); j++) {
        // Update enemy direction and velocity
        enemyList[j].enemyDirection = Vector2Subtract(playerPos, enemyList[j].positon);
        enemyList[j].velocity = Vector2Scale(Vector2Normalize(enemyList[j].enemyDirection), enemyList[j].speed);
        enemyList[j].angle = atan2(enemyList[j].enemyDirection.y, enemyList[j].enemyDirection.x) * RAD2DEG;

        // Move the enemy
        enemyList[j].positon = Vector2Add(enemyList[j].positon, enemyList[j].velocity);

        // Draw the enemy
        DrawTextureEx(enemyList[j].Texture, enemyList[j].positon, enemyList[j].angle, 5.0f, WHITE);
    }
}