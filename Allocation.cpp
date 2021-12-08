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
#include "allocationClass.cpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

std::string memAllocation::solve() {

    std::cout << "Solving Policy ... " << std::endl;
    std::cout << "1. First Fit" << std::endl;
    std::cout << "2. Best Fit" << std::endl;
    std::cout << "3. Worst Fit" << std::endl;

    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    std::string result;

    bool isDone = false;
    while (!isDone) {

        std::vector<int> availableBlock = problem->getMemoryAvailable();
        std::vector<std::pair<std::string, int>> processList = problem->getProcesses();


        //show the size of current available memory and the process list with processes' size
        std::cout << GREEN << "Available Memory: " << RESET << std::endl;
        for (int i = 0; i < availableBlock.size(); i++) {
            std::cout << i << ". " << availableBlock[i] << std::endl;
        }
        std::cout << "===============================================" << std::endl;

        std::cout << GREEN << "Process List: " << RESET << std::endl;
        for (int i = 0; i < processList.size(); i++) {
            std::cout << i << ". Pid: " << processList[i].first << " Memory needed: " << processList[i].second << std::endl;
        }
        std::cout << "===============================================" << std::endl;


        switch(choice) {
        case 1: result = firstFit(availableBlock, processList);
                break;
        case 2: result = bestFit(availableBlock, processList);
                break;
        case 3: result = worstFit(availableBlock, processList);
                break;
        default:
            std::cout << "Invalid Choice. Please reselect from 1-3" << std::endl;
    }

        std::cout << "Continue with other allocating policies? (y/n)\n";
        std::string answer;
        std::cin >> answer;
        isDone = (answer == "n");
    }

    return result;

}


std::string firstFit(std::vector<int> availableBlock, std::vector<std::pair<std::string, int>> processList) {
    /*
    First fit policy: search for the first available block that is large enough to hold the process.
    */

    std::string result;
    for (int i = 0; i < processList.size(); i++) {
        std::string processName = processList[i].first;
        int processSize = processList[i].second;

        int index = 0;
        bool isFound = false;
        while (!isFound && index < availableBlock.size()) {
            availableBlock[index] >= processSize ? isFound = true : index++;
        }

        if (isFound) {
            result += processName + " with size of " + std::to_string(processSize) 
                    + " is allocated to block " + std::to_string(index) + "\n";
            
            availableBlock[index] -= processSize;
            result += "Remaining memory for block " + std::to_string(index) + ": " + std::to_string(availableBlock[index]) + "\n";
        } else {
            result += " Found no block large enough to hold "  + processName + " with size of " + std::to_string(processSize) 
                    + " under first fit policy \n";
        }
    }

    return result;
}

std::string bestFit(std::vector<int> availableBlock, std::vector<std::pair<std::string, int>> processList) {
    /*
    Best fit policy: search for the smallest available block that is large enough to hold the process.
    */

    std::cout << "Best Fit ...." << std::endl;

    std::string result;
    for (int i = 0; i < processList.size(); i++) {
        std::string processName = processList[i].first;
        int processSize = processList[i].second;

        int index = 0;
        int minIndex = -1;
        int minSize = 0;
        while (index < availableBlock.size()) {
            if (availableBlock[index] >= processSize && availableBlock[index] < minSize) {
                minIndex = index;
                minSize = availableBlock[index];
            }
            index++;
        }

        if (minIndex != -1 && minSize != 0) {
            result += processName + " with size of " + std::to_string(processSize) 
                    + " is allocated to block " + std::to_string(index) + "\n";
            
            availableBlock[minIndex] -= processSize;
            result += "Remaining memory for block " + std::to_string(minIndex) + ": " + std::to_string(availableBlock[minIndex]) + "\n";
        } 
        else {
            result += " Found no block large enough to hold "  + processName + " with size of " + std::to_string(processSize) 
                    + " \n under best fit policy \n";
        }

    }

    return result;
}

std::string worstFit(std::vector<int> availableBlock, std::vector<std::pair<std::string, int>> processList) {
    /*
    Worst fit policy: search for the largest available block that is large enough to hold the process.
    */
    
    std::cout << "Worst Fit ...." << std::endl;
    std::string result;

    for (int i = 0; i < processList.size(); i++) {
        std::string processName = processList[i].first;
        int processSize = processList[i].second;

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
            result += processName + " with size of " + std::to_string(processSize) 
                    + " is allocated to block " + std::to_string(index) + "\n";
            
            availableBlock[maxIndex] -= processSize;
            result += "Remaining memory for block " + std::to_string(maxIndex) + ": " + std::to_string(availableBlock[maxIndex]) + "\n";
        } 
        else {
            result += " Found no block large enough to hold "  + processName + " with size of " + std::to_string(processSize) 
                    + " \n under worst fit policy \n";
        }
    }

    return result;
}