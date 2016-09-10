CXX=clang++-3.8
CXXFLAGS=-std=c++11 -pthread

all: simple

simple: simple.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm simple
