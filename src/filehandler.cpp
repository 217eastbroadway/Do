#include "filehandler.hpp"

void saveEverything(const char *fileName, std::vector<Task> tasks) {
    FILE *file = fopen(fileName, "w");

    if(file == NULL)
        exit(1);

    //Debug Print
    std::cout << "[DEBUG] >> saveEverything::Saving...\n";

    for(Task task : tasks) {
        fprintf(file, "%s %s %d %hhu %hhu %hhu %hhu\n", 
                                            task.getName(),
                                            task.getDescription(),
                                            task.getIsChecked(),
                                            task.getBgColor().r,
                                            task.getBgColor().g,
                                            task.getBgColor().b,
                                            task.getBgColor().a);
    }

    //Debug Print
    std::cout << "[DEBUG] >> saveEverything::Done!\n\n";

    fclose(file);
}

void loadEverything(const char *fileName, std::vector<Task> &tasks) {
    tasks.clear(); //Removing anything from tasks array
    FILE *file = fopen(fileName, "r"); //Opening file

    if(file == NULL) //Checking file ptr
        exit(1); //Couldn't open file, crash.

    //Debug Print
    std::cout << "[DEBUG] >> loadEverything::Loading...\n";

    //TODO: clean up (no char* bs, only std::string)
    // std::string name, description;
    char *name = (char*)calloc(128, sizeof(char));
    char *description = (char*)calloc(128, sizeof(char));
    int isChecked;
    Color color;
    
    while(fscanf(file, "%s %s %d %hhu %hhu %hhu %hhu", 
                                            name,
                                            description,
                                            &isChecked,
                                            &color.r,
                                            &color.g,
                                            &color.b,
                                            &color.a) == 7) {
        tasks.push_back(Task((const char*)name, (const char*)description, (bool)isChecked, color));
    }

    //Debug Print
    std::cout << "[DEBUG] >> loadEverything::Done!\n\n";

    fclose(file);
}