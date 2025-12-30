#include <iostream> 
#include <ctime> 
#include <cstdlib> 

using namespace std; 

int main () {
	for(int x = 0; x < 11; x++) {
		srand(time(NULL)); 	
		double n = (rand() % 11) + 1; 
		cout << n << endl;		

		}



	return 0;
}
