CXX=clang++-3.8
CXXFLAGS=-fsanitize=address -g

all: free overflow leak double_free

free: free.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

overflow: overflow.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

leak: leak.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

double_free: double_free.cpp
	${CXX} ${CXXFLAGS} -o $@ $<

clean:
	rm free overflow leak double_free
