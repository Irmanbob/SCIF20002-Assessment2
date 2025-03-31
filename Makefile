CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

# Object files in the src folder
OBJS = src/main.o src/ising1d.o src/ising2d.o

all: ising_sim

ising_sim: $(OBJS)
	$(CXX) $(CXXFLAGS) -o ising_sim $(OBJS)

src/main.o: src/main.cpp src/ising1d.hpp src/ising2d.hpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/ising1d.o: src/ising1d.cpp src/ising1d.hpp
	$(CXX) $(CXXFLAGS) -c src/ising1d.cpp -o src/ising1d.o

src/ising2d.o: src/ising2d.cpp src/ising2d.hpp
	$(CXX) $(CXXFLAGS) -c src/ising2d.cpp -o src/ising2d.o

clean:
	rm -f src/*.o ising_sim
