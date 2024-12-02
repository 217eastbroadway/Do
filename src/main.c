#include <stdio.h>
#include <raylib.h>
#include <graphics/objects/text.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/do.h>
#include <graphics/objects/button.h>

int main() {
    InitWindow(300, 800, "Do");

    int vSize = 3;
    Do *v = malloc(sizeof(Do) * 3);
    v[0] = createDo(true, "217eastbroadway", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 10, 200, 76});
    v[1] = createDo(false, "templeos", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 96, 200, 76});
    v[2] = createDo(true, "unchecked", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 182, 200, 76});

    Button b = createButton(createText("+", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), "res/textures/buttonaqua.png", (Rectangle) {250, 750, 35, 35});

    while(!WindowShouldClose()) {
        if(isClicked(b)) 
            createDoDialog(&v, &vSize);
        
        for(int i = 0; i < vSize; i++)
            checkToDo(&v[i]);

        ClearBackground(WHITE);
        BeginDrawing();

        for(int i = 0; i < vSize; i++)
            renderDo(&v[i]);

        renderButton(b);
        EndDrawing();   
    }
}