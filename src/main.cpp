#include <iostream>
#include <vector>
#include <string>
#include "raylib/raylib.h"

class Task {
    private:
        std::string name;
        std::string description;
        
    public:
};

int main() {
    InitWindow(300, 300, "Do");

    Texture2D checked = LoadTexture("res/checked.png");        
    Font font = LoadFontEx("res/helvetica.otf", 30, NULL, 0);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        
        // std::vector<TextureX*> textures;
        // textures.push_back(new TextureX("res/checked.png", "checked"));
        // textures.push_back(new TextureX("res/unchecked.png", "checked"));
        DrawTextureEx(checked, {0, 0}, 0.0f, 0.1f, WHITE);
        DrawTextEx(font, "Task", {(checked.width * 0.1f), (checked.height * 0.1f) / 2 - 30 / 2 }, 30.0f, 0.0f, WHITE);

        EndDrawing();
    }
    return 0;
}