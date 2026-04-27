#include "ui.hpp"

void ui::createTask(std::vector<Task> &tasks) {
    bool isCreated = false; //loop conditional var
    std::string str = "";

    //ui vars
    Font font = LoadFontEx("res/helvetica.otf", 30.0f, NULL, 0); //should i move shit around? dunno
    int textBoxWidth = 250;
    int textBoxHeight = 50;
    
    while(!isCreated) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextPro(font, "Create New Task", {0, 0}, {0, 0}, 0.0f, 30.0f, 0.0f, BLACK);
        DrawRectangle(GetRenderWidth() / 2 - textBoxWidth / 2, GetRenderHeight() / 2 - textBoxHeight / 2, textBoxWidth, textBoxHeight, {75, 75, 75, 255});
        char pressedChar = GetCharPressed(); //TODO: this sucks, space / backspace aren't recognized, also add backspace support.

        if(pressedChar > 0)
            str += pressedChar;

        DrawTextPro(font, str.c_str(), {(float)GetRenderWidth() / 2 - textBoxWidth / 2, (float)GetRenderHeight() / 2 - textBoxHeight / 2}, {0, 0}, 0.0f, 30.0f, 0.0f, WHITE);
        EndDrawing();

        if(IsKeyDown(KEY_LEFT_CONTROL))
            if(IsKeyReleased(KEY_C)) {
                std::cout << "[DEBUG] ui::createTask >> Quitting...\n";
                isCreated = true;
            }
    }

    UnloadFont(font);
}