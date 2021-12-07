#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Process {
	public: 
		std::string getPid();
		int getNeededMemory();

        //Helper functions
        int getAllocatedBlockNumber();
        void setAllocatedBlockNumber(int blockNumber);
		
		// Constructor
		Process(std::string pid, int neededMemory);
		
	private: 
		std::string Id = "";
		int size = 0;
		int allocatedBlockNumber = 0;
};

struct Block {
    public: 
        int getSize();
        int getAllocationCount();
        void setAllocationCount(int allocationCount);
        void insertProcess(Process* process);

        // Constructor
        Block(int blockSize);


    private: 
        int size = 0;
        int count = 0;
        std::vector<std::pair<std::string, int>> allocatedProcesses;

};

//void showRAM(std::vector );

void *problem_1 (void *parameter);
void *problem_2 (void *parameter);
void *problem_3 (void *parameter);
void *problem_4 (void *parameter);


