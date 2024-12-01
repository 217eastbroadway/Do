#include <graphics/objects/do.h>

Do createDo(bool isChecked, const char* doText, const char* fontFile, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos) {
    Do d;

    d.x = pos.x;
    d.y = pos.y;

    d.checkbox = createCheckbox(isChecked,
                                borderTextureFile,
                                checkMarkTextureFile,
                                (Rectangle) {pos.x, pos.y, pos.height, pos.height});

    d.text = createText(doText,
                        fontFile,
                        GetScreenWidth() / strlen(doText),
                        BLACK,
                        pos.x + pos.height + pos.height * 0.2,
                        pos.y + (pos.height / 2));

    return d;
}

void checkToDo(Do *d) {
    Rectangle r;
    r.width = 1;
    r.height = 1;
    r.x = GetMouseX();
    r.y = GetMouseY();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
       CheckCollisionRecs(r, (Rectangle) {d->x, d->y,
                                          d->checkbox.borderTexture.width + 
                                          (d->text.fontSize * strlen(d->text.string)) + 
                                          (d->checkbox.borderTexture.height * 0.2),
                                          d->checkbox.borderTexture.height}))
            d->checkbox.isChecked = !d->checkbox.isChecked;
}


void renderDo(Do* d) {
    renderCheckbox(d->checkbox);
    renderText(d->text);
}
