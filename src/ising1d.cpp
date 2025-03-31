#include "ising1d.hpp"
#include <cmath>
#include <random>

// Constructor: Initializes the 1D lattice with random spins.
Ising1D::Ising1D(int n, double beta) : size(n), beta(beta), spins(n) {
    std::random_device rd;
    generator = std::mt19937(rd());
    randomise();  // Randomly assign spins
}

// Randomly assign each spin a value of +1 or -1.
void Ising1D::randomise() {
    std::uniform_int_distribution<> dis(0, 1);
    for (int &spin : spins) {
        spin = dis(generator) == 0 ? -1 : 1;
    }
}

// Perform one Monte Carlo sweep over the 1D lattice.
void Ising1D::sweep() {
    std::uniform_int_distribution<> site(0, size - 1);
    std::uniform_real_distribution<> prob(0.0, 1.0);

    // Attempt one spin flip per spin on average.
    for (int step = 0; step < size; ++step) {
        // Choose a random spin index.
        int i = site(generator);
        // Apply periodic boundary conditions to find left and right neighbors.
        int left = spins[(i - 1 + size) % size];
        int right = spins[(i + 1) % size];
        // Calculate the change in energy if spin at index i is flipped.
        int deltaE = 2 * spins[i] * (left + right);  // ΔE = 2 * σ_i * (σ_left + σ_right)

        double acceptanceProbability = std::exp(-beta * deltaE);
        // Use the Metropolis criterion to decide whether to flip the spin.
        if (deltaE <= 0 || prob(generator) < acceptanceProbability) {
            spins[i] = -spins[i];
        }
    }
}

// Compute the total energy of the 1D configuration.
// Only consider interactions with the right neighbor to avoid double counting.
double Ising1D::totalEnergy() const {
    double energy = 0.0;
    for (int i = 0; i < size; ++i) {
        int right = spins[(i + 1) % size];
        energy += -1.0 * spins[i] * right;
    }
    return energy;
}

// Compute the net magnetisation by summing all spins.
int Ising1D::magnetisation() const {
    int m = 0;
    for (int s : spins) {
        m += s;
    }
    return m;
}


