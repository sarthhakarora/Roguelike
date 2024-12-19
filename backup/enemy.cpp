#include "enemy.h"
#include "raylib.h"
#include "bow.h"

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

void Enemy::Spawn(Vector2 playerPos, std::vector<Bow::projectile> projetiles)
{
    // Seed the random generator
    srand(static_cast<unsigned int>(time(0)));

    // Spawn enemies if the list has less than 10 enemies
    for (size_t i = enemyList.size(); i < 10; i++) {
        // Set enemy stats
        enemy.speed = (rand() % 3) + 2;  // Random speed between 2 and 4
        enemy.height = 40.0f;
        enemy.width = 40.0f;
        enemy.Texture = enemyTexture;  // Assign texture
        
        // Random starting position
        float randomX = static_cast<float>(rand() % 1000);  // Adjust range based on screen width
        float randomY = static_cast<float>(rand() % 800);  // Adjust range based on screen height

        // Define source and destination rectangles
        enemy.src = {0, 0, 8.0f, 8.0f};  // Texture's source rectangle
        enemy.dest = {randomX, randomY, enemy.width, enemy.height};  // Destination rectangle for drawing

        // Calculate direction and velocity
        Vector2 enemyDirection = Vector2Subtract(playerPos, (Vector2){enemy.dest.x, enemy.dest.y});
        enemy.angle = atan2(enemyDirection.y, enemyDirection.x) * RAD2DEG;
        enemy.velocity = Vector2Scale(Vector2Normalize(enemyDirection), enemy.speed);

        // Add the enemy to the list
        enemyList.push_back(enemy);
    }

    // Update and draw all enemies
    
    for (size_t j = 0; j < enemyList.size(); j++) {
        // Calculate enemy movement
        Vector2 enemyDirection = Vector2Subtract(playerPos, (Vector2){enemyList[j].dest.x, enemyList[j].dest.y});
        enemyList[j].velocity = Vector2Scale(Vector2Normalize(enemyDirection), enemyList[j].speed);
        enemyList[j].angle = atan2(enemyDirection.y, enemyDirection.x) * RAD2DEG;

        // Update position in `dest` rectangle
        enemyList[j].dest.x += enemyList[j].velocity.x;
        enemyList[j].dest.y += enemyList[j].velocity.y;
        
        for (size_t k = 0; k < projetiles.size(), k++;)
        if(CheckCollisionRecs(enemyList[k].dest,projetiles[k].dest)) {
            std::cout << "collision" << std::endl;
        }

    

        // Draw the enemy
        DrawTexturePro( enemyList[j].Texture, enemyList[j].src, enemyList[j].dest, (Vector2){enemyList[j].width / 2.0f, enemyList[j].height / 2.0f}, enemyList[j].angle, WHITE);

    
    }
}
