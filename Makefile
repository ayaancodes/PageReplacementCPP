CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src
OBJS = $(SRC)/main.cpp $(SRC)/q1_generator.cpp $(SRC)/q2_algorithms.cpp $(SRC)/q3_belady.cpp

all:
	$(CXX) $(CXXFLAGS) -o lab3 $(OBJS)

clean:
	rm -f lab3
