#include <stdio.h>
#include <raylib.h>
#include <graphics/objects/text.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/do.h>
#include <graphics/objects/button.h>

int main() {
    InitWindow(300, 800, "Do");
    SetExitKey(0);

    int vSize = 0;
    Do *v;

    Text header = createText("Tasks", "res/fonts/helvetica_neue_65.ttf", 50.0f, BLACK, 10, 10);
    Rectangle breakline = {10, 65, 280, 1};
    Button create = createButton(createText("+", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), "res/textures/buttonaqua.png", (Rectangle) {250, 750, 35, 35});
    Button delete = createButton(createText("-", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), "res/textures/buttonaqua.png", (Rectangle) {210, 750, 35, 35});

    while(!WindowShouldClose()) {
        //Input checking
        if(isClicked(create)) 
            createDoDialog(&v, &vSize);

        if(isClicked(delete)) 
            deleteDoDialog(&v, &vSize);
        
        for(int i = 0; i < vSize; i++)
            checkToDo(&v[i]);

        float scroll = GetMouseWheelMove() * 10;
        for(int i = 0; i < vSize; i++) {
            setDoPos(&v[i], (Rectangle) {v[i].x, v[i].y - scroll, v[i].checkbox.pos.width, v[i].checkbox.pos.height});
        }

        //Rendering
        ClearBackground(WHITE);
        BeginDrawing();

        //Tasks (DOs)
        for(int i = 0; i < vSize; i++)
            renderDo(v[i]);

        DrawRectangle(0, 0, 300, 85, WHITE);
        renderText(header);
        DrawRectangle(breakline.x, breakline.y, breakline.width, breakline.height, BLACK);
        renderButton(create);
        renderButton(delete);
        EndDrawing();   
    }
}