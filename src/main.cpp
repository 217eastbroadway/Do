#include <iostream>
#include <vector>
#include <string>
#include "raylib/raylib.h"
#include "task.hpp"

#define TASK_WIDTH WINDOW_WIDTH * SCALE
#define TASK_HEIGHT 50 * SCALE
#define TASK_FONT_SIZE 30.0f * SCALE
#define WINDOW_HEIGHT 600 * SCALE
#define WINDOW_WIDTH 300 * SCALE
#define SCALE 1.25

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Do");

    std::vector<Task> tasks;
    tasks.push_back(Task("Do", "", {255, 175, 0, 255}));
    tasks.push_back(Task("Dont", "", {0, 150, 255, 255}));
    tasks.push_back(Task("Maybe Do", "", {255, 0, 150, 255}));
    tasks.push_back(Task("Unsure", "", {0, 255, 150, 255}));
    tasks.push_back(Task("Almost Sure", "", {255, 0, 200, 255}));
    tasks.push_back(Task("Pretty Sure", "", {255, 0, 0, 255}));
    tasks[2].setIsChecked(true);

    std::vector<Texture2D> textures;
    textures.push_back(LoadTexture("res/checked.png"));
    textures.push_back(LoadTexture("res/unchecked.png"));

    Font font = LoadFontEx("res/helvetica.otf", TASK_FONT_SIZE, NULL, 0);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for(int i = 0; i<tasks.size(); i++) {
            DrawRectangle(0, (TASK_HEIGHT * i), TASK_WIDTH, TASK_HEIGHT, tasks[i].getBgColor());

            if(tasks[i].getIsChecked())
                DrawTextureEx(textures[0], {0, (float)(TASK_HEIGHT * i)}, 0.0f, ((float)TASK_HEIGHT / textures[0].width), WHITE);
            else
                DrawTextureEx(textures[1], {0, (float)(TASK_HEIGHT * i)}, 0.0f, ((float)TASK_HEIGHT / textures[1].width), WHITE);

            // printf("%d // %d // %f\n", TASK_HEIGHT * i, i, (float)TASK_HEIGHT / textures[0].width);

            DrawTextEx(font, tasks[i].getName(), {(float)(TASK_HEIGHT + 15), (float)(TASK_HEIGHT * i)}, TASK_FONT_SIZE, 0.0f, WHITE);
        }

        EndDrawing();
    }
    return 0;
}