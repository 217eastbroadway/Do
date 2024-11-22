#include <stdio.h>
#include <raylib.h>
#include <graphics/objects/text.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/do.h>

int main() {
    InitWindow(300, 800, "Do");

    
    Do a = createDo(true, "217eastbroadway", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 10, 200, 76});
    Do b = createDo(false, "balls", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 96, 200, 76});
    Do c = createDo(true, "unchecked", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 182, 200, 76});

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_ENTER))
            b.checkbox.isChecked = !b.checkbox.isChecked;


        ClearBackground(WHITE);
        BeginDrawing();        

        renderDo(a);
        renderDo(b);
        renderDo(c);

        EndDrawing();
    }
}
