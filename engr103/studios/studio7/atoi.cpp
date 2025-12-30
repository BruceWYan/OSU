/**************************************************************************************
** Function: a_to_i
** Description: Turns a character into a decimal value 
** Parameters: char character
** Pre-conditions: The input is character 
** Post-conditions: Returned the decimal value of the character 
***************************************************************************************/

#include <iostream> 

using namespace std; 

int main() {
	char input; 	
	int output;
	char ing; 

	cout << '\n' << "Type in a character: "; 
	cin >> input; 

	output = input; 

	cout << '\n' << "Here is your decimal value of the number: " << output << '\n'; 
	
	return 0;
}
