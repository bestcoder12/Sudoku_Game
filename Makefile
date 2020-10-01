CXX=g++
CFLAGS=-Wall -pedantic -Werror -O3
CXXFLAGS=-std=c++11
DBGFLAGS=-Wall -pedantic -Werror -std=c++11 -ggdb3 -DDEBUG
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
DBOBJS=$(patsubst,%.cpp,%dbg.o,$(SRCS))

# Two versions of the executeable is made, an optimized and a debugging one

all: game game-debug

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $<

game: $(OBJS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -o $@ $(OBJS) 

game-debug:: $(DBOBJS)
	$(CXX) $(DBGFLAGS) -o $@ 

%.dbg.o: %.cpp
	$(CXX) $(DBGFLAGS) -c -o $@ $< 

# PHONEY targets can be called by make clean or make depend as per requirement
# Clean will remove only the object files either optimized ones or debugging ones

.PHONEY: clean depend all
clean:
	rm -f $(OBJS) $(DBOBJS)
depend:
	makedepend $(SRCS)
	makedepend -a -o .dbg.o $(SRCS)
