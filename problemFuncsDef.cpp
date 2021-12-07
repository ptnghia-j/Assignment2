#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <mutex>
#include <iostream>
#include <sstream>
#include <vector>
#include "assignment2.h"

void *problem_1 (void *parameter) {
    /*
    This function implements first fit policy for memory allocation.
    */
    char *data = (char *) parameter;
    size_t found = std::string(data).find(",");
    if (found != std::string::npos) {
    	std::string freeMemoryInfo = std::string(data).substr(0, found);
    	std::string processesInfo = std::string(data).substr(found + 1);
    }

    std::stringstream freeMemory(data);
		
    std::vector<Block> freeMemoryList;
    std::string sizeString;
    while(freeMemory >> size) {
	int size = std::stoi(sizeString);
        if (size > 0) {
            Block block(size);
            freeMemoryList.push_back(block);
        }
    }

    std::stringstream processes(processesInfo);
    std::vector<Process> processesList;
    std::string pid;
    std::string size;
    while (processes >> pid >> size) {
	int size = std::stoi(sizeString);
        Process process(pid, size);
        processesList.push_back(process);
    }

    //for each process, find the first block that is big enough to hold it
    
    
    return NULL;
}

void *problem_2 (void *parameter) {

    return NULL;
}

void *problem_3 (void *parameter) {

    return NULL;
}


void *problem_4 (void *parameter) {

    return NULL;
}
