#include <iostream>

using namespace std;

int main() {
	/*int n=10, i=0;
	do {
		cout << i++ << endl;
	} while (i <= n); 
	
	int count = 1;
	int num = 24; 
	while (count < 25) {
		num--;
		count++;
	}

	cout << count << " " << num << endl;	

	int x = 0; 
	for (x =0; x <2020; x++) {
		while (x <2020) {
			x++;
		}

	}
	cout << x << endl;	
		
	int o = 2; 
	switch (o) {
		case 0 : o = 10; break; 
		case 1 : o = 20; break; 
		case 2 : o = 30; 
		default: o = 40; 
	}
	cout << o << endl;*/

	int total = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i; j++) 
			total += i*j;
	
	}
	cout << total << endl; 
	return 0;
}
