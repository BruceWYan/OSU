/************************************************************************************************************************************************************
**Program: assignment1.cpp
**Author: Bruce Yan 
**Data: 04/06/2022
**Description: Monthly Mortgage Calculator 
**Input: Home Price, Down Payment, Length of the Loan, Annual Interest Rate
**Output: Monthly mortgage, Total Amount Paid, Total Interest Paid, Mortgage Principal
*************************************************************************************************************************************************************/
 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

int main() {
	cout << '\n' << "Hello there and welcome to the mortgage calculator!" 
		        "Here we will help you calculate your monthly mortgage for the new house you just bought!" << '\n' << 
		        "Please keep all the values that you type in as numbers no commas or special characters are needed!" << '\n';

	cout << '\n' << "Please enter the price of your home in dollars: \n"; //prompts the user to type in the price of their home
	double home_price; //defines a variable home_price, this will be the price of the home 
	cin >> home_price; //gets an input from the user and stores it into home_price

	cout << "Please enter the down payment you made in dollars: \n"; //prompts the user to type in the price of the down payment
	double down_payment; //defines a variable down_payment, this will be the down payment of the home 
	cin >> down_payment; //get an input from the user and stores it into down_payment

	cout << "Please enter the length of the loan in years: \n"; //prompts the user to type in the length of the loan in years 
	double loan_length; //defines a variable loan_length, this will be the length of the loan 
	cin >> loan_length; //get an input from the user and stores it into loan_length

	cout << "Please enter the annual interest rate as a percentage: \n"; //prompts the user to type in the annual interest rate on their home 
	double ainterest_rate; //defines a variable ainterest_rate, this will beannual interest rate of the loan 
	cin >> ainterest_rate; //get an input from the user and stores it into ainterset_rate

	double mort_principal = home_price - down_payment;          //finds the mortgage principal 
	double num_pay = 12 * loan_length; 		            //finds the number of payments 
	double minterest_rate = ainterest_rate / 1200;              //finds the monthly interest rate
	double monthly_mort = ((mort_principal * (minterest_rate * pow(1 + minterest_rate , num_pay))) 
			/ (pow(1 + minterest_rate , num_pay) - 1)); //finds the monthly mortgage
	double total_paid = monthly_mort * num_pay;                 //finds the total amount paid
	double interest_paid = total_paid - mort_principal;         //finds the total amount of interest paid 

	cout << fixed; 						    //makes it so that setprecision is read correctly and not in a form such as this "1.0e5"
	
	cout << '\n' << setprecision(2) << "Your estimated monthly payments is: $" << monthly_mort << '\n'; //outputs the monthly mortgage to two decimal points

	cout << '\n' << setprecision(2) << "Your total amount paid is: $" << total_paid << '\n'; //outputs the total amount paid to two decimal points 
	
	cout << '\n' << setprecision(2) << "Principal paid: $" << mort_principal << '\n'; //outputs the principal mortgage to two decimal points 
	
	cout << '\n' << setprecision(2) << "Interest paid: $" << interest_paid << '\n'; //outputs the interest paid to two decimal points 

	cout << '\n' << "Thank you for using our mortgage calculator and have a wonderful day!" << '\n';

	return 0;

}
