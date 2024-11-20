#include <objects/general.h>

Font createFont(const char* fontFile) {
    Font temp = LoadFont(fontFile);
    // SetTextureFilter(temp.texture, TEXTURE_FILTER_TRILINEAR);

    return temp;
}

Texture2D createTexture2D(const char* textureFile) {
    return LoadTexture(textureFile);
}