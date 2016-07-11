CXX=clang++-3.8
CXXFLAGS=-fsanitize=undefined -g

all: function

function: function.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm function
