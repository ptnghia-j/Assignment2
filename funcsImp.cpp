#include "assignment2.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

//Implementation for functions of struct Process
Process::Process(std::string pid, int neededMemory): 
				Id(pid), size(neededMemory) {}
				
std::string Process::getPid() { 
	return Id; 
}

int Process::getNeededMemory() { 
	return size; 
}

int Process::getAllocatedBlockNumber() { 
	return allocatedBlockNumber;; 
}


void Process::setAllocatedBlockNumber(int blockNumber) {
	allocatedBlockNumber = blockNumber;
}

//Implementation for functions of struct Block
Block::Block(int blockSize): 
            size(blockSize) {}

int Block::getSize() { 
    return size; 
}

int Block::getAllocationCount(){
    return count;
}
        
void Block::setAllocationCount(int allocationCount) {
    count = allocationCount;
}
        
void Block::insertProcess(Process* process) {
    allocatedProcesses.push_back(std::make_pair(process->getPid(), process->getNeededMemory()));
}
