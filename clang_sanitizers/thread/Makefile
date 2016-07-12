CXX=clang++-3.8
CXXFLAGS=-fsanitize=thread -g -lpthread

all: race

race: race.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm race
