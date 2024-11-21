#include <stdio.h>
#include <raylib.h>
#include <objects/text.h>
#include <objects/checkbox.h>

int main() {
    InitWindow(300, 800, "Do");

    Text a;
    initText(&a, "checked", "res/fonts/helvetica_neue_65.ttf", 25.0f, (Color) {255, 255, 255, 255}, 100, 35);

    Text a2;
    initText(&a2, "unchecked", "res/fonts/helvetica_neue_65.ttf", 25.0f, (Color) {255, 255, 255, 255}, 100, 135);

    Text a3;
    initText(&a3, "217eastbroadway", "res/fonts/helvetica_neue_65.ttf", 25.0f, (Color) {255, 255, 255, 255}, 100, 235);

    Checkbox b;
    initCheckbox(&b, true, "res/textures/border.png", "res/textures/checkmark.png", (Rectangle) {10, 10, 75, 75});

    Checkbox c;
    initCheckbox(&c, false, "res/textures/border.png", "res/textures/checkmark.png", (Rectangle) {10, 100, 75, 75});

    while(!WindowShouldClose()) {
        BeginDrawing();

        renderText(a);
        renderText(a2);
        renderText(a3);
        renderCheckbox(b);
        renderCheckbox(c);

        EndDrawing();
    }
}
