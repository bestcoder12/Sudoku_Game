CXX=g++
CFLAGS=-Wall -pedantic -Werror -g 
CXXFLAGS=-std=c++11
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

all: game 

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $<

game:  $(OBJS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -o $@ $(OBJS) 

# PHONEY targets can be called by make clean or make depend as per requirement
# Clean will remove only the object files either optimized ones or debugging ones
.PHONEY: clean depend all
clean:
	rm -f $(OBJS)
depend:
	makedepend $(SRCS)
