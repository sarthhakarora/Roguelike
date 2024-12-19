#include "raylib.h"
#include "player.h"
#include "tilemanager.h"
#include "camera.h"
#include "weapon.h"
#include "enemy.h"

#include <iostream>

int main() {
    // Initialize window
    InitWindow(800, 600, "Rogue Like Game");

    // Set fps
    SetTargetFPS(60);

    // Player object creation and set player object to the middle of the screen
    Player player;
    player.x = GetScreenWidth()/2 - player.width/2;
    player.y = GetScreenHeight()/2 - player.height/2;

    // More objects 
    Tile tile;
    GameCamera camera;
    Weapon Weapon;

    // Cam attributes
    camera.x = player.x;
    camera.y = player.y;
    camera.camUpdate();

    tile.GenerateMap();
    
    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();
       
        // Set background color
        ClearBackground(Color{34, 35, 35, 255});
        // Set camera target to player center
        camera.camera.target = (Vector2){player.destRect.x, player.destRect.y};
        
        // Camera mode
        BeginMode2D(camera.camera);
        
        // Game functions
        tile.TileRenderer();
        player.Draw();
        player.Update();

        Weapon.Draw();
        Weapon.Update((Vector2){player.destRect.x, player.destRect.y}, GetMousePosition());
        
        // End drawing
        EndMode2D();
        DrawFPS(20, 20);

        
        EndDrawing();
    }

    player.Unload();
    //tile.Unload
    // Clean up
    CloseWindow();  // Close window and OpenGL context
    return 0;
}
