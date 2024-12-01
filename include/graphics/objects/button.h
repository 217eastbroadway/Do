#pragma once
#include <graphics/general.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // Remove this.

/* --- IDEAS ---

- Darken button texture when clicked.
- Double texture: general button layout texture + icon texture

*/

typedef struct {
    Texture2D buttonTexture;
    Rectangle pos;
} Button;

Button createButton(const char* buttonTextureFile, Rectangle pos);

bool isClicked(Button b);

void renderButton(Button b);