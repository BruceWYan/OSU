/***************************
** Function: atoi
** Description: turns a character into a decimal value 
** Parameters: char character
** Pre-conditions: The input is a character 
** Post_conditions: Returned the decimal value of the character
***************************/

/***************************
** Function: itoa
** Description: turns a decimal value into a character value 
** Parameters: int decimal 
** pre-conditions: the input is an integer 
** post-conditions: returend the character which represents the decimal value
***************************/

/***************************
** Function: stoi
** Description: turns a string of numbers into an int
** Parameters: string num 
** pre-conditions: the input is a string 
** post-conditions: returned string as an int
***************************/


#include <iostream>
#include <string>

using namespace std; 

int atoi(char);
char itoa(int);
int length(string);
int stoi(string);

int main () {
	char character;
	int num;
	string str;
	string numStr;
	int printStr; 

	//gets decimal value from character
	cout << "type in a character: ";
	cin >> character; 
	cout << "you decimal value is: " << atoi(character) << '\n'; 
	
	//gets character from decimal value
	cout << '\n' << "type in a number: ";
	cin >> num;
	cout << "your character is: " << itoa(num) << '\n';

	//get length of word
	cout << '\n' << "Type in a word: ";
	cin >> str; 
	cout << "you length is: " << length(str) << '\n';  

	//gets int from string
	cout << '\n' << "Type in a string: "; 
	cin >> str;
	cout << '\n' << "your int is: " << stoi(str) << '\n';   

}

int atoi(char character) {
	int integer = character;
	return integer;
}


char itoa(int num) {
	char chara = num; 
	return chara; 

}

int length(string str) {
	int i; 
	for (i = 0; str[i]; i++);
	return i;
}

int stoi(string str) {
	int i;
	int sum = 0;
	for (i = 0; i < length(str); i++){
		sum = sum*10 + str[i] - '0';
	}
	return sum; 
}
