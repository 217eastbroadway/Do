#include <graphics/objects/text.h>

Text createText(const char* string, const char* fontFile, float fontSize, Color textColor, int x, int y) {
    Text t;
    
    t.fontFile = (char*)malloc((sizeof(char) * strlen(fontFile)) + (sizeof(char) * 1));
    strcpy(t.fontFile, fontFile);
    
    t.font = createFont(fontFile);
    
    t.string = (char*)malloc(sizeof(char) * strlen(string) + 1);
    strcpy(t.string, string);

    t.fontSize = fontSize;
    t.textColor = textColor;

    t.x = x;
    t.y = y;

    return t;
}

void setText(Text *t, const char* string) {
    t->string = (char*)malloc(sizeof(char) * strlen(string) + 1);
    strcpy(t->string, string);
}

void renderText(Text t) {
    DrawTextEx(t.font, t.string, (Vector2){t.x, t.y}, t.fontSize, 0, t.textColor);
}