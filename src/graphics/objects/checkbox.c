#include <graphics/objects/checkbox.h>

Checkbox createCheckbox(bool isChecked, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos) {
    Checkbox c;
    c.isChecked = isChecked;
    c.borderTexture = createTexture2D(borderTextureFile);
    c.checkMarkTexture = createTexture2D(checkMarkTextureFile);

    c.borderTexture.width = pos.width;
    c.borderTexture.height = pos.height;

    c.checkMarkTexture.width = pos.width * 0.8;
    c.checkMarkTexture.height = pos.height * 0.8;

    c.pos = pos;
    
    return c;
}

void renderCheckbox(Checkbox c) {
    DrawTexture(c.borderTexture, c.pos.x, c.pos.y, WHITE);

    if(c.isChecked)
        DrawTexture(c.checkMarkTexture, c.pos.x + (c.borderTexture.width - c.checkMarkTexture.width) / 2, c.pos.y  + (c.borderTexture.height - c.checkMarkTexture.height) / 2, WHITE);
}