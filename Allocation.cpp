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
            availableBlock[index] -= processSize;
        }
        else {
            result += " Found no block large enough to hold process with size of " + std::to_string(processSize) 
                    + " \n under first fit policy \n";
        }
    }

    int totalFreeRemaining = 0;
    for (auto size : availableBlock)
    {
        totalFreeRemaining += size;
    }
    return "First fit solver finished.\nTotal memory remaining: " + std::to_string(totalFreeRemaining);
}

std::string solveBestFit(std::vector<int> availableBlock, std::vector<int> processList) {
    /*
    Best fit policy: search for the smallest available block that is large enough to hold the process.
    */

    std::string result;
    for (int i = 0; i < processList.size(); i++) {
        int processSize = processList[i];

        int index = 0;
        int minIndex = 0;
        int minSize = processList[0];
        while (index < availableBlock.size()) {
            if (availableBlock[index] >= processSize && availableBlock[index] < minSize) {
                minIndex = index;
                minSize = availableBlock[index];
            }
            index++;
        }

        if (minSize != 0) {
            availableBlock[minIndex] -= processSize;
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
    return "Best fit solver finished.\nTotal memory remaining: " + std::to_string(totalFreeRemaining);
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
            availableBlock[maxIndex] -= processSize;
        } 
        else {
            result += " Found no block large enough to hold process with size of " + std::to_string(processSize) 
                    + " \n under worst fit policy \n";
        }
    }

    int totalFreeRemaining = 0;
    for (auto size : availableBlock)
    {
        totalFreeRemaining += size;
    }
    return "Worst fit solver finished.\nTotal memory remaining: " + std::to_string(totalFreeRemaining);
}

std::string memAllocation::solve() {
    std::string result;

    bool isDone = false;
    while (!isDone) {
        std::vector<int> availableBlock = problem->getMemoryAvailable();
        std::vector<int> processList = problem->getProcesses();


        switch(problem->getMethod()) {
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