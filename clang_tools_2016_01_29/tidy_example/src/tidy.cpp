#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}
