/**************************************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value 
** Parameters: int decimal 
** Pre-conditions: The input is an integer 
** Post-conditions: returned the character which represents the decimal value
***************************************************************************************/

#include <iostream> 

using namespace std; 

int main() {
	int input;
	char output; 
	
	cout << "Type in an integer: ";
	cin >> input; 

	output = input; 
	
	cout << "Your character is: " << output << '\n';	



	return 0;
}
