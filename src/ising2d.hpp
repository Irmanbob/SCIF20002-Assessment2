#ifndef ISING2D_HPP
#define ISING2D_HPP

#include <vector>
#include <random>

// The Ising2D class implements a 2D Ising model on a square grid.
class Ising2D {
private:
    int size;         // Dimension of the square grid (size x size)
    double beta;      // Inverse temperature (1/(kT))
    std::vector<std::vector<int>> grid;  // 2D vector representing the lattice of spins
    std::mt19937 generator;  // Random number generator for Monte Carlo moves

public:
    // Constructor: Initializes the grid with random spins.
    Ising2D(int n, double beta);

    // Randomly initialize the grid with spins (+1 or -1).
    void randomise();

    // Perform one Monte Carlo sweep (attempt one spin flip per grid site on average).
    void sweep();

    // Compute the total energy of the grid configuration.
    double totalEnergy() const;

    // Compute the net magnetisation (sum of all spins in the grid).
    int magnetisation() const;
};

#endif // ISING2D_HPP
