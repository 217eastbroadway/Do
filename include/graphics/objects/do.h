#pragma once
#include <graphics/general.h>
#include <graphics/objects/checkbox.h>
#include <graphics/objects/text.h>
#include <graphics/objects/button.h>

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

void checkToDo(Do *d);

void createDoDialog(Do** v, int *size);

void deleteDoDialog(Do** v, int *size);

void renderDo(Do* d);