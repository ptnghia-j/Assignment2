#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Solver.h"


struct memAllocationProblem {
public:
    void setMemoryAvailable(std::vector<int> memoryAvailable) {
        this->memoryAvailable = memoryAvailable;
    }
    std::vector<int> getMemoryAvailable() {
        return memoryAvailable;
    }

    void setProcesses(std::vector<std::pair<std::string, int>> processes) {
        this->processes = processes;
    }

    std::vector<std::pair<std::string, int>> getProcesses() {
        return processes;
    }

private:
    std::vector<int> memoryAvailable;
    std::vector<std::pair<std::string, int> > processes;
};

class memAllocation: Solver {
public:
    memAllocation(struct memAllocationProblem &problem) {
        this->problem = &problem;
    }
    ~memAllocation() {
        // TODO Auto-generated destructor stub
    }

    std::string solve();

    void print();

private:
    struct memAllocationProblem* problem;

};

