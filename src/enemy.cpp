#include "enemy.h"
#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <iostream>
#include <ctime>

// Spawn functions
void Enemy::spawn(Vector2 playerPos) {
    // Loop through all of the Enemies
    for (size_t i = 0; i < maxEnemyCount; i++) {
        if (enemyList.size() < maxEnemyCount) { // Check if we can add more enemies

            // Randomize position outside the camera's view
            int spawnMargin = 50; // Distance outside the camera to spawn
            int edge = rand() % 4; // Randomly select one of the edges
            switch (edge) {
                case 0: // Top
                    enemy.x = rand() % 400 + playerPos.x; // Random x within width
                    enemy.y = -spawnMargin; // Above the camera
                    break;
                case 1: // Bottom
                    enemy.x = rand() % 400 - playerPos.x;
                    enemy.y = 600 + spawnMargin; // Below the camera
                    break;
                case 2: // Left
                    enemy.x = -spawnMargin; // To the left of the camera
                    enemy.y = rand() % 300 + playerPos.y;
                    break;
                case 3: // Right
                    enemy.x = 800 + spawnMargin; // To the right of the camera
                    enemy.y = rand() % 300 + playerPos.y;;
                    break;
            }

            // Set Basic enemy Stats
            enemy.width = 40.0f;
            enemy.height = 40.0f;
            enemy.speed = rand() % 3 + 2;
            enemy.src = {0.0f, 0.0f, 8.0f, 8.0f};
            enemy.dest = {enemy.x, enemy.y, 40.0f, 40.0f};
            enemy.texture = zombieTexture;

            // Calculate the angle to make the enemy point towards the player
            Vector2 direction = Vector2Subtract(playerPos, (Vector2){enemy.dest.x, enemy.dest.y});
            direction = Vector2Normalize(direction);
            enemy.angle = atan2(direction.y, direction.x) * RAD2DEG;
            enemy.velocity = Vector2Scale(direction, enemy.speed);

            // Add this instance of the enemy to the enemyList
            enemyList.push_back(enemy);
        }
    }
}



// Enemy Update function
void Enemy::update(Vector2 playerPos)
{

    // Loop through all of the enemies
    for (size_t j = 0; j < maxEnemyCount; j++) {

        // Recalulate the direction so it updates everytime the enemy is drawn
        enemyList[j].direction = Vector2Multiply(Vector2Subtract((Vector2){enemyList[j].dest.x, enemyList[j].dest.y}, playerPos), Vector2{-1.0f, -1.0f});
        enemyList[j].angle = atan2(enemyList[j].direction.x, enemyList[j].direction.y) * RAD2DEG - 90.0f;
        
        enemyList[j].velocity = Vector2Scale(Vector2Normalize(enemyList[j].direction), enemyList[j].speed);
        enemyList[j].dest.x = enemyList[j].velocity.x + enemyList[j].dest.x;
        enemyList[j].dest.y = enemyList[j].velocity.y + enemyList[j].dest.y;

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
