#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "Solver.h"
using namespace std;

struct translationProblem {
	int segmentId, logicalAddress, physicalAddress;
	int base[3] = {200, 2300, 1200};
	int length[3] = {600, 20, 100};
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
