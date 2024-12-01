#include <stdio.h>
#include <raylib.h>
#include <graphics/objects/text.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/do.h>
#include <graphics/objects/button.h>

int main() {
    InitWindow(300, 800, "Do");

    Do *v = malloc(sizeof(Do) * 3);
    v[0] = createDo(true, "217eastbroadway", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 10, 200, 76});
    v[1] = createDo(false, "cacchio?", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 96, 200, 76});
    v[2] = createDo(true, "unchecked", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 182, 200, 76});

    Button b;
    b = createButton("res/textures/button.png", (Rectangle) {220, 720, 75, 75});

    while(!WindowShouldClose()) {
        for(int i = 0; i < 3; i++)
            checkToDo(&v[i]);

        if(isClicked(b))
            printf("Hello\n");

        ClearBackground(WHITE);
        BeginDrawing();

        for(int i = 0; i < 3; i++)
            renderDo(&v[i]);

        renderButton(b);
        
        EndDrawing();
    }
}
