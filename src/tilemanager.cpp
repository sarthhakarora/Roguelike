#include "tilemanager.h"
#include "raylib.h"
#include <iostream>
#include <ctime>

void Tile::GenerateMap () {
    // Set seed
    srand(static_cast<unsigned int>(time(0)));

    // Loop through rows
    for (int k = 0; k < 250; k++) { 

        // Loop through columns
        for (int l = 0; l < 250; l++) {
            // Chance of a tree / Special object spawning is set to 1/10th
            
            if ((rand() % 9) != 1) { 
                // Set tile background
                tileMap[l][k] = 1;

            }
            if ((rand() % 9) == 1) {
                // Set tile to randomly picked object
                tileMap[l][k] = (rand() % 8) + 1;

            }
            //std::cout << tileMap[l][k] << ", "
        }
        //std::cout << std::endl;
    }
}

void Tile::TileRenderer()
{
    // Loop through each cell of the tile map
    for (int i = 0; i < 250; i++) {  
        for (int j = 0; j < 250; j++) {  
            // Set tile index 
            int tileIndex = tileMap[i][j];
            if (tileIndex >= 0 && tileIndex < sizeof(textures) / sizeof(Texture2D)) {
                // Draw tile
                DrawTextureEx(textures[tileIndex], (Vector2){ j * width - 5000, i * height - 5000}, 0.0f, 5.0f, WHITE);
            }
        }
    }
}

// Incompleat destructer
void Tile::Unload()
{
    UnloadTexture(backgroundTexture);
}

