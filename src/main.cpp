#include <iostream>
#include <vector>
#include <string>
#include "raylib/raylib.h"

#define TASK_WIDTH 300 * SCALE
#define TASK_HEIGHT 50 * SCALE
#define TASK_FONT_SIZE 30.0f * SCALE
#define WINDOW_HEIGHT 300 * SCALE
#define WINDOW_WIDTH 300 * SCALE
#define SCALE 3

class Task {
    private:
        //Logic
        std::string name;
        std::string description;
        bool isChecked;

        Color bgColor; //Default = white/transparent
    public:
        //Constructors

        Task(const char *name, const char *description, Color bgColor) { //Default Constructor
            this->name = name;
            this->description = description;
            this->bgColor = bgColor;
            this->isChecked = false;
        }

        Task(const Task& copy) { //Copy constructor
            this->name = copy.name;
            this->description = copy.description;
            this->isChecked = copy.isChecked;
            this->bgColor = copy.bgColor;
        }
        
        //Getters
        const char *getName() {
            return name.c_str();
        }

        const char *getDescription() {
            return description.c_str();
        }

        bool getIsChecked() {
            return isChecked;
        }

        Color getBgColor() {
            return bgColor;
        }

        //Setters
        void setName(const char* name) {
            this->name = name;
        }

        void setDescription(const char *description) {
            this->description = description;
        }

        void setIsChecked(bool isChecked) {
            this->isChecked = isChecked;
        }
        
        void setBgColor(Color bgColor) {
            this->bgColor = bgColor;
        }

        //i am such a faggot!!
};

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Do");

    std::vector<Task> tasks;
    tasks.push_back(Task("Do", "", {255, 175, 0, 255}));
    tasks.push_back(Task("Don't", "", {0, 150, 255, 255}));
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