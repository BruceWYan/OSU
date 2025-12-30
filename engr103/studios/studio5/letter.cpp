#include <iostream> 
#include <cstdlib>
#include <ctime> 

using namespace std; 

int main() {
	
	srand(time(NULL));
		

	int upperCount = 0;
	cout << "How many upper case letters?" << endl; 
	cin >> upperCount; 
	cout << "your pass word is ";
	for (int i = 0; i < upperCount; i++) {
		// how to generate random numbers 
		// between 65 and 90
		char letter = (rand() % 26) + 65;
		cout << letter; 
	


	}





	return 0;
}
