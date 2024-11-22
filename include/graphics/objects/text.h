#pragma once
#include <graphics/general.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // Remove this.

typedef struct {
    char* string;
    Font font;
    float fontSize;
    Color textColor;

    int x;
    int y;
} Text;

Text createText(const char* string, const char* fontFile, float fontSize, Color textColor, int x, int y);

void setText(Text *t, const char* string);

void renderText(Text t);