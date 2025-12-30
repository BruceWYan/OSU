#include <iostream> 

int main() {
	std::cout << "Type in a letter to see if it's lower or upper case" << std::endl; 
	char a; 
	std::cin >> a; 

	if ( a >= 65 && a <= 90) {
		std::cout << "Upper Case!" << std::endl; 
	}

	else if ( a >= 91 && a <= 122) {
		std::cout << "Lower Case!" << std::endl; 
	}
	
	return 0;
}
