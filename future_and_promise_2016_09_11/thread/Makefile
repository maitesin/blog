CXX=clang++-3.8
CXXFLAGS=-std=c++11 -pthread

all: simple two

simple: simple.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

two: two_threads.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm simple two
