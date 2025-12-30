#include <iostream> 
using namespace std;

int main(){
	int x = 0; 
	cout << "enter an integer: ";
	cin >> x;

	switch (x%2) {
		case 0: 
			cout << "even number" << endl;
		break;
		default: 
			cout << "Odd number" << endl;

	}


	return 0;
}
