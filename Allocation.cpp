//#include <sys/types.h>
//#include <sys/wait.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <string.h>
//#include <pthread.h>
//#include <stdlib.h>
//#include <mutex>
#include <iostream>
#include <sstream>
#include <vector>

#include "Allocation.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

std::string solveFirstFit(std::vector<int> availableBlock, std::vector<int> processList) {
    /*
    First fit policy: search for the first available block that is large enough to hold the process.
    */

    std::string result;
    for (int i = 0; i < processList.size(); i++) {
        int processSize = processList[i];

        int index = 0;
        bool isFound = false;
        while (!isFound && index < availableBlock.size()) {
            availableBlock[index] >= processSize ? isFound = true : index++;
        }

        if (isFound) {
            // result += "Process with size of " + std::to_string(processSize) 
            //         + " is allocated to block " + std::to_string(index) + "\n";
            
            availableBlock[index] -= processSize;
            // result += "Remaining memory for block " + std::to_string(index) + ": " + std::to_string(availableBlock[index]) + "\n";
        } else {
            // result += " Found no block large enough to hold process with size of " + std::to_string(processSize) 
            //         + " under first fit policy \n";
        }
    }

    int totalFreeRemaining = 0;
    for (auto size : availableBlock)
    {
        totalFreeRemaining += size;
    }
    result += ("First fit solver finished.\nTotal memory remaining: " + std::to_string(totalFreeRemaining) + "\n\n");
    return result;
}

std::string solveBestFit(std::vector<int> availableBlock, std::vector<int> processList) {
    /*
    Best fit policy: search for the smallest available block that is large enough to hold the process.
    */

    std::string result;
    for (int i = 0; i < processList.size(); i++) {
        int processSize = processList[i];

        int index = 0;
        int minIndex = -1;
        int minSize = processList[0];
        while (index < availableBlock.size()) {
            if (availableBlock[index] >= processSize && availableBlock[index] < minSize) {
                minIndex = index;
                minSize = availableBlock[index];
            }
            index++;
        }

        if (minIndex != -1 && minSize != 0) {
            result += "Process with size of " + std::to_string(processSize) 
                    + " is allocated to block " + std::to_string(index) + "\n";
            
            availableBlock[minIndex] -= processSize;
            result += "Remaining memory for block " + std::to_string(minIndex) + ": " + std::to_string(availableBlock[minIndex]) + "\n";
        } 
        else {
            result += " Found no block large enough to hold process with size of " + std::to_string(processSize) 
                    + " \n under best fit policy \n";
        }

    }

    int totalFreeRemaining = 0;
    for (auto size : availableBlock)
    {
        totalFreeRemaining += size;
    }
    result += ("Best fit solver finished.\nTotal memory remaining: " + std::to_string(totalFreeRemaining) + "\n\n");
    return result;
}

std::string solveWorstFit(std::vector<int> availableBlock, std::vector<int> processList) {
    /*
    Worst fit policy: search for the largest available block that is large enough to hold the process.
    */
    
    std::string result;

    for (int i = 0; i < processList.size(); i++) {
        int processSize = processList[i];

        int index = 0;
        int maxIndex = -1;
        int maxSize = 0;
        while (index < availableBlock.size()) {
            if (availableBlock[index] >= processSize && availableBlock[index] > maxSize) {
                maxIndex = index;
                maxSize = availableBlock[index];
            }
            index++;
        }

        if (maxIndex != -1 && maxSize != 0) {
            // result += "Process with size of " + std::to_string(processSize) 
            //         + " is allocated to block " + std::to_string(index) + "\n";
            
            availableBlock[maxIndex] -= processSize;
            // result += "Remaining memory for block " + std::to_string(maxIndex) + ": " + std::to_string(availableBlock[maxIndex]) + "\n";
        } 
        else {
            // result += " Found no block large enough to hold process with size of " + std::to_string(processSize) 
            //         + " \n under worst fit policy \n";
        }
    }

    int totalFreeRemaining = 0;
    for (auto size : availableBlock)
    {
        totalFreeRemaining += size;
    }
    result += ("Worst fit solver finished.\nTotal memory remaining: " + std::to_string(totalFreeRemaining) + "\n\n");
    return result;
}

std::string memAllocation::solve() {

    // std::cout << "Solving Policy ... " << std::endl;
    // std::cout << "1. First Fit" << std::endl;
    // std::cout << "2. Best Fit" << std::endl;
    // std::cout << "3. Worst Fit" << std::endl;

    // std::cout << "Enter your choice: ";
    // int choice;
    // std::cin >> choice;

    std::string result;

    bool isDone = false;
    while (!isDone) {

        std::vector<int> availableBlock = problem->memoryAvailable;
        std::vector<int> processList = problem->processes;


        //show the size of current available memory and the process list with processes' size
        // std::cout << GREEN << "Available Memory: " << RESET << std::endl;
        // for (int i = 0; i < availableBlock.size(); i++) {
        //     std::cout << i << ". " << availableBlock[i] << std::endl;
        // }
        // std::cout << "===============================================" << std::endl;

        // std::cout << GREEN << "Process List: " << RESET << std::endl;
        // for (int i = 0; i < processList.size(); i++) {
        //     std::cout << i << ". Pid: " << processList[i].first << " Memory needed: " << processList[i].second << std::endl;
        // }
        // std::cout << "===============================================" << std::endl;


        // std::cout << "Solving by method " << problem->method << std::endl;
        switch(problem->method) {
            case firstFit: result = solveFirstFit(availableBlock, processList);
                    break;
            case bestFit: result = solveBestFit(availableBlock, processList);
                    break;
            case worstFit: result = solveWorstFit(availableBlock, processList);
                    break;
            default:
                return "Tried to solve by nonexistent method.";
        }

    return result;

    }
}

