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

class	translation: Solver {
public:
	translation(struct translationProblem &problem){
		this-> problem = &problem;
	}

	~translation(){
		//Todo
	}

	string solve();

	void print();

private:
	struct translationProblem* problem;

};
