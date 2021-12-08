#include <pthread.h>
#include <mutex>
#include <iostream>
#include <vector>
// #include "assignment2.h"

using namespace std;

// -- PLACEHOLDER CLASSES -- //
struct MemAllocQuestion
{
    
};
class MemAllocSolver
{
public:
    // store the question
    MemAllocSolver(MemAllocQuestion)
    {

    }
    void solve()
    {

    }
};

// MemoryAllocation thread
void solveMemoryAlloc(vector<MemAllocQuestion> vec)
{
    for (auto q : vec)
    {
        MemAllocSolver solver(q);
        solver.solve();
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
        cout << "Chose " << choice << "\n";
        switch(choice)
        {
            case 1: // Free space after allocation
            case 2: // Virtual memory address translation
            case 3:
                goto endInput;
        }
    }
endInput:
    // SOLVE
    cout << "Solving created problems...";
    return 0;
}