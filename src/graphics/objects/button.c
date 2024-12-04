#include <graphics/objects/button.h>

Button createButton(Text text, const char* buttonTextureFile, Rectangle pos) {
    Button b;

    b.buttonTextureFile = (char*)malloc((sizeof(char) * strlen(buttonTextureFile)) + (sizeof(char) * 1));
    strcpy(b.buttonTextureFile, buttonTextureFile);
    
    b.buttonTexture = createTexture2D(buttonTextureFile);

    b.buttonTexture.width = pos.width;
    b.buttonTexture.height = pos.height;   

    b.text = createText(text.string, "?", pos.height - strlen(text.string), WHITE, pos.x, pos.y);
    b.text.font = text.font;

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
    renderText(b.text);
}