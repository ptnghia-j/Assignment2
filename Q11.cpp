#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <mutex>
#include <iostream>
#include <sstream>
#include <vector>

void q11 () {
  //Displaying the given segmentation table
  std::cout << "Seg ID  Base   Length" << '\n';
  std::cout << "1       200    600" << '\n';
  std::cout << "2       2300   20" << '\n';
  std::cout << "3       1200   100" << '\n';

  //Declaring variables
  int SegID; //User input, tells what ID to User
  int logadd; //User input, logical address

  int Base[2] = {200, 2300, 1200} //Given bases
  int Length[2] = {600, 20, 100} //Given lengths

  int phyadd; //Physical address

  //Getting user input
  std::cout << "What Seg ID: ";
  std::cin >> SegID;
  std::cout << "What logical address: ";
  std::cin >> logadd;
  std::cout << '\n';

  //Finding the physical address
  if (logadd <= Length[SegID - 1]) {
    phyadd = logadd + Base[SegID - 1];
    std::cout << "Physical address: " << phyadd << '\n';
  } else {
    std::cout << "Logical address is larger than the length of that Seg ID" << '\n';
  }
}
