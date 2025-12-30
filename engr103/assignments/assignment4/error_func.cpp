/***********************************************
** Program: error_func.cpp
** Author: Bruce Yan
** Description: Test functions for error
** Input: int lower_bound, int upper_bound, int test_value, int num1, int num2, string num, string sentence, int& num1, int& num2 
** Output: true, false, 1, 0, -1, value, length 
***********************************************/

// ENGR103-120 Assignment 4
// error_func.cpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//function prototypes
bool check_range(int, int, int);
/********************************************
** Function: check_range()
** Description: Indicates if a given int is between two other given ints 
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-conditions: takes an int parameter
** Post-conditions: returns a value to tell if test_value is between lower_bound and upper_bound
********************************************/
int  equality_test(int, int);
/********************************************
** Function: equality_test()
** Description: Tests num1 against num2 and indicated if one is larger, smaller, or equal
** Parameters: int num1, int num2
** Pre-conditions: takes an int parameter
** Post-conditions: returns either -1, 0, or 1 depending on the inequality relationship between num1 and num2
********************************************/
bool is_int(string);
/********************************************
** Function: is_int()
** Description: Indicates if a given string is an integer
** Parameters: string num
** Pre-conditions: takes a string parameter
** Post-conditions: returns a value to tell if the given string is an integer 
********************************************/
bool is_float(string);
/********************************************
** Function: is_float()
** Description: Indicated if a given string is a float
** Parameters: string num
** Pre-conditions: takes a string parameter
** Post-conditions: returns a value to tell if the given string is a float
********************************************/
void string_to_int(string, int&);
/********************************************
** Function: string_to_int
** Description: Convert a given sting to an int
** Parameters: string num, int &value
** Pre-conditions: takes a string parameter and stores it into an int
** Post-conditions: returns given address into int &value
********************************************/
void swap(int&, int&);
/********************************************
** Function: swap()
** Description: Swap num1 and num2
** Parameters: int& num1, int& num2
** Pre-conditions: takes two ints and swaps them 
** Post-conditions: returns num1 as num2 and num2 as num1 
********************************************/
int  word_count(string);
/********************************************
** Function: word_count() 
** Description: Provides the number of words in a given string
** Parameters: string sentence 
** Pre-conditions: takes a string parameter
** Post-conditions: returns the number of words in a sentence as an int
********************************************/

bool check_range(int lower_bound, int upper_bound, int test_value){//6 lines

	if (lower_bound <= test_value && upper_bound >= test_value) { //tests to see if test is atmost upper and atleast lower
		return true;
	
	}
	
	else { //all cases that dont fit the above parameter 
		return false;
	}
}

int  equality_test(int num1, int num2){ // 9 lines

	if (num1 < num2) { //tests if num1 is less than num2
		return -1; 
	}

	else if (num1 > num2) { //tests if num1 is greater than num2
		return 1; 
	}

	else if (num1 == num2) { //test if num1 is equal to num2
		return 0;
	}
}

bool is_int(string num){ // 8 lines 

	int test = 0; //holds a count of how many chars found in num 
	
	for (int j=0; j < num.length(); j++) {
	
		if (num[j] - '\0' == 45 && (num[j+1] >= 48 && num[j+1] <=57)) { //if there is a dash and a number after it, then add 0 to test
			test+=0;
		}

		else if (num[j] - '\0' < 48 || num[j] - '\0' > 57) { //all ints are in ascii are between [48,57] thus all other numbers are chars
			return false; //if index in string fits this parameter then add to test 
		}
	}

	if (test == 0){
		return true;
	} 
}

bool is_float(string num){ // 8 lines

	int test = 0; //holds a count of how many chars found in num 

	for (int j=0; j < num.length(); j++) {

		//if there is a "." then and a number preceeding and after the ".", then no count will be added to test
		if (num[j] - '\0' == 46 && (num[j+1] >= 48 && num[j+1] <=57) || (num[j-1] >=48 && num[j-1] <=57) || (num[j] - '\0' == 45 && (num[j+1] >= 48 && num[j+1] <=57))) {
			test+=0;
		}

		//add count to test if char is present
		else if (num[j] - '\0' < 48 || num[j] - '\0' > 57) {
			return false; 
		}
	}
	
	if (test == 0){
		return true;
	} 
}

void string_to_int(string num, int& value){ // 8 lines

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

void swap(int& num1, int& num2){ // 4 lines 
	int temp = num1; 
	num1 = num2;
	num2 = temp; 
	return;
}

int  word_count(string sentence){ // 5 lines

	int length = 1; //length represents how many words in a sentence, set to 1 since there will be atleast one word in a sentence

	for (int i = 0; i < sentence.length(); i++) { //repeats loop for every character in loop 

		//if there is a space in between chars, then a count will be added 
		if (sentence[i] - '\0' == 32 && sentence[i-1] - '\0' != 32 && sentence[i+1] - '\0' != 32) { 
			length++;
		}
	}

	return length;
}


void pause(){
	cout << "\n\npress anything to continue...";
    cin.clear();
    cin.ignore(256 ,'\n');
}

int main()
{
	system("clear");
	cout << "\n1. Testing check_range() ....\n";
	cout << "Testing check_range(5,8,6)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << check_range(5,8,6);
	(check_range(5,8,6) == true)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting check_range(5,8,8)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << check_range(5,8,8);
	(check_range(5,8,8) == true)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting check_range(5,8,5)...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << check_range(5,8,5);
	(check_range(5,8,5) == true)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting check_range(5,8,9)...\n";
	cout << "Expected: 0";
	cout << "\tActual: "<< check_range(5,8,9);
	(check_range(5,8,9) == false)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n2. Testing equality_test() ....\n";
	cout << "Testing equality_test(7,7)...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << equality_test(7,7);
	(equality_test(7,7) == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting equality_test(10,8)...\n";
	cout << "Expected: 1";
	cout << "\tActual: "<< equality_test(10,8);
	(equality_test(10,8) == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting equality_test(9,10)...\n";
	cout << "Expected: -1";
	cout << "\tActual: " << equality_test(9,10);
	(equality_test(9,10) == -1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n3. Testing is_int() ....\n";
	cout << "Testing is_int(\"34\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_int("34");
	(is_int("34") == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"-34\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_int("-34");
	(is_int("-34") == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"50.6\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: "<< is_int("50.6");
	(is_int("50.6") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("abc");
	(is_int("abc") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"-\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("-");
	(is_int("-") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"50abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_int("50abc");
	(is_int("50abc") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n4. Testing is_float() ....\n";
	cout << "Testing is_float(\"34.2\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_float("34.2");
	(is_float("34.2") == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"-34.2\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: " << is_float("-34.2");
	(is_float("-34.2") == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\".6\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: "<< is_float(".6");
	(is_float(".6") == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"4.\")...\n";
	cout << "Expected: 1";
	cout << "\tActual: "<< is_float("4.");
	(is_float("4.") == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("abc");
	(is_float("abc") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"-\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("-");
	(is_float("-") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"-.\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("-.");
	(is_float("-.") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_float(\"50.2abc\")...\n";
	cout << "Expected: 0";
	cout << "\tActual: " << is_float("50.2abc");
	(is_float("50.2abc") == 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n5. Testing string_to_int() ....\n";
	int value;
	cout << "Testing string_to_int...(\"1234\", value)\n";
	cout << "Expected: 1234";
	string_to_int("1234", value);
	cout << "\tActual: "<< value;
	(value == 1234)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting string_to_int...(\"18\", value)\n";
	cout << "Expected: 18";
	string_to_int("18", value);
	cout << "\tActual: "<< value; 
	(value == 18)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting string_to_int...(\"-18\", value)\n";
	cout << "Expected: -18";
	string_to_int("-18", value);
	cout << "\tActual: "<< value; 
	(value == -18)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n6. Testing swap() ....\n";
	cout << "Testing swap(7, 9)...\n";
	cout << "Expected num1 = 9, num2 = 7";
	int num1 = 7, num2 = 9;
	swap(num1, num2);
	cout << "\tActual: num1 = " << num1 << ", num2 = "<< num2; 
	(num1 == 9 && num2 == 7)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting swap(100, -60)... \n";
	cout << "Expected num3 = -60, num4 = 100";
	num1 = 100; num2 = -60;
	swap(num1, num2);
	cout << "\tActual: num1 = " << num1 << ", num2 = "<< num2; 
	(num1 == -60 && num2 == 100)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	pause();
	cout << "\n7. Testing word_count() ....\n";
	cout << "Testing word_count(\"Hello, my name is Roger.\")...\n";
	cout << "Expected: 5";
	string sentence = "Hello, my name is Roger.";
	cout << "\tActual: "<< word_count(sentence);
	(word_count(sentence) == 5)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting word_count(\"hello\")...\n";
	cout << "Expected: 1";
	sentence = "hello";
	cout << "\tActual: "<< word_count(sentence);
	(word_count(sentence) == 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	

	return 0;
}
