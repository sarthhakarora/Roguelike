#include "enemy.h"
#include "raylib.h"

#include <vector>
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time


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
    // Set the seed to the current time
    srand(static_cast<unsigned int>(time(0)));
    
    // Spawn enemy
    for (size_t i = enemyList.size(); i < 10; i++)  {
        // Set enemy stats
        enemy.positon = (Vector2){rand() % 100, rand() % 100};
        enemy.speed = 5;
        enemy.height = 40.0f;
        enemy.width = 40.0f;
        enemy.Texture = LoadTexture("../assets/Tiles/Colored/tile_0011.png");
        
        enemy.velocity = {};

        // Add the enemy to my std::Vector 
        enemyList.push_back(enemy);
    }

    // DrawTextureEx(LoadTexture("../assets/Tiles/Colored/tile_0011.png"), (Vector2){0, 0}, 0.0f, 5.0f, WHITE);


    // Loop through the enemies to draw them
    for (size_t j = 0; j < enemyList.size();  j++)  {
        // void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);  // Draw a Texture2D with extended parameters
        DrawTextureEx(enemyList[j].Texture, enemyList[j].positon, 0.0f, 5.0f, WHITE);
    }
}