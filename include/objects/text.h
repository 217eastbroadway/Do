#pragma once
#include <objects/general.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // Remove this.

typedef struct {
    const char* string;
    Font font;
    float fontSize;
    Color textColor;

    int x;
    int y;
} Text;

void initText(Text* t, const char* string, const char* fontFile, float fontSize, Color textColor, int x, int y);

void renderText(Text t);