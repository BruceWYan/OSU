#include <iostream> 
#include <ctime>
#include <cstdlib> 

using namespace std; 

int main() {
	srand(time(NULL)); //outside so that for loop doesn't print the same thing over again

	cout << "Welcome to the password generator!" << endl; 
	
	cout << "Do you want letters for your pass word? 1-yes, 0-no: ";
	int letter;
	cin >> letter; 
	
	if (letter == 1) {
		cout << "Do you want uppercase? 1-yes, 0-no: ";
		int upperCase; 
		cin >> upperCase;

		if (upperCase == 1) { 
			cout << "Enter the amount of uppcase letters you want: "; 
			int numUpper; 
			cin >> numUpper; 

			cout << "Do you want lower case? 1-yes, 0-no: ";
			int lowerCase;
			cin >> lowerCase; 
		
			if (lowerCase == 1) {
				cout << "Enter the amount of lowercase letters you want: ";
				int numLower; 
				cin >> numLower; 

				cout << "Do you want numbers? 1-yes 0-no: ";
				int numbers;
				cin >> numbers; 

				if (numbers == 1) {
					cout << "Enter the amount of numbers you want: ";
					int numNumbers; 
					cin >> numNumbers; 

					cout << "Your password is: ";
					
					for (int i = 0; i < numUpper; i++) {
						char upperLetter = (rand() % 26) + 65; 
						cout << upperLetter; 

					}  	
					for (int i = 0; i < numLower; i++) {
						char lowerLetter = (rand() % 26) + 97; 
						cout << lowerLetter; 
					}
					for (int i = 0; i < numNumbers; i++) {
						int number = rand() % 10;  
						cout << number; 
					}
					cout << endl;
				}
				
				else {
					
					cout << "Your password is: ";
					
					for (int i = 0; i < numUpper; i++) {
						char upperLetter = (rand() % 26) + 65; 
						cout << upperLetter; 
					}
					for (int i = 0; i < numLower; i++) {
						char lowerLetter = (rand() % 26) + 97; 
						cout << lowerLetter; 
					}
				}
			
			}
			else {
				cout << "Do you want numbers? 1-yes 0-no: ";
				int numbers;
				cin >> numbers; 

				if (numbers == 1) {
					cout << "Enter the amount of numbers you want: ";
					int numNumbers; 
					cin >> numNumbers; 

					cout << "Your password is: ";
					
					for (int i = 0; i < numUpper; i++) {
						char upperLetter = (rand() % 26) + 65; 
						cout << upperLetter; 

					}  	
					for (int i = 0; i < numNumbers; i++) {
						int number = rand() % 10;  
						cout << number; 
					}
					cout << endl;
				}
				
				else {
					
					cout << "Your password is: ";
					
					for (int i = 0; i < numUpper; i++) {
						char upperLetter = (rand() % 26) + 65; 
						cout << upperLetter; 
					}
				}
			}
		}
		else {
			cout << "Do you want lower case? 1-yes, 0-no: ";
			int lowerCase;
			cin >> lowerCase; 
		
			if (lowerCase == 1) {
				cout << "Enter the amount of lowercase letters you want: ";
				int numLower; 
				cin >> numLower; 

				cout << "Do you want numbers? 1-yes 0-no: ";
				int numbers;
				cin >> numbers; 

				if (numbers == 1) {
					cout << "Enter the amount of numbers you want: ";
					int numNumbers; 
					cin >> numNumbers; 

					cout << "Your password is: ";
					
					for (int i = 0; i < numLower; i++) {
						char lowerLetter = (rand() % 26) + 97; 
						cout << lowerLetter; 
					}
					for (int i = 0; i < numNumbers; i++) {
						int number = rand() % 10;  
						cout << number; 
					}
					cout << endl;
				}
				
				else {
					
					cout << "Your password is: ";
					
					for (int i = 0; i < numLower; i++) {
						char lowerLetter = (rand() % 26) + 97; 
						cout << lowerLetter; 
					}
				}
			
			}
			else {
				cout << "Do you want numbers? 1-yes 0-no: ";
				int numbers;
				cin >> numbers; 

				if (numbers == 1) {
					cout << "Enter the amount of numbers you want: ";
					int numNumbers; 
					cin >> numNumbers; 

					cout << "Your password is: ";
					
					for (int i = 0; i < numNumbers; i++) {
						int number = rand() % 10;  
						cout << number; 
					}
					cout << endl;
				}
				
				else {
					
					cout << "Your password is: ";
					
					}
			}
		}
	}

	else {
		cout << "Enter the amount of numbers you want: ";
		int numNumbers; 
		cin >> numNumbers; 

		cout << "Your password is: ";
			
		for (int i = 0; i < numNumbers; i++) {
		int number = rand() % 10;  
		cout << number;

		}
		cout << endl;
	}	







	return 0;
}
