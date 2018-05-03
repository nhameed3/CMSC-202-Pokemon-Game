CXX = g++
CXXFLAGS = -Wall

proj2: Pokemon.o MyPokemon.o proj2.cpp
	$(CXX) $(CXXFLAGS) Pokemon.o MyPokemon.o proj2.cpp -o proj2

Pokemon.o: Pokemon.cpp Pokemon.h
	$(CXX) $(CXXFLAGS) -c Pokemon.cpp

MyPokemon.o: MyPokemon.cpp MyPokemon.h
	$(CXX) $(CXXFLAGS) -c MyPokemon.cpp