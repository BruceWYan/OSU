#include <iostream> 

using namespace std;

int main() {
    	char x = 'a'; 
	do {
	cout << "Hello World" << endl;

    	cout << x << "do you still want to plat? hit 0" << endl; 
	cin >> x; 

	}
	while (x == 'y');
	 

	return 0;
}
