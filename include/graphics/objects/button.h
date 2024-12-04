#pragma once
#include <graphics/general.h>
#include <graphics/objects/text.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // Remove this.

/* --- IDEAS ---

- Darken button texture when clicked.
- Double texture: general button layout texture + icon texture

*/

typedef struct {
    char* buttonTextureFile;
    Texture2D buttonTexture;
    Text text;

    Rectangle pos;
} Button;

Button createButton(Text text, const char* buttonTextureFile, Rectangle pos);

bool isClicked(Button b);

void renderButton(Button b);