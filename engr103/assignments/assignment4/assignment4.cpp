/********************************************
** Program: assignment4.cpp 
** Author: Bruce Yan
** Data: 05/19/2022
** Description: Fraction convert, that converts a fraction to its lowests terms
** Input: num, den, str
** Output: numerator, denominator
********************************************/
#include <iostream> 
#include <string> 

using namespace std; 

bool is_int(string);
/********************************************
** Function: is_int()
** Description: Indicates if a given string is an integer
** Parameters: string num
** Pre-conditions: take a string parameter 
** Post-conditions: return a value to tell if the string is an int 
********************************************/
void string_to_int(string, int&);
/********************************************
** Function: string_to_int()
** Description: Turns a string into an int
** Parameters: string num, int& value
** Pre-conditions: takes a string parameter and stores address into value
** Post-conditions: returns a string as an int 
********************************************/
bool is_zero(string);
/********************************************
** Function: is_zero() 
** Description: Indicates if a given string is 0
** Parameters: string num 
** Pre-conditions: takes a string parameter
** Post-conditions: returns a value to tell if the string is 0
********************************************/
void end_statement(int, int);
/********************************************
** Function: end_statement()
** Description: displays reduced fraction to users
** Parameters: int numer, int demon 
** Pre-conditions: takes two numer and denom, which is received from conversion()
** Post-conditions: returns the reduced fraction on the display
********************************************/
string string_num();
/********************************************
** Function: string_num()
** Description: Checks the string num if it is an integer, else reprompts the user 
** Parameters: string num
** Pre-conditions: takes a string parameter
** Post-conditions: returns an error statement if false or num if correct
********************************************/
string string_den();
/********************************************
** Function: string_den()
** Description: checks string den if it is an integer and not 0, else reprompts the user
** Parameters: string den
** Pre-conditions: takes a string parameter
** Post-conditions: returns an error satement if false or den if correct
********************************************/
bool is_play_again(string);
/********************************************
** Function: is_play_again() 
** Description: Indicates if a given string turned into an int is 1
** Parameters: string str
** Pre-conditions: takes a string parameter
** Post-conditions: returns a value to tell if string_to_int(str) is 1  
********************************************/
bool to_lowest_terms(int&, int&);
/*******************************************
** Function: to_lowest_terms()
** Description: Indicates if denominator is 0, else will pass by reference of lowest terms to the ints
** Parameters: int &numerator, int &denominator
** Pre-conditions: takes two int parameters
** Post-conditions: returns false if denominator is 0, else it will pass by reference of lowest terms
********************************************/
int g_c_d(int, int);
/*******************************************
** Function: g_c_d(int, int);
** Description: gets an int that determines the greatest common divisor
** Parameters: int numerator, int denominator
** Pre-conditions: takes two int parameters
** Post-conditions: returns an int that represts the greatest common divisor
********************************************/

int main() { // 10 lines
	string num; 
	string den; 
	string str;
	int value; 
	int numerator; 
	int denominator;

	do {
		num = string_num(); // checks to see if numerator is an integer 
		den = string_den(); // checks to see if denominator is an integer and is not 0

		string_to_int(num, value); // turns numerator into an int, stores into a value
		numerator = value; // value assigned to numerator
		string_to_int(den, value); // turns denominator into an int, stores into a value 
		denominator = value; // value assigned to denominator
	
		to_lowest_terms(numerator, denominator);
		end_statement(numerator, denominator);
	} while (is_play_again(str) == true); 
}


bool is_int(string num){ // 8 lines
	int test = 0;

	for (int j=0; j < num.length(); j++) {

		if (num[j] - '\0' == 45 && (num[j+1] - '\0' >= 48 && num[j+1] - '\0' <=57)) { //if there is a dash and a number after it, then add 0 to test
			test+=0;
		}

		else if (num[j] - '\0' < 48 || num[j] - '\0' > 57) { //all ints are in ascii are between [48,57] thus all other numbers are chars
			return false; 
		}
	}

	if (test == 0) { 
		return true;
	}
}

void string_to_int(string num, int &value){ // 9 lines
	value = 0;
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

bool is_zero(string num){ // 8 lines
	int test = 0; 
	
	for (int i = 0; i < num.length(); i++) {
		//checks if num is 0 or if num has any characters that aren't an integer 
		if ((num[i] - '\0' == 48 && (num[i+1] - '\0' < 48 && num[i+1] - '\0' > 57)) || (num[i] - '\0' == 48 && (num[i-1] - '\0' > 57 && num[i-1] - '\0' < 48)) || num[0] - '\0'== 48){
			return true;
		}
		//checks if num has a 0 and if there is a number after/before it
		else if (num[i] - '\0' == 48 && (num[i+1] - '\0' >= 48 && num[i+1] -'\0' <= 57) || num[i] - '\0' == 48 && (num[i-1] - '\0' <= 57 && num[i-1] - '\0' >= 48 || num[i] - '\0' <= 57 && num[i+1] - '\0' >= 48)){
			test+=0;
		}
	}
	
	if (test == 0){ // if test is 0, then no values other than integers/zero were detected 
		return false;
	}
}

void end_statement(int numerator, int denominator){ // 9 lines
	cout << "Your fraction in lowest terms is: ";
	if (denominator == 1) {
		cout << numerator << '\n';
	}

	else if (denominator == -1) {
		cout << numerator * -1 << '\n';
	}

	else if (denominator < -1) {
		cout << numerator * -1 << "/" << denominator * -1 << '\n';
	}	

	else {
		cout << numerator << "/" << denominator << '\n';
	}

	return;
}

string string_num(){ // 7 lines
	//checks if string num is an integer
	string num;
	do {
		cout << "Enter a numerator: ";
		getline(cin, num);	

		if (is_int(num) == false) {
			cout << "You did not enter an integer! Please enter in an integer. \n";
		}	
	} while (is_int(num) == false);
	
	return num;
}

string string_den(){ // 9 lines
	//checks if string den is an integer/zero
	string den;
	do {
		cout << "Enter a denominator: ";
		getline(cin, den); 

		if (is_int(den) == false) {
			cout << "You did not enter an integer! Please enter in an integer. \n";
		}

		else if (is_zero(den) == true) {
			cout << "Your denominator cannot be zero! \n"; 
		}		
	} while (is_int(den) == false || is_zero(den) == true);

	return den;
}

bool to_lowest_terms(int &numerator, int &denominator){ //6 lines
	if (denominator == 0){ 
		return false;
	}
	int numer = numerator;
	int denom = denominator;	
	numerator /= g_c_d(numer, denom); // divides numerator to lowest terms
	denominator /=  g_c_d(numer, denom); // divides denominator to lowest terms
}

int g_c_d(int numerator, int denominator){ //7 lines
	int divisor = 1; 
	for(int i = 2; i <= 7; i++) {
		while (numerator%i == 0 && denominator%i == 0){
			numerator /= i;
			denominator /= i;
			divisor *= i;
		}
	}
	return divisor;
}

bool is_play_again(string str) { // 10 lines
	//reprompts an again statement if input is invalid and if 1 or 0 then either terminate or loop program
	int value;
	int numb;

	do {
		cout << "Do you want to use fraction reducer again? 1-yes or 0-no: ";
		getline(cin, str);

		string_to_int(str, value);
		numb = value;

	} while (is_int(str) == false || numb > 1 || numb < 0);

	if (numb == 1){
		return true;
	}

	else if (numb == 0){
		return false; 
	}
}
