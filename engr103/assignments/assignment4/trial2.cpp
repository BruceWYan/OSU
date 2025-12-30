#include <iostream> 
#include <string> 

using namespace std; 

bool is_int(string);
void string_to_int(string, int&);
bool is_zero(string);
void correct_num(string);
void correct_den(string);

int main() {
	string num, den;
	int again, value, numerator, denominator;
/*	
	do {
		if (is_int(num) == false) {
			cout << "You did not enter an integer! Please enter in an integer. \n";
		}	
		cout << "Enter a numerator: ";
		cin >> num; 
	} while (is_int(num) == false);

	do {
		if (is_int(den) == false) {
			cout << "You did not enter an integer! Please enter in an integer. \n";
		}
		else if (is_zero(den) == true) {
			cout << "Youe denominator cannot be zero! \n"; 
		}		
		cout << "Enter a denominator: ";
		cin >> den; 
	} while (is_int(den) == false || is_zero(den) == true);
*/
	cout << "Enter a numerator: "; 
	cin >> num;	
	correct_num(num);
	cout << "Enter a denominator: "; 
	cin >> den;	
	correct_den(den); 

	string_to_int(num, value);
	numerator = value; 
	string_to_int(den, value);
	denominator = value;
	
	do {
		if (numerator%2 == 0 && denominator%2 == 0) {
			denominator /=2;
			numerator /=2;
		}
		
		else if (numerator%3 == 0 && denominator%3 == 0) {
			denominator /=3;
			numerator /=3;
		}
	
		else if (numerator%5 == 0 && denominator%5 == 0) {
			denominator /=5;
			numerator /=5;
		}
		
		else if (numerator%7 == 0 && denominator%7 == 0) {
			denominator /=7;
			numerator /=7;
		}
	} while (numerator%2 == 0 || numerator%3 == 0 || numerator%5 == 0 || numerator%7 == 0 || denominator%2 == 0 || denominator%3 == 0 || denominator%5 == 0 || denominator%7 == 0);

	if (denominator == 1) {
		cout << numerator << '\n';
	}
	
	else {
		cout << numerator << "/" << denominator << '\n';
	}
}


bool is_int(string num){
	int j; //initialize j for for loop
	int test = 0; //holds a count of how many chars found in num 
	for (j=0; j < num.length(); j++) {
		if (num[j] - '\0' == 45 && (num[j+1] >= 48 && num[j+1] <=57)) { //if there is a dash and a number after it, then add 0 to test
			test+=0;
		}
		else if (num[j] - '\0' < 48 || num[j] - '\0' > 57) { //all ints are in ascii are between [48,57] thus all other numbers are chars
			test++; //if index in string fits this parameter then add to test 
		}
	}
	if (test > 0) { //identifies if there are any chars or anything other than ints returns false
		return false;
	}
	else{
		return true;
	} 
}

void string_to_int(string num, int& value){
	value = 0; //sets value equal to 0
	for (int i =0; i < num.length(); i++) { //runs the loops for each index in the string
		if (num[i] - '\0' == 45) { //ignores dash 
			value+=0;
		} 
		else {
			value = value*10 + num[i] - '0'; //turns string to int
		}
	}
	if (num[0] - '\0' == 45) { //handles negative strings
		value *= -1;
	}
	return;
}

bool is_zero(string num){ 
	int i, test = 0; 
	for (i = 0; i < num.length(); i++) {
		if (num[i] - '\0' == 48 && (num[i+1] < 48 && num[i+1] > 57) || num[i] - '\0' == 48 && (num[i-1] > 57 && num[i-1] < 48)){
			test++;
		}
		else {
			test+=0;
		}
	}
	if (test > 0) {
		return true;
	}
	else {
		return false;
	}
}

void correct_num(string num){
	int numerator;
	int value;
	do{
		if (is_int(num) == false) {
			cout << "You did not enter an integer! Please enter in an integer. \n"; 
			cout << "Enter a Numerator: ";
			cin >> num;
		}
	}while (is_int(num) == false);
	return;
}

void correct_den(string den){
	int denominator;
	int value;
	do{
		if (is_int(den) == false) {
			cout << "You did not enter an integer! Please enter in an integer. \n";
			cout << "Enter a denominator: ";
			cin >> den;	
		}
		else if (is_zero(den) == true) {
			cout << "Youe denominator cannot be zero! \n"; 
			cout << "Enter a denominator: ";
			cin >> den;	
		}	
	}while (is_int(den) == false || is_zero(den) == true);
	return;
}
