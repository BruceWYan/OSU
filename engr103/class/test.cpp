#include <iostream> 

int main() {
	for (int x = 0; x < 158; x += 15) {
		std::cout << x << std::endl; 
	}

	int count = 1, num = 25; 
	while (count < 20) {
		num--;
		count++;
	}
	std::cout << num << std::endl;

	for (int i = 0; i < 10; i++)
		for (int j = 5; j > i; j--)
			std::cout << "nesting" << std::endl;

	int i = 7, j=3;
	while (--i > ++j)
		std::cout << "loop" << std::endl;
	return 0; 
}
