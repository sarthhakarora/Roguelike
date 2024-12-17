#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "raylib.h"

class Tile {
public:
    float width = 40.0f;
    float height = 40.0f;
    int row = 100;
    int column = 100;
    
    Texture2D backgroundTexture = LoadTexture("../assets/Tiles/Colored/tile_0017.png");
    Texture2D waterTexture = LoadTexture("../assets/Tiles/Colored/tile_0140.png");
    Texture2D verticalWaterTexture = LoadTexture("../assets/Tiles/Colored/tile_0139.png");
    Texture2D tree1Texture = LoadTexture("../assets/Tiles/Colored/tile_0024.png");
    Texture2D tree2Texture = LoadTexture("../assets/Tiles/Colored/tile_0085.png");
    Texture2D tree3Texture = LoadTexture("../assets/Tiles/Colored/tile_0087.png");
    Texture2D blackGrassTexture = LoadTexture("../assets/Tiles/Colored/tile_0068.png");
    Texture2D grassTexture = LoadTexture("../assets/Tiles/Colored/tile_0069.png");
    Texture2D trblwaterTexture = LoadTexture("../assets/Tiles/Colored/tile_0155.png");
    Texture2D bltrwaterTexture = LoadTexture("../assets/Tiles/Colored/tile_0123.png");
    Texture2D horizontalwaterTexture = LoadTexture("../assets/Tiles/Colored/tile_0124.png");
    
    Texture2D textures[13] = {
        {},                      // 0 (Unused placeholder)
        backgroundTexture,       // 1
        tree1Texture,            // 2
        tree2Texture,            // 3
        tree3Texture,            // 4
        backgroundTexture,       // 5
        blackGrassTexture,       // 6
        grassTexture,            // 8
        //waterTexture,          // 8
        //verticalWaterTexture,  // 9
        //trblwaterTexture,      // 10
        //bltrwaterTexture,      // 11
        //horizontalwaterTexture // 12
    };


    struct tile
    {
        Texture2D Texture;
        Rectangle bounds;
        bool      isSolid;
    };
    
    int tileMap[1000][1000];
    /*int tileMap[15][20] = {
        {1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 5, 1, 9, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1},
        {1, 9, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 5},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,11,12,12,12},
        {1, 1, 5, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1,11,12,12, 7, 7, 7, 7},
        {1, 1, 1, 4, 1, 1, 1, 3, 1, 1, 1, 1, 2, 8, 7, 7, 7, 7, 7, 7},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 8, 7, 7, 7, 7, 7, 7},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 7, 7, 7, 7, 7, 7},
        {1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 8, 7, 7, 7, 7, 7, 7},
        {1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1,10, 7, 7, 7, 7, 7, 7}
    };*/




    void GenerateMap();
    void TileRenderer();
    void Unload();

};

#endif