#include <stdio.h>
#include <raylib.h>
#include <graphics/objects/text.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/do.h>
#include <graphics/objects/button.h>

int main() {
    InitWindow(300, 800, "Do");

    int vSize = 0;
    Do *v;

    Text header = createText("Tasks", "res/fonts/helvetica_neue_65.ttf", 50.0f, BLACK, 10, 10);
    Rectangle breakline = {10, 65, 280, 1};
    Button create = createButton(createText("+", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), "res/textures/buttonaqua.png", (Rectangle) {250, 750, 35, 35});
    Button delete = createButton(createText("-", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), "res/textures/buttonaqua.png", (Rectangle) {210, 750, 35, 35});

    while(!WindowShouldClose()) {
        //Input checking
        if(isClicked(create)) {
            createDoDialog(&v, &vSize);

            for(int i = 0; i < vSize; i++)
                printf("<ineedadebugger@main> %d @ %p\n", i, &v[i]);
        }

        if(isClicked(delete)) 
            deleteDoDialog(&v, &vSize);
        
        for(int i = 0; i < vSize; i++)
            checkToDo(&v[i]);

        //Rendering
        ClearBackground(WHITE);
        BeginDrawing();

        //Tasks (DOs)
        for(int i = 0; i < vSize; i++)
            renderDo(&v[i]);

        renderText(header);
        DrawRectangle(breakline.x, breakline.y, breakline.width, breakline.height, BLACK);
        renderButton(create);
        renderButton(delete);
        EndDrawing();   
    }
}