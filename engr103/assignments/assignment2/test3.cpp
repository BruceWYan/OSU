#include <iostream> 
#include <cmath> 
#include <iomanip> 

using namespace std; 

int main () {
	
	short first_input; 

	cout << "Hello Adventurer and welcome to The City of Beginnings!" << endl; 
	cout << "To start your journey please choose either one of the followings paths: 1) Go left or 2) Go right" << endl; // rewrite the line and add space to the next line 
 	cin >> first_input;  

	if (first_input == 1) {
		cout << "You have entered the city of [ ]! A strange creature has approached you do you befriend them? Enter y to befriend him, enter n to walk away: "; 
		char second_input;
		cin >> second_input; 
		
		if (second_input == 'y' || second_input == 'Y') { //add another or statement to inlcude 'yes'
			cout << "The stranger turned out to be dangerous and they have kidnapped you! Remember don't trust random strangers!" << endl;
			return 0; 
		}
		else if (second_input == 'n' || second_input == 'N') {
			cout << endl << "You brushed off the stranger who turned out to be dangerous!" << endl;
			cout << "Unfortunately he has chosen to challenge you in a fight. Enter your age to choose a weapon: "; 
			double age; 
			cin >> age;
			
			double birthyear = 2022 - age; 
			
			cout << "Your birth year is " << birthyear << " and you have been given a pokeball." << endl;
			
			if (birthyear >= 2000) {
				cout << "You throw your pokeball. It's a Pikachu! Pikachu uses thunderbolt and it's super effective!" << endl; 
				
			}
			else {
				cout << "You throw your pokeball. Nothing comes out. The stranger charges at you and you end up being kidnapped" << endl;
				cout << "Gameover :(" << endl; 
			} 	
		}
	}
	else if (first_input == 2) {
		cout << "bruh" << endl; 
	}

	return 0;
	
}
