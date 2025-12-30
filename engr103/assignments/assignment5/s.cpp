#include <iostream> 

using namespace std;

int main(){
	float hi;

	
	do {
		cout << "hi you want?: ";
		cin.clear();
		cin.ignore(100, '\n');
	} while(!(cin >> hi));
	
/*	cout << "type something: ";
	while(!(cin >> hi)){
		cout << "please ytpe it in corrently: ";
		cin.clear();
		cin.ignore(100, '\n');
	}*/
}
