#pragma once
#include <graphics/general.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/text.h>

#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // Remove this.

typedef struct {
    Checkbox checkbox;
    Text text;

    int x;
    int y;
} Do;

Do createDo(bool isChecked, const char* doText, const char* fontFile, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos);

void renderDo(Do* d);