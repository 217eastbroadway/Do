#include <iostream>
#include <vector>
#include <string>
#include "raylib/raylib.h"
#include "task.hpp"
#include "filehandler.hpp"

#define TASK_WIDTH WINDOW_WIDTH * SCALE
#define TASK_HEIGHT 50 * SCALE
#define TASK_FONT_SIZE 30.0f * SCALE
#define WINDOW_HEIGHT 600 * SCALE
#define WINDOW_WIDTH 300 * SCALE
#define SCALE 1

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Do");

    std::vector<Task> tasks;

    std::vector<Texture2D> textures;
    textures.push_back(LoadTexture("res/checked.png"));
    textures.push_back(LoadTexture("res/unchecked.png"));

    Font font = LoadFontEx("res/helvetica.otf", TASK_FONT_SIZE, NULL, 0);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        //Debug Input Handling
        if(IsKeyDown(KEY_LEFT_CONTROL)) 
            if(IsKeyReleased(KEY_S))
                saveEverything(tasks);
            if(IsKeyReleased(KEY_L))
                loadEverything("save.dorec", tasks);
            

        //Input Handling
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            if(mouseX >= 0 && mouseX <= TASK_HEIGHT) { //Checking if mouse is inside of checkbox (x) [task_height is the same size as the checkbox]
                int clickedTaskIndex = mouseY / TASK_HEIGHT; 

                if(clickedTaskIndex < tasks.size()) { //Check if out of bounds
                    tasks[clickedTaskIndex].setIsChecked(!tasks[clickedTaskIndex].getIsChecked()); //invert checkbox status
                }
            }
        }

        //Rendering
        for(int i = 0; i<tasks.size(); i++) {
            DrawRectangle(0, (TASK_HEIGHT * i), TASK_WIDTH, TASK_HEIGHT, tasks[i].getBgColor());

            int checkboxTextureIndex; 
            if(tasks[i].getIsChecked())
                checkboxTextureIndex = 0;
            else
                checkboxTextureIndex = 1;

            DrawTextureEx(textures[checkboxTextureIndex], {0, (float)(TASK_HEIGHT * i)}, 0.0f, ((float)TASK_HEIGHT / textures[checkboxTextureIndex].width), WHITE);
            DrawTextEx(font, tasks[i].getName(), {(float)(TASK_HEIGHT + 15), (float)(TASK_HEIGHT * i)}, TASK_FONT_SIZE, 0.0f, WHITE);
        }

        EndDrawing();
    }
    return 0;
}