#include <iostream> 
#include <cmath>

int main() {
	
	std::cout << "Give me a number: " <<  std::endl; 
	int num; 
	std::cin >> num; 

	unsigned long long unsign_max = pow(2 , 8 * num);
	unsign_max--;
	unsigned long long unsign_min = 0;
	long long sign_max = pow(2 , (8 * num) - 1);
	sign_max--;
	long long sign_min = (-1) * pow(2 , (8 * num) - 1); 

	std::cout << "max unsigned overflow: " << unsign_max + 1 << std::endl; 
	
	std::cout << "min unisgned underflow: " << unsign_min - 1 << std::endl;	

	std::cout << "max signed overflow: " << sign_max + 1 << std::endl;

	std::cout << "min signed underflow: " << sign_min - 1 << std::endl; 
	
	std::cout << "Your max unisgned value is: " << unsign_max << std::endl; 

	std::cout << "Your min unsigned valus is: " << unsign_min << std::endl;

	std::cout << "Your max signed valus is: " << sign_max << std::endl;

	std::cout << "You min signed values is: " << sign_min << std::endl; 

	return 0; 

}	
