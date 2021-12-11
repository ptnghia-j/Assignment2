#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Solver.h"

enum Method { firstFit = 1, bestFit, worstFit };

struct memAllocationProblem {
public:
    void setMemoryAvailable(std::vector<int> memoryAvailable) {
        this->memoryAvailable = memoryAvailable;
    }
    std::vector<int> getMemoryAvailable() {
        return memoryAvailable;
    }

    void setProcesses(std::vector<int> processes) {
        this->processes = processes;
    }

    std::vector<int> getProcesses() {
        return processes;
    }

    void setMethod(Method method) {
        this->method = method;
    }

    Method getMethod() {
        return method;
    }
    
private:
    std::vector<int> memoryAvailable;
    std::vector<int> processes;
    Method method;
};

class memAllocation: Solver {
private:
    struct memAllocationProblem* problem;
public:
    memAllocation(struct memAllocationProblem &problem) {
        this->problem = &problem;
    }
    ~memAllocation() {
        // TODO Auto-generated destructor stub
    }
    std::string solve();
    void print();
};