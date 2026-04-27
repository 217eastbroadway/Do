#include "filehandler.hpp"

void saveEverything(std::vector<Task> tasks) {
    FILE *file = fopen("save.dorec", "w");

    if(file == NULL)
        exit(1);

    //Debug Print
    std::cout << "[DEBUG] >> saveEverything::Saving...\n";

    for(Task task : tasks) {
        fprintf(file, "%s %s %d %d %d %d %d\n", 
                                            task.getName(),
                                            task.getDescription(),
                                            task.getIsChecked(),
                                            task.getBgColor().r,
                                            task.getBgColor().g,
                                            task.getBgColor().b,
                                            task.getBgColor().a);
    }

    //Debug Print
    std::cout << "[DEBUG] >> saveEverything::Done!\n";

    fclose(file);
}

void loadEverything(const char *fileName, std::vector<Task> &tasks) {
    tasks.clear(); //Removing anything from tasks array
    FILE *file = fopen("save.dorec", "r"); //Opening file

    if(file == NULL) //Checking file ptr
        exit(1); //Couldn't open file, crash.

    //Debug Print
    std::cout << "[DEBUG] >> loadEverything::Loading...\n";


    //TODO: clean up (no char* bs, only std::string)
    // std::string name, description;
    char *name, *description;
    name = (char*)calloc(128, sizeof(char));
    description = (char*)calloc(128, sizeof(char));
    int isChecked;
    Color color;

    //TODO: fix bool scanning (for some reason it always reads it as 0 [why?])
    while(fscanf(file, "%s %s %d %d %d %d %d", 
                                            name,
                                            description,
                                            &isChecked,
                                            &color.r,
                                            &color.g,
                                            &color.b,
                                            &color.a) == 7) {
        std::cout << "[DEBUG] >> loadEverything::isChecked = " << isChecked << '\n';
        tasks.push_back(Task((const char*)name, (const char*)description, (bool)isChecked, color));
    }

    //Debug Print
    std::cout << "[DEBUG] >> loadEverthing::tasks.size() = " << tasks.size() << '\n';
    std::cout << "[DEBUG] >> loadEverything::Done!\n\n";

    fclose(file);
}