/********************************************
** Program: assignment4.cpp 
** Author: Bruce Yan
** Data: 05/19/2022
** Description: Fraction convert, that converts a fraction to its lowests terms
** Input: num, den, str
** Output: numer, denom 
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
int conversion(int, int);
/********************************************
** Function: conversion()
** Description: converts two numbers to their lowest terms by dividing both by the greatest common factor 
** Parameters: int numerator, int denominator
** Pre-conditions: takes two int parameters the numerator and the denominator 
** Post-conditions: returns one number reduced to lowest terms 
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

int main() { // 11 lines
	string num; 
	string den; 
	string str;
	int value; 
	int numerator; 
	int denominator;
	int denom; 
	int numer; 

	do {
		num = string_num(); // checks to see if numerator is an integer 
		den = string_den(); // checks to see if denominator is an integer and is not 0

		string_to_int(num, value); // turns numerator into an int, stores into a value
		numerator = value; // value assigned to numerator
		string_to_int(den, value); // turns denominator into an int, stores into a value 
		denominator = value; // value assigned to denominator

		numer = conversion(numerator, denominator); // divides numerator to lowest terms
		denom = conversion(denominator, numerator); // divides denominator to lowest terms

		end_statement(numer, denom); // displays your fraction at lowest terms

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

void string_to_int(string num, int& value){ // 9 lines
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

int conversion(int numerator, int denominator){ // 5 lines
	for (int i = 2; i <= 7; i++) {
		while (numerator%i == 0 && denominator%i == 0) { //if both numerator and denominator share a common factor, then divide both by i
			denominator /=i;
			numerator /=i;
		}
	}

	return numerator;
}

void end_statement(int numer, int denom){ // 9 lines
	if (denom == 1) {
		cout << numer << '\n';
	}

	else if (denom < 0) {
		cout << numer * -1 << "/" << denom * -1 << '\n';
	}	

	else if (denom == -1) {
		cout << numer * -1 << '\n';
	}

	else {
		cout << numer << "/" << denom << '\n';
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
bool is_play_again(string str) { // 10 lines
	//reprompts an again statement if input is invalid and if 1 or 0 then either terminate or loop program
	int value;
	int numb;

	do {
		cout << "Do you want to use fraction converter again? 1-yes or 0-no: ";
		cin >> str;

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
