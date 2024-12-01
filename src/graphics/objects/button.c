#include <graphics/objects/button.h>

Button createButton(const char* buttonTextureFile, Rectangle pos) {
    Button b;
    b.buttonTexture = createTexture2D(buttonTextureFile);

    b.buttonTexture.width = pos.width;
    b.buttonTexture.height = pos.height;   

    b.pos = pos;

    return b;
}

bool isClicked(Button b) {
    Rectangle r;
    r.width = 1;
    r.height = 1;
    r.x = GetMouseX();
    r.y = GetMouseY();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
       CheckCollisionRecs(r, (Rectangle) {b.pos.x, b.pos.y,
                                          b.buttonTexture.width,
                                          b.buttonTexture.height}))
            return true;

    return false;
}

void renderButton(Button b) {
    DrawTexture(b.buttonTexture, b.pos.x, b.pos.y, WHITE);
}