#include <iostream>
#include "raylib.h"

int main() {
    InitWindow(300, 300, "Do");
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Do", 15, 15, 25, WHITE);

        EndDrawing();
    }
    return 0;
}