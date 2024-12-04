#include <graphics/general.h>

Font createFont(const char* fontFile, float fontSize) {
    Font temp = LoadFontEx(fontFile, fontSize, 0, 0);
    SetTextureFilter(temp.texture, TEXTURE_FILTER_TRILINEAR);

    return temp;
}

Texture2D createTexture2D(const char* textureFile) {
    return LoadTexture(textureFile);
}