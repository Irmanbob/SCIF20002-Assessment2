#ifndef ISING1D_HPP
#define ISING1D_HPP

#include <vector>
#include <random>

// The Ising1D class implements a 1D Ising model.
class Ising1D {
private:
    int size;              // Number of spins in the 1D lattice.
    double beta;           // Inverse temperature (1/(kT)).
    std::vector<int> spins;  // Vector to store spin values (+1 or -1).
    std::mt19937 generator;  // Random number generator for Monte Carlo moves.

public:
    // Constructor: Initializes the lattice with n spins and sets the inverse temperature.
    Ising1D(int n, double beta);

    // Randomly assign spins to either +1 or -1.
    void randomise();

    // Perform one Monte Carlo sweep (attempt to flip each spin on average once).
    void sweep();

    // Calculate the total energy of the system using nearest neighbor interactions.
    double totalEnergy() const;

    // Calculate the net magnetisation (sum of all spins).
    int magnetisation() const;
};

#endif // ISING1D_HPP

