#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Solver.h"

enum Method { firstFit = 1, bestFit, worstFit };

struct memAllocationProblem {
    std::vector<int> memoryAvailable;
    std::vector<int> processes;
    Method method;
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

