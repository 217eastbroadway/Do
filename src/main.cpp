#include <iostream>
#include <vector>
#include <string>
#include "raylib/raylib.h"

class Task {
    private:
        //Logic
        std::string name;
        std::string description;
        bool isChecked;

        Vector3 bgColor; //Default = white/transparent
    public:
        //Constructors

        Task(const char *name, const char *description, Vector3 bgColor) { //Default Constructor
            this->name = name;
            this->description = description;
            this->bgColor = bgColor;
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

        Vector3 getBgColor() {
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
        
        void setBgColor(Vector3 bgColor) {
            this->bgColor = bgColor;
        }

        //i am such a faggot!!
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
        // DrawTextureEx(checked, {0, 0}, 0.0f, 0.1f, WHITE);
        // DrawTextEx(font, "Task", {(checked.width * 0.1f), (checked.height * 0.1f) / 2 - 30 / 2 }, 30.0f, 0.0f, WHITE);
        DrawTextEx(font, "Task", {15, 15}, 30.0f, 0.0f, WHITE);

        EndDrawing();
    }
    return 0;
}