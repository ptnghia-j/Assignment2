#ifndef Solver_h
#define Solver_h

#include <string>

// All Solver classes should be subclasses of this.

class Solver {
public:
    // Returns a string that tells the result.
    // This string will be used in final output.
    virtual std::string solve();
};

#endif // Solver_h