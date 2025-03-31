import pandas as pd
import matplotlib.pyplot as plt

def plot_data(filename, title, energy_plot_file, mag_plot_file):
    data = pd.read_csv(filename)
    
    # Plot Energy vs. Monte Carlo Steps
    plt.figure()
    plt.plot(data['Step'], data['Energy'], label='Energy')
    plt.xlabel('Monte Carlo Steps')
    plt.ylabel('Energy')
    plt.title(title + " - Energy")
    plt.legend()
    plt.savefig(energy_plot_file)
    plt.close()
    
    # Plot Magnetisation vs. Monte Carlo Steps
    plt.figure()
    plt.plot(data['Step'], data['Magnetisation'], label='Magnetisation', color='orange')
    plt.xlabel('Monte Carlo Steps')
    plt.ylabel('Magnetisation')
    plt.title(title + " - Magnetisation")
    plt.legend()
    plt.savefig(mag_plot_file)
    plt.close()

if __name__ == "__main__":
    # Plot for 1D Ising Model
    plot_data("ising1d_data_steps1000_size150_beta0.5.csv",
              "1D Ising Model (β=0.5, 1000 steps, size=150)",
              "energy_1d_beta0.5.png", "magnetisation_1d_beta0.5.png")
    
    # Plot for 2D Ising Model
    plot_data("ising2d_data_steps1000_size150_beta0.5.csv",
              "2D Ising Model (β=0.5, 1000 steps, size=150)",
              "energy_2d_beta0.5.png", "magnetisation_2d_beta0.5.png")
    print("Plots generated successfully.")
