#include <iostream> 

using namespace std;

int main() {
	int numPlayer; 
	
	do {
		cout << "how many players to you have: ";
		cin >> numPlayer; 	
		
		if (numPlayer == 1) {
			cout << "You have " << numPlayer << " player" << endl; 
						
		}
		
		else if (numPlayer == 2) {
			cout << "You have " << numPlayer << " player" << endl; 

		}


	}while (numPlayer >= 4); 

	return 0;
}
