#include "enemy.h"
#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <iostream>
#include <ctime>

// Spawn functions
void Enemy::spawn(Vector2 playerPos)
{
    // Set RNG seed
    srand(static_cast<unsigned int>(time(0)));

    // Loop through all of the Enemies
    for(size_t i = 0; i < maxEnemyCount; i++) {

        // Set Basic player Stats
        enemy.x = 100; //rand() % 100;
        enemy.y = 100; //rand() % 100;
        enemy.width = 40.0f;
        enemy.height = 40.0f;
        enemy.speed = rand() % 3 + 5;
        enemy.src = {0.0f, 0.0f, 8.0f, 8.0f};
        enemy.dest = {enemy.x, enemy.y, 40.0f, 40.0f};
        enemy.texture = zombieTexture;

        // Calulate the angle to make the enemy point towards the player
        enemy.direction = Vector2Subtract((Vector2){enemy.dest.x, enemy.dest.y}, playerPos);
        enemy.angle = atan2(enemy.direction.x, enemy.direction.y) * RAD2DEG * -1.0f;

        // Add this instance of the enemy to enemyList 
        enemyList.push_back(enemy);
    }
}

// Enemy Update function
void Enemy::update(Vector2 playerPos)
{

    // Loop through all of the enemies
    for (size_t j = 0; j < maxEnemyCount; j++) {

        // Recalulate the direction so it updates everytime the enemy is drawn
        enemyList[j].direction = Vector2Subtract((Vector2){enemyList[j].x, enemyList[j].y}, playerPos);
        enemyList[j].angle = atan2(enemyList[j].direction.x, enemyList[j].direction.y) * RAD2DEG * -1.0f;

        // Draw enemy using DrawTexturePro
        DrawTexturePro(
            enemyList[j].texture,
            enemyList[j].src,
            enemyList[j].dest,
            (Vector2){enemyList[j].height / 2, enemyList[j].width / 2},
            enemyList[j].angle,
            WHITE);
    }

}
