CXX=g++
OBJS=main.o functions.o
CFLAGS=-Wall -pedantic -ggdb3
CXXFLAGS=-std=c++11

all: game

main.o: main.c
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c main.cpp

functions.o: functions.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c functions.cpp

game: $(OBJS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(OBJS) -o game

