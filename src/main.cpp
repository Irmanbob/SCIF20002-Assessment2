#include "ising1d.hpp"
#include "ising2d.hpp"
#include <iostream>
#include <fstream>

// Main function to run both the 1D and 2D Ising model simulations.
int main() {
    // Simulation parameters
    const int steps = 1000;       // Number of Monte Carlo sweeps.
    const int size1D = 100;       // 1D lattice size.
    const int size2D = 100;       // 2D lattice: 100x100.
    const double beta = 0.5;      // Inverse temperature (1/(kT)).

    // ----- 1D Ising Model Simulation -----
    // Create an instance of the 1D Ising model
    Ising1D model1D(size1D, beta);
    
    // Open an output CSV file for writing simulation data for the 1D model.
    std::ofstream out1d("ising1d_data.csv");
    out1d << "Step,Energy,Magnetisation\n";  // CSV header line
    
    // Run the simulation for a given number of sweeps
    for (int i = 0; i < steps; ++i) {
        model1D.sweep();
        // Write the current step, total energy, and magnetisation to the CSV file.
        out1d << i << "," << model1D.totalEnergy() << "," << model1D.magnetisation() << "\n";
    }
    out1d.close();
    std::cout << "1D simulation complete.\n";

    // ----- 2D Ising Model Simulation -----
    // Create an instance of the 2D Ising model
    Ising2D model2D(size2D, beta);
    
    // Open an output CSV file for writing simulation data for the 2D model.
    std::ofstream out2d("ising2d_data.csv");
    out2d << "Step,Energy,Magnetisation\n";  // CSV header line
    
    // Run the simulation for a given number of sweeps
    for (int i = 0; i < steps; ++i) {
        model2D.sweep();
        // Write the current step, total energy, and magnetisation to the CSV file.
        out2d << i << "," << model2D.totalEnergy() << "," << model2D.magnetisation() << "\n";
    }
    out2d.close();
    std::cout << "2D simulation complete.\n";

    return 0;
}

