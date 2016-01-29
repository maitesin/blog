#include <iostream>
#include <vector>

int main(void) {
	int hardcoded[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> v (hardcoded, hardcoded + sizeof(hardcoded) /
			    sizeof(int));
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}
