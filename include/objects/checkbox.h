#pragma once
#include <objects/general.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // Remove this.

/* --- IDEAS ---

- invert the texture color of the checkbox against the background one. (1:1 contrast)
*/

typedef struct {
    bool isChecked;

    Texture2D borderTexture;
    Texture2D checkMarkTexture;
    Rectangle pos;
} Checkbox;

void initCheckbox(Checkbox *c, bool isChecked, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos);

void renderCheckbox(Checkbox c);