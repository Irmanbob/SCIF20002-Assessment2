#include "ising2d.hpp"
#include <cmath>
#include <random>

// Constructor: Initializes the 2D grid with random spins.
Ising2D::Ising2D(int n, double beta) : size(n), beta(beta), grid(n, std::vector<int>(n)) {
    std::random_device rd;
    generator = std::mt19937(rd());
    randomise();  // Populate the grid with random spins (+1 or -1)
}

// Randomly assign each site in the 2D grid a spin of either +1 or -1.
void Ising2D::randomise() {
    std::uniform_int_distribution<> dis(0, 1);
    for (auto& row : grid) {
        for (int &s : row) {
            s = dis(generator) == 0 ? -1 : 1;
        }
    }
}

// Perform one Monte Carlo sweep over the entire 2D grid.
void Ising2D::sweep() {
    std::uniform_int_distribution<> pos(0, size - 1);
    std::uniform_real_distribution<> prob(0.0, 1.0);

    // Attempt one spin flip per site on average.
    for (int step = 0; step < size * size; ++step) {
        // Choose a random site (i, j)
        int i = pos(generator);
        int j = pos(generator);

        // Retrieve the nearest neighbor spins using periodic boundary conditions.
        int up    = grid[(i - 1 + size) % size][j];
        int down  = grid[(i + 1) % size][j];
        int left  = grid[i][(j - 1 + size) % size];
        int right = grid[i][(j + 1) % size];

        // Calculate the change in energy if the spin at (i,j) is flipped.
        int deltaE = 2 * grid[i][j] * (up + down + left + right);
        double acceptanceProbability = std::exp(-beta * deltaE);

        // Apply the Metropolis criterion: flip if energy decreases or with probability acceptanceProbability.
        if (deltaE <= 0 || prob(generator) < acceptanceProbability) {
            grid[i][j] = -grid[i][j];
        }
    }
}

// Compute the total energy of the 2D configuration.
// Only interactions to the right and below are counted to avoid double counting.
double Ising2D::totalEnergy() const {
    double energy = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int right = grid[i][(j + 1) % size];
            int down  = grid[(i + 1) % size][j];
            energy += -1.0 * grid[i][j] * (right + down);
        }
    }
    return energy;
}

// Compute the net magnetisation by summing all spins in the grid.
int Ising2D::magnetisation() const {
    int m = 0;
    for (const auto& row : grid) {
        for (int s : row) {
            m += s;
        }
    }
    return m;
}

