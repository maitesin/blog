#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> v;
	for (size_t i = 1; i <= 10; ++i) {
		v.push_back(i);
	}
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}
