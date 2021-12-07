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

/*
 * Function: main
 * ----------------
 * This is the main function of the program.
 * It takes in the command line arguments and calls the appropriate functions in order
 * to execute the commands.
 */


int main(){
    bool isDone = false;
    //create an array of function pointers to store 4 functions to be called by the threads
    void *(*function_pointer[4]) (void *) = {problem_1, problem_2, problem_3, problem_4};

    std::cout << "Assignment 2 ...." << std::endl;

    while (!isDone) {

        //collecting data from command line
        pthread_t thread;
        int problemNumber = 1;
        std::cout << "Which problem would you like to solve?\n";
        std::cin >> problemNumber;

        //collect free memory information
        std::string freeMemoryInfo = "";

        int numBlocks = 0;
        std::cout << "How many available blocks in the RAM?\n";
        std::cin >> numBlocks;
        freeMemoryInfo += std::to_string(numBlocks) + " ";
        std::cout << "Enter information for the available blocks in the RAM\n";

        for (int i = 0; i < numBlocks; i++) {
            std::cout << "Enter size of block " << i << " and hit enter ";
            int size = 0;

            std::cin >> size;
            freeMemoryInfo += (i == (numBlocks - 1)) ? std::to_string(size) : std::to_string(size) + " ";
        }
        //append a comma to the end of freeMemoryInfo to separate with info for processes
        freeMemoryInfo += ",";

        //collect processes information
        std::string processesInfo = "";
        
        int numProcesses = 0;
        std::cout << "How many processes?\n";
        std::cin >> numProcesses;
        std::cout << "Enter information for processes\n";

        for (int i = 0; i < numProcesses; i++) {
            std::cout << "Enter pid and size of process " << i << " with a space in between and hit enter ";
            std::string pid;
            int size = 0;

            std::cin >> pid >> size;
            processesInfo += (i == (numProcesses - 1)) ? (pid + " " + std::to_string(size)) 
                            : pid + " " + std::to_string(size) + " ";
            
        }

        std::string passedData = freeMemoryInfo + processesInfo;


        if (pthread_create(&thread, NULL, function_pointer[problemNumber], (void *)passedData.data()) != 0) {
                printf("Error creating thread\n");
                exit(1);
        }
        
        if(pthread_join(thread, NULL)!=0){
                perror("Error joining thread");
                exit(-1);
        }

        std::cout << "This is data passed to the thread: " << passedData << std::endl;

        std::cout << "Would you like to solve another problem? (y/n)\n";
        std::string answer;
        std::cin >> answer;
        isDone = (answer == "n");

        
    }

    
    
}




