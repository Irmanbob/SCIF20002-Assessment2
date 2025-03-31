# SCIF20002-Assessment2
 # Ising Model Monte Carlo Simulation

## Overview
This project implements a Monte Carlo simulation of the Ising Model in both 1D and 2D using C++ and object-oriented programming.

## Files
- **ising1d.hpp / ising1d.cpp:**  
  Implements the 1D Ising Model with random initialization, Monte Carlo sweeps using the Metropolis algorithm, and methods to compute energy and magnetisation.

- **ising2d.hpp / ising2d.cpp:**  
  Implements the 2D Ising Model on a square lattice (with periodic boundary conditions) with similar functionality to the 1D version.

- **main.cpp:**  
  The main program that runs the simulation for both models, outputs CSV files (`ising1d_data.csv` and `ising2d_data.csv`) containing energy and magnetisation data for each Monte Carlo sweep.

- **Makefile:**  
  Build instructions to compile the project.

- **analyze_ising.py:**  
  A Python script to analyze the simulation data and generate plots.

## Compilation
To compile the project, run:
```bash
make

