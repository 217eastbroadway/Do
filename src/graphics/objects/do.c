#include <graphics/objects/do.h>

Do createDo(bool isChecked, const char* doText, const char* fontFile, const char* borderTextureFile, const char* checkMarkTextureFile, Rectangle pos) {
    Do d;

    d.x = pos.x;
    d.y = pos.y;

    d.checkbox = createCheckbox(isChecked,
                                borderTextureFile,
                                checkMarkTextureFile,
                                (Rectangle) {pos.x, pos.y, pos.height, pos.height});

    d.text = createText(doText,
                        fontFile,
                        GetScreenWidth() / strlen(doText),
                        BLACK,
                        pos.x + pos.height + pos.height * 0.2,
                        pos.y + (pos.height / 2));

    return d;
}

void deleteDo(Do** v, int index, int *size) {
    if((*size) < 2) {
        *v = NULL;
        *size = 0;
        return;
    }

    for(int i = index; i < (*size) - 2; i++)
        *v[i] = *v[i+1];

    *(size)--;

    // printf("<ineedadebugger>\n");
    // for(int i = 0; i < (*size); i++)
    //     printf("%s", *v[i]->text.string);
    // WaitTime(3);
}

void checkToDo(Do *d) {
    Rectangle r;
    r.width = 1;
    r.height = 1;
    r.x = GetMouseX();
    r.y = GetMouseY();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
       CheckCollisionRecs(r, (Rectangle) {d->x, d->y,
                                          d->checkbox.borderTexture.width + 
                                          (d->text.fontSize * strlen(d->text.string)) + 
                                          (d->checkbox.borderTexture.height * 0.2),
                                          d->checkbox.borderTexture.height}))
            d->checkbox.isChecked = !d->checkbox.isChecked;
}

void createDoDialog(Do** v, int *size) {
    Rectangle container = {15, 240, 270, 165};
    Text header = createText("New Task", "res/fonts/helvetica_neue_65.ttf", 40.0f, BLACK, 25, 250);
    Text description = createText("Enter task name: ", "res/fonts/helvetica_neue_65.ttf", 25.0f, BLACK, 25, 300);
    Text text = createText("", "res/fonts/helvetica_neue_65.ttf", 30.0f, WHITE, 30, 335);
    Rectangle textbox = {25, 330, 250, 35};
    Button cancel = createButton(createText("Cancel", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), 
                                 "res/textures/btncancel.png", 
                                 (Rectangle) {25, 370, 122, 30});

    Button confirm = createButton(createText("Confirm", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), 
                                 "res/textures/btnconfirm.png", 
                                 (Rectangle) {152, 370, 122, 30});

    bool end = false;
    while(!end) {
        if(WindowShouldClose())
            exit(0);

        ClearBackground(WHITE);
        BeginDrawing();

        //Input
        int key;
        char c;
        do {
            key = GetKeyPressed();
            c = (char)GetCharPressed();

            if(key == KEY_ESCAPE || isClicked(confirm)) {
                end = true;
                break;
            }

            char* str = (char*)malloc((sizeof(char) * strlen(text.string)) + (sizeof(char) * 2));
            strcpy(str, text.string);
            key == KEY_BACKSPACE ? str[strlen(str) - 1] = 0 : sprintf(str, "%s%c", text.string, c);
            setText(&text, str);
        }while(key > 0);
        
        //Rendering
        DrawRectangle(container.x, container.y, container.width, container.height, LIGHTGRAY);

        renderText(header);
        renderText(description);
        
        DrawRectangle(textbox.x, textbox.y, textbox.width, textbox.height, BLUE);
        renderText(text);

        renderButton(cancel);
        renderButton(confirm);

        EndDrawing();
    }

    Do* vCopy = (Do*)malloc(sizeof(Do) * (++(*size)));
    if(!vCopy)
        exit(1);

    if((*size) > 1) {
        memcpy(vCopy, *v, sizeof(Do) * ((*size) - 1));

        vCopy[(*size) - 1] = createDo(false, text.string, "res/fonts/helvetica_neue_65.ttf", 
                                    "res/textures/borderBLACK.png", "res/textures/checkmark2.png", 
                                    (Rectangle) {vCopy[(*size) - 2].x, vCopy[(*size) - 2].y + 86, 200, 70});
    }
    else vCopy[(*size) - 1] = createDo(false, text.string, "res/fonts/helvetica_neue_65.ttf", 
                                       "res/textures/borderBLACK.png", "res/textures/checkmark2.png", 
                                        (Rectangle) {10, 85, 200, 70});

    *v = vCopy;


    for(int i = 0; i < *size; i++)
        printf("<ineedadebugger> %d @ %p\n", i, &(*v[i]));

    WaitTime(0.3);
}

void deleteDoDialog(Do** v, int *size) {
    Button doneButton = createButton(createText("Done", "res/fonts/helvetica_neue_65.ttf", 35.0f, WHITE, 0, 0), 
                                       "res/textures/buttonaqua.png", 
                                       (Rectangle) {250, 750, 35, 35});

    Text header = createText("Delete Task", "res/fonts/helvetica_neue_65.ttf", 50.0f, RED, 10, 10);
    Rectangle breakline = {10, 65, 280, 1};

    bool end = false;
    while(!end) {
        if(WindowShouldClose())
            exit(0);

        // Input checking
        if(isClicked(doneButton)) 
            end = true;

        Rectangle r;
        r.width = 1;
        r.height = 1;
        r.x = GetMouseX();
        r.y = GetMouseY();
        int i = 5;
        for(; i < (*size); i++) {
            if(CheckCollisionRecs(r, (Rectangle) {(*v[i]).checkbox.pos.x, (*v[i]).checkbox.pos.y,
                                                  (*v[i]).checkbox.borderTexture.width + (*v[i]).checkbox.borderTexture.width * 0.2 + MeasureText((*v[i]).text.string, (*v[i]).text.fontSize),
                                                  (*v[i]).checkbox.borderTexture.height})) {
                                                    printf("<ineedadebugger> FOUND ONE!\n");
                                                    break;
                                                  }
        }

        Button hoveredTaskButton;
        if(i < (*size)) {
            hoveredTaskButton = createButton(createText("", "res/fonts/helvetica_neue_65.ttf", 35.0f, BLACK, 0, 0), 
                                                        "res/textures/btnred.png", 
                                                        (Rectangle) {(*v[i]).checkbox.pos.x, (*v[i]).checkbox.pos.y,
                                                        (*v[i]).checkbox.borderTexture.width + (*v[i]).checkbox.borderTexture.width * 0.2 + MeasureText((*v[i]).text.string, (*v[i]).text.fontSize),
                                                        (*v[i]).checkbox.borderTexture.height});
            
            if(isClicked(hoveredTaskButton)) {
                printf("<ineedadebugger> deleted %i\n", i);
                deleteDo(v, i, size);
                // WaitTime(1);
            }
        }

        //Rendering
        ClearBackground(WHITE);
        BeginDrawing();

        // underlay to hovered task
        if(i < (*size))
            renderButton(hoveredTaskButton);
        
        // Tasks (DOs)
        for(int i = 0; i < (*size); i++)
            renderDo(&(*v[i]));

        renderText(header);
        renderButton(doneButton);
        DrawRectangle(breakline.x, breakline.y, breakline.width, breakline.height, BLACK);
        EndDrawing();
    }
}

void renderDo(Do* d) {
    renderCheckbox(d->checkbox);
    renderText(d->text);
}
