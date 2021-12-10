#include <pthread.h>
#include <mutex>
#include <iostream>
#include <vector>

#include "Solver.h"
#include "Allocation.hpp"
#include "Translation.hpp"

using namespace std;

mutex printLock;

// MemoryAllocation thread
void* solveMemoryAlloc(void* vec)
{
    vector<memAllocationProblem>* questions = (vector<memAllocationProblem>*) vec;
    for (auto q : *questions)
    {
        memAllocation solver(q);
        string result = solver.solve();

        printLock.lock();
        cout << result;
        printLock.unlock();
    }
}


void* solveTranslation(void* vec){
	vector<translationProblem>* questions = (vector<translationProblem>*) vec;
	for(auto q: *questions){
		translation solver(q);
		string result = solver.solve();
		printLock.lock();
		cout << result << "\n";
		printLock.unlock();
	}
}
int main()
{
    vector<memAllocationProblem> memQuestions;
    vector<translationProblem> translationProblems;
 
    // USER INPUT
    while(true)
    {
        string input = "";
        cout << "Which question type to add?\n";
        cout << "1. Free space after memory allocation\n";
        cout << "2. Virtual memory translation\n";
        cout << "3. Solve what we have and exit\n";
        cout << "Choose: ";
        cin >> input;
        int choice = stoi(input);

        switch(choice)
        {
            case 1: // Free space after allocation
            {
                vector<int> freeSpaces;
                vector<int> processes;
                cout << "Free space blocks available... (press enter after each entry; -1 to stop)" << endl;
                while(true)
                {
                    cin >> input;
                    int in = stoi(input);
                    if (in == -1)
                        break;
                    freeSpaces.push_back(in);
                }
                cout << "Processes' requested space... (press enter after each entry; -1 to stop)" << endl;
                while(true)
                {
                    cin >> input;
                    int in = stoi(input);
                    if (in == -1)
                        break;
                    processes.push_back(in);
                }
                cout << "Solving Policy...\n" 
                     << "1. First Fit\n"
                     << "2. Best Fit\n"
                     << "3. Worst Fit\n";
                cout << "Enter your choice: ";

                int solvePolicy;
                cin >> solvePolicy;

                memAllocationProblem q;
                q.memoryAvailable = freeSpaces;
                q.processes = processes;
                q.method = (Method)solvePolicy;
                memQuestions.push_back(q);

                cout << "\"Free space after allocation\" problem added.\n\n";
		break;
            }
            case 2: // Virtual memory address translation
		{
                int segmentId, logicalAddress;
		cout << "Given a segment table of\nSeg ID  Base   Length\n1       200    600\n2       2300   20\n3       1200   100\nEnter a segment ID:\n";
		cin >> input;
		segmentId = stoi(input);
		cout << "Enter a logical address to be translated:\n";
		cin >> input;
		logicalAddress = stoi(input);
		translationProblem q;
		q.segmentId = segmentId;
		q.logicalAddress = logicalAddress;
		translationProblems.push_back(q);
		cout << "\"Virtual memory translation\" problem added.\n\n";
       	   	break;
	     }
	     case 3: // Exit input mode
                cout << endl << endl;
                goto endInput;
        }
    }
endInput:
    // SOLVE AND PRINT
    cout << "Solving created problems...\n";
    pthread_t thr[2];

    pthread_create(&thr[0], NULL, solveMemoryAlloc, (void*) &memQuestions);
    pthread_create(&thr[0], NULL, solveTranslation, (void*) &translationProblems);
    pthread_join(thr[0], NULL);

    return 0;
}
