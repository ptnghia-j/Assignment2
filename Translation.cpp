#include <iostream>
#include <vector>

#include "Translation.hpp"

using namespace std;

string translation::solve(){
	string result;
	int physicalAddress;
	if(problem->logicalAddress <= problem->length[problem->segmentId - 1])
		physicalAddress = problem->logicalAddress + problem->base[problem->segmentId];
	else{
		result = "Logical address is larger than the length of the segment ID";
	}
	return result;
}

