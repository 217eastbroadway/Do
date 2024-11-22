#pragma once
#include <graphics/general.h>
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

Text createText(const char* string, const char* fontFile, float fontSize, Color textColor, int x, int y);

void renderText(Text t);