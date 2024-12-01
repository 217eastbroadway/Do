#include <stdio.h>
#include <raylib.h>
#include <graphics/objects/text.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/do.h>

void checkDo(Do *v, int size) {
    Rectangle r;
    r.width = 1;
    r.height = 1;
    r.x = GetMouseX();
    r.y = GetMouseY();

    for(int i = 0; i < size; i++)
        if(CheckCollisionRecs(r, (Rectangle) {v[i].x, v[i].y,
                                              v[i].checkbox.borderTexture.width + (v[i].text.fontSize * strlen(v[i].text.string)) + (v[i].checkbox.borderTexture.height * 0.2),
                                              v[i].checkbox.borderTexture.height}))
            v[i].checkbox.isChecked = !v[i].checkbox.isChecked;
}

int main() {
    InitWindow(300, 800, "Do");

    Do *v = malloc(sizeof(Do) * 3);
    v[0] = createDo(true, "217eastbroadway", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 10, 200, 76});
    v[1] = createDo(false, "cacchio?", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 96, 200, 76});
    v[2] = createDo(true, "unchecked", "res/fonts/helvetica_neue_65.ttf", "res/textures/borderBLACK.png", "res/textures/checkmark2.png", (Rectangle) {10, 182, 200, 76});

    Text t = createText("cacchio?", "res/fonts/helvetica_neue_65.ttf", 75/2, BLACK, 0, 765);

    while(!WindowShouldClose()) {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            checkDo(v, 3);

        char* str = malloc(sizeof(char) * 16);
        sprintf(str, "x: %d, y: %d", GetMouseX(), GetMouseY());
        setText(&v[1].text, "cacchio!");

        ClearBackground(WHITE);
        BeginDrawing();

        for(int i = 0; i < 3; i++)
            renderDo(&v[i]);

        renderText(t);

        EndDrawing();
    }
}
