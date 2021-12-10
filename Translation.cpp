#include <iostream>
#include <vector>

#include "Translation.hpp"

using namespace std;

string translation::solve(){
	//returned output string
	string result;
	//placeholder int
	int physicalAddress;
	//Finding the physical address
	if(problem->logicalAddress <= problem->length[problem->segmentId-1]){
		physicalAddress = problem->logicalAddress + problem->base[problem->segmentId-1];
		result = "Physical address: " + to_string(physicalAddress);
	}
	//input validation
	else{
		result = "Logical address is larger than the length of the segment ID\n";
	}

	return result;
}



