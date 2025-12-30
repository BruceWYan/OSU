/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>

using namespace std;

int main(){

	int x = 3, y;

	y = x;
	cout << "y is set to: " << y << endl;

	//while again is true, prompt user for y value,
	//and output if it's >, < or = to x
	bool again = true;
	while(again){
		cout << "Please enter a number for y: ";
		cin >> y;
		if(x > y){
			cout << "X is greater than Y\n";
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		else if (x == y){
			cout << "X is equal to y\n";
			cout << "would like to input another number?" << endl;
			cin >> again;
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		
	}

	//for loop, print out the value of x for 10 times
	for(x = 0; x < 10; x++){
		cout << x << endl;
	}
	
	//compute and output factorial for num
	cout << "What number would you like to find the factorial for? " << endl;
	int num;
	cin >> num;
	int sum;
	int total = 1;
	for(int x = num; x > 0; x--){
		sum = x * x--;
		total *= sum; 
	}
	cout << total << endl;
//conditionals
	char myanswer;
	cout << "Are you enjoying engr103? (y or n) " << endl;
	cin >> myanswer;
	if(myanswer == 'y'){
		cout << "YAY" << endl;
	}
	else {
		cout << "YOU WILL SOON!" << endl;
	}
	return 0;
}
