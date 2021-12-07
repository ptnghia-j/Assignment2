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
    std::cout << "Problem 1" << std::endl;
    std::cout << "Received data: " << (char *) parameter << std::endl;
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
