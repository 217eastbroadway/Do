#include <objects/checkbox.h>

void initCheckbox(Checkbox *c, bool isChecked, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos) {
    c->isChecked = isChecked;
    c->borderTexture = createTexture2D(borderTextureFile);
    c->checkMarkTexture = createTexture2D(checkMarkTextureFile);

    c->borderTexture.width = pos.width;
    c->borderTexture.height = pos.height;

    c->checkMarkTexture.width = pos.width * 0.8;
    c->checkMarkTexture.height = pos.height * 0.8;

    c->pos = pos;
}

void renderCheckbox(Checkbox c) {
    DrawTexture(c.borderTexture, c.pos.x, c.pos.y, WHITE);

    if(c.isChecked)
        DrawTexture(c.checkMarkTexture, c.pos.x + c.pos.x * 0.8, c.pos.y  + c.pos.y * 0.8, WHITE);
}