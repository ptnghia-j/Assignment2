#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "Solver.h"
using namespace std;

struct translationProblem {
private:
	int segmentId, logicalAddress;
public:
	const int base[3] = {200, 2300, 1200};
	const int length[3] = {600, 20, 100};
	int getSegmentID(){
		return segmentId;
	}
	int getLogicalAddress(){
		return logicalAddress;
	}
	int setSegmentID(int newId){
		segmentId = newId;
	}
	int setLogicalAddress(int newAddr){
		logicalAddress = newAddr;
	}
};

class translation: Solver {
private:
	struct translationProblem* problem;
public:
	translation(struct translationProblem &problem){
		this-> problem = &problem;
	}
	string solve();
	void print();
};
