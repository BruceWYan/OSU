
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
void player();
int main() {
	//Variable declaration
	srand(time(NULL));
	int betOne;
	int startOne;
	int betTwo;
	int startTwo;
	int betThree;
	int startThree;
	int betFour;
	int startFour;
	int numPlayers; //amount of players
	int playerOneVal = 0;
	int playerTwoVal = 0;
	int playerThreeVal = 0;
	int playerFourVal = 0;
	int dealerVal = 0;
	int n = (rand() % 11) + 1; //gets number between 1-11
	char draw; //gets 'y' or 'n' from player if they want to draw again
	char again; //gets 'y' or 'n' if they want to play again 

	//start of the game 
	cout << '\n' << "Welcome to the Blackjack Simulator!\n"; 
	do {	
		cout << "How many players will be playing?: ";
		cin >> numPlayers; 
	} while (numPlayers > 4 || numPlayers <= 0); 
		do {
			cout << '\n' << "Player 1, how much money do you want to start with?: ";
			cin >> startOne; 
		} while (startOne <= 0); 
		
		do {
			cout << '\n' << "Player 2, how much money do you want to start with?: ";
			cin >> startTwo;
		} while (startTwo <= 0);	
	
		do {
			cout << '\n' << "Player 3, how much money do you want to start with?: ";
			cin >> startThree; 
		} while (startThree <= 0); 
	
		do {
			cout << '\n' << "Player 4 how much money do you want to start with?: ";
			cin >> startFour; 
		} while (startFour <= 0); 
				
		//Player 1's turn	
		cout << '\n' << "Player 1's turn...\n";
	
		void player();		
	
		if (draw == 'n' && playerOneVal == 21) {
			cout << '\n' << "You Win! \n";
			startOne +=betOne;
		}	

		else if (draw == 'n' && playerOneVal > 21) {
			cout << '\n' << "You Lose! \n";
			startOne -=betTwo; 
		}
	
		else if (draw == 'n' && playerOneVal < 21) {
			cout << '\n' << "Dealer's Turn...\n"; 
			
			do {
				int n = (rand() % 11) + 1; //gets number between 1-11
				cout << '\n' << "Dealer got a(n) " << n << ". ";
				dealerVal +=n; 
				cout << "Dealer total is " << dealerVal << "."; 
			} while (dealerVal <= 17);
	
			if (dealerVal == 21) {
				cout << '\n' << "Dealers value is 21, you lose! \n";
				startOne -=betOne; 
			}
		
			else if (dealerVal > 21) {
				cout << '\n' << "Dealer busted! You win! \n";
				startOne +=betOne; 
			}
			
			else if (dealerVal < 21) {
				if (dealerVal > playerOneVal) {
					cout << "The dealer's total is greater than yours. You lose! \n";
					startOne -=betOne;
				}
				
				else if (dealerVal < playerOneVal) {
					cout << "Player 1 value is greater than Dealer's. Player 1 wins! \n";
					startOne +=betOne; 
				}	
				
				else if (dealerVal == playerOneVal) {
					cout << "Player 1 tied with the Dealer. No one wins. \n";
				}	
			}
		}
		cout << "Player 1 has " << startOne << ".\n";
	return 0;
}

void player() {
	int playerOneVal;
	char draw;

		do {
			int n = (rand() % 11) + 1; //gets number between 1-11
			cout << "Player 1 got a(n) " << n << "."; 
			playerOneVal +=n; 
			cout << " Running total is " << playerOneVal << ".";
	
			if (playerOneVal < 21) {
				cout << " Do you want to draw again? y-yes or n-no: ";
				cin >> draw; 
			}	
		
			else if (playerOneVal >= 21) {
				draw = 'n'; 
			}
		
		} while (draw == 'y');	



}
