CXX=clang++-3.8
CXXFLAGS=-fsanitize=memory -g

all: memory

memory: memory.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm memory
