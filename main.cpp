#include <pthread.h>
#include <mutex>
#include <iostream>
#include <vector>
#include "Solver.h"
// #include "assignment2.h"

using namespace std;

mutex printLock;

// -- PLACEHOLDER CLASSES -- //
struct MemAllocQuestion{};
class MemAllocSolver: Solver
{
public:
    // store the question
    MemAllocSolver(MemAllocQuestion) {}
    string solve()
    {
        // finished, print safely
        return "Final results!";
    }
};

// MemoryAllocation thread
void* solveMemoryAlloc(void* vec)
{
    vector<MemAllocQuestion>* questions = (vector<MemAllocQuestion>*) vec;
    for (auto q : *questions)
    {
        MemAllocSolver solver(q);
        string result = solver.solve();

        // finished, print safely
        printLock.lock();
        cout << result;
        printLock.unlock();
    }
}

int main()
{
    vector<MemAllocQuestion> memQuestions;
    
    // USER INPUT
    while(true)
    {
        string input = "";
        cout << "Which question type to add?\n";
        cout << "1. Free space after memory allocation\n";
        cout << "2. Virtual memory translation\n";
        cout << "3. Solve and exit\n";
        cout << "Choose: ";
        cin >> input;
        int choice = stoi(input);
        cout << "Chose " << choice << ".\n";
        switch(choice)
        {
            case 1: // Free space after allocation
            case 2: // Virtual memory address translation
            case 3:
                goto endInput;
        }
    }
endInput:
    // SOLVE AND PRINT
    cout << "Solving created problems...";
    pthread_t thr[2];
    pthread_create(&thr[0], NULL, solveMemoryAlloc, (void*) &memQuestions);

    return 0;
}