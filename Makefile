FLAGS=-std=c++17 -Wall -pedantic

all:
	g++ main.cpp $(FLAGS) -o ./build/a.exe
	./build/a.exe
