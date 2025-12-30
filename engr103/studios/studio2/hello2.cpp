/***************************************************************************************************************************************************************Name: Bruce Yan 
**Assignment: Studio 2 assignment
**Purpose: Make a calculator and then prompt for MPG and then make another calculator
**Input: MPG 
**Output: Gallons of Gas Used, Cost of gas if gas costed $2.50 or $4.50
*************************************************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

int main () {
	
	std::cout << 
	"hello World!" << std::endl;
	
	double qOne = 20 / (2 + 4 + 5.5) + 2 / 4;
	double qTwo = 20 / 2 + 4 + 5.5 + 2 / 4;  
	double qThree = 25 % 5 * (6 + 12) % 36; 
	double qFour = 2 * 45.0 + 10 / 12;
	double qFive = 2 * 45.0 + 10.0 / 12;
	double qSix = pow(2 , 8) / (6 + 12) * 2; 

	std::cout << std::fixed;

	std::cout << std::setprecision(2) << qOne << '\n';
	std::cout << std::setprecision(2) << qTwo << '\n';
	std::cout << std::setprecision(2) << qThree << '\n';
	std::cout << std::setprecision(2) << qFour << '\n'; 
	std::cout << std::setprecision(2) << qFive << '\n';
	std::cout << std::setprecision(2) << qSix << '\n';  
	
	std::cout << "Enter the miles per gallon (MPG) of your car: \n";
	double mPg; 
	std::cin >> mPg;

	double galOfGasUsed = 100000 / mPg;
	double twoFifty = galOfGasUsed * 2.50; 
	double fourFifty = galOfGasUsed * 4.50; 

	std::cout << "Gallons used over a 100,000-miles: " << galOfGasUsed << '\n';
	std::cout << "If the gas is $2.50/gallon, you will spend: $" << twoFifty << '\n';
	std::cout << "If the gas is $4.50/gallon, you will spend: $" << fourFifty << '\n';  
	
	return 0;
}
