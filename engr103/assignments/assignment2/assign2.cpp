/**********************************************************************************************************************************************************
**Program Filename: assign3.cpp
**Author: Bruce Yan
**Date: 4/24/2022 
**Description: Create an adventure game using if/else statements for middle schoolers 
**Input: age, numbers, characters 
**Output: The story of the game is printed after the inputs are read
**********************************************************************************************************************************************************/

#include <iostream>
#include <cmath> 
#include <iomanip> 
#include <ctime> 
#include <cstdlib> 

using namespace std; 

int main() {
	
	//defines the first_input as a short data type
	short first_input; 

	//prints the story of the game
	cout << '\n' << "Hello Adventurer and welcome to The City of Beginnings!" << endl; 
	cout << '\n' << "To start your journey, press 1 to go left or 2 to go right: ";
	
	//reads first_input from the user
	cin >> first_input; 
	
	//first path
	if (first_input == 1) {
		
		//displays next part of game and prompts for user input
		cout << '\n' << "You have entered The City of Thieves! A stranger has approached you and offers you candy." << endl;
		cout << "Enter y to befriend him or n to walk away: ";
		char second_input; 
		cin >> second_input; 
		
		//first nested if statement 
		if (second_input == 'n') {
			cout << '\n' << "The stranger turned out to be dangerous and you've avoided danger!" << endl; 
			cout << "However, the stranger has chosen to challenge you to a fight!" << endl; 
			cout << "Enter your age to be given a weapon: "; 

			double third_input; 
			cin >> third_input; 
			
			//takes third_input and calculates birth year of person
			double birthyear = 2022 - third_input; 
		
			cout << '\n' << "Your birth year is " << birthyear << " and you have been given a pokeball!" << endl << endl;
			
			//second nested if statement 
			if (birthyear >= 1994) {
				cout << "You throw your pokeball. It's a Pikachu!" << endl;
				cout << "Pikachu uses thunderbolt and it's super effective!" << endl; 
				cout << "The stranger reveals themself and it turns out he's Jesus! In order to pass him you must answer his question" << endl; 
				cout << "What is 9 + 10?: "; 

				float fourth_input;
				cin >> fourth_input; 
				
				//third nested if statement
				if (fourth_input == 19 || fourth_input == 21) {
					cout << '\n' << "You have passed Jesus' test and he will now let a coin flip decide your fate." << endl; 
					cout << "Press h for head or t for tails to choose your side: "; 
									
					char fifth_input; 
					cin >> fifth_input; 
					
					//random element, n gets a number between 0-5
					srand(time(NULL)); 
					long n = rand()%6; 
					
					//fourth nested if statemnt
					//if number is even it is heads, if number is odd it is tails
					if ((n%2 == 0 || n == 0) && fifth_input == 'h') {
						cout << '\n' << "The coin has landed on heads and you've managed to get past Jesus and won the game!" << endl; 
						cout << "Congratulations!" << endl << endl;	
					}
				
					else if ((n%2 == 0 || n == 0) && fifth_input == 't') {
						cout << '\n' << "The coin has landed on heads and not tails! You could not pass Jesus and lost the game!" << endl << endl; 
					}
					
					else if ((n%2 == 1 || n == 1) && fifth_input == 't') {
						cout << '\n' << "The coin has landed on tails and you've managed to get past Jesus and won the game!" << endl;
						cout << "Congratulations!" << endl << endl;
					}

					else if ((n%2 == 1 || n == 1) && fifth_input == 'h') {
						cout << '\n' << "The coin has landed on tails and not heads! You could not get pass Jesus and lost the game!" << endl << endl; 
					}
				
					//end of fourth nested if statement
					else {
						cout << '\n' << "You did not press the right buttons! >:(" << endl; 
						cout << "Restart the game!" << endl << endl;
					} 
				}
				
				//end of third nested if statement
				else {
					cout << '\n' << "You failed the math test! Looks like you need to go back to school! Jesus has sent you home!" << endl << endl;
				}
						
			}
			
			//end of second nested if statement
			else {
				cout << "You throw your pokeball and nothing comes out! It was an old pokeball just like you!" << endl; 
				cout << "The stranger defeats you! :(" << endl << endl;
			}
		}

		else if (second_input == 'y') {
			cout << '\n' << "The strangers turned out to be very dangerous and they have kidnapped you!!" << endl;
			cout << "Remember friends, don't trust random strangers! :)" << endl << endl;
		}

		//end of first nested if statement
		else {
			cout << '\n' << "You did not press the right button! >:(" << endl;
			cout << "Restart the game!!" << endl << endl; 	
		} 

	}
	
	//2nd path
	else if (first_input == 2) {
		cout << '\n' << "You have entered a spooky, haunted forest." << endl; 
		cout << "Press c if you wish to continue or press b if you are too scared: ";
		char second_input;
		cin >> second_input; 
		
		//first nested if statement
		if (second_input == 'c') {
			cout << '\n' << "You keep walking down the dark and mysterious forest and encounter a swamp." << endl; 
			cout << "In this swamp, you see a small green creature sitting down." << endl; 
			cout << "Enter the following to find out who the creature is." << endl;
			cout << "height(in): "; 
			double third_input; 
			cin >> third_input; 
			
			cout << "weight(lbs): ";
			double fourth_input;
			cin >> fourth_input;
			
			//calculate human bmi
			double bmi = 703 * (fourth_input / pow(third_input , 2)); 
		
			//second nested if statement
			if (bmi >= 18.5) {
				cout << '\n' << "Your BMI is " << bmi << " and the creature turned out to be Jedi Master Yoda!" << endl; 
				cout << "Master Yoda senses great power in you and trains you to become a jedi master." << endl; 
				cout << "Yoda asks if you would join his crusade to defeat the evil Darth Vader." << endl; 
				cout << "Enter j to join the crusade or r to refuse: "; 
				char fifth_input; 
				cin >> fifth_input; 
				
				//third nested if statement
				if (fifth_input == 'j') {
					cout << '\n' << "You fly to fight Darth Vader and engage with him in an epic and dangerous batthle!" << endl; 
					cout << "Solve the following math problem to keep fighting: " << endl; 
					cout << "(9 + 9)(6 - 5) / (5 - 3) = " ;
					
					short sixth_input; 
					cin >> sixth_input; 
					
					//fourth nested if statement
					if (sixth_input == 9) {
						cout << '\n' << "Good job, you've evaded Vaders strongest attack!" << endl; 
						cout << "Oh no! Fate is now out of your hands! The gods of randomness will not decide your fate..." << endl; 
						cout << "Enter j to continue" << endl; 

						int seventh_input; 
						cin >> seventh_input;
						
						srand(time(NULL)); 
						long n = rand()%6; 

						//fifth nested if statement
						if (n%2 == 0 || n == 0) {
							cout << '\n' << "You have defeated Darth Vader! You are now the champion of the galaxy!" << endl << endl; 
						}
					
						//end of fifth nested if statement
						else if (n%2 == 1 || n == 1) {
							cout << '\n' << "Luck was not on your side! Vader has defeated you and darkness still rules the galaxy!" << endl << endl;
						}
					}	
				
					//end of fourth nested if statement
					else {
						cout << '\n' << "You miscalculated and Vader gets the better of you! Darkness rains supreme!" << endl << endl;
					}
				}
				
				else if (fifth_input == 'r') {
					cout << '\n' << "You refused and with that Yoda sensed your misguided ways and slayed you on the spot!" << endl << endl; 
				}
				
				//end of third nested if statement
				else {
					cout << '\n' << "You did not press the right button! >:(" << endl; 
					cout << "Restart the game!!" << endl << endl;
				}
			}
		
			//end of second nested if statement
			else {

			}		   
		}

		else if (second_input == 'b') {
			cout << '\n' << "You were scared and decided to run back home. Unfortunately, you tripped on a rock and fell to your doom!" << endl << endl; 
		}
		
		//end of first nested if statement
		else {
			cout << '\n' << "You did not press the right button! >:(" << endl; 
			cout << "Restart the game!!" << endl << endl;
		} 
		
		
	}
	
	//end of very first if statement
	else {
		cout << "You did not press the right button! >:(" << endl; 
		cout << "Restart the game!!"<< endl << endl; 		

	}	

	return 0;
}
