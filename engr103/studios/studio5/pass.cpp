#include <iostream> 
#include <cstdlib> 

using namespace std; 

int main() {
	int loopCount; 

	cout << "how many times should we loop?" << endl; 
	cin >> loopCount; 

	for (int i = 0; i < loopCount; i++) {
		srand(time(NULL));
		int n = rand() % 6; 
		cout << n << endl;
	
	}
/*	
	int i = 0;
	while(i < loopCount) {
		cout << "We are looping: " << i << endl; 
		i++;
	}

	char playAgain; //needs to be outside, at the end what we can do, is do start start += bet on the outside
	do {
		cout << "Game is played" << endl; 
		cin << playAgain; 		


	} while(playAgain == 'y')



	return 0;
}
