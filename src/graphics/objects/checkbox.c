#include <graphics/objects/checkbox.h>

Checkbox createCheckbox(bool isChecked, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos) {
    Checkbox c;
    c.isChecked = isChecked;
    c.borderTexture = createTexture2D(borderTextureFile);
    c.checkMarkTexture = createTexture2D(checkMarkTextureFile);

    c.borderTexture.width = pos.width;
    c.borderTexture.height = pos.height;

    //Inner texture
    c.checkMarkTexture.width = pos.width * 0.8;
    c.checkMarkTexture.height = pos.height * 0.8;

    c.pos = pos;
    
    return c;
}

//Checks if mouse is trying to checkmark the checkbox
void checkToCheck(Checkbox *c) {
    Rectangle r;
    r.width = 1;
    r.height = 1;
    r.x = GetMouseX();
    r.y = GetMouseY();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
       CheckCollisionRecs(r, (Rectangle) {c->pos.x, c->pos.y,
                                          c->borderTexture.width,
                                          c->borderTexture.height}))
            c->isChecked = !c->isChecked;
}

void renderCheckbox(Checkbox c) {
    DrawTexture(c.borderTexture, c.pos.x, c.pos.y, WHITE);

    if(c.isChecked)
        DrawTexture(c.checkMarkTexture, c.pos.x + (c.borderTexture.width - c.checkMarkTexture.width) / 2, c.pos.y  + (c.borderTexture.height - c.checkMarkTexture.height) / 2, WHITE);
}