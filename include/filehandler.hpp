#pragma once
#include <stdlib.h>
#include "task.hpp"

void saveEverything(std::vector<Task> tasks);
void loadEverything(const char *fileName, std::vector<Task> &tasks);