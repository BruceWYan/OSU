/***************************************************************************************************************************************************************************
**Program: assignment3.cpp
**Author: Bruce Yan 
**Date: 05/07/2022
**Description: Plays a game of blackjac with 1-4 players 
**Input: startOne, betOne, startTwo, betTwo, startThree, betThree, startFour, betFour, numPlayers, draw, again
**Output: playerOneVal, playerTwoVal, playerThreeVal, playerFourVal, dealerVal, startOne, startTwo, startThree, startFour, n
***************************************************************************************************************************************************************************/

#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	//Variable declaration
	srand(time(NULL)); //random seed as time
	double betOne; //betting amount for player 1 
	double startOne; //starting amount for player 1
	double betTwo; //betting amount for player 2
	double startTwo; //starting amount for player 2
	double betThree; //betting amount for player 3
	double startThree; //starting amount for player 3
	double betFour; //betting amount for player 4
	double startFour; //starting amount for player 4
	int numPlayers; //amount of players
	int playerOneVal = 0; //player running totals
	int playerTwoVal = 0; //player running totals 
	int playerThreeVal = 0; //player running totals
	int playerFourVal = 0; //player running totals 
	int dealerVal = 0; //dealer running total
	int n = (rand() % 11) + 1; //gets number between 1-11
	char draw; //gets 'y' or 'n' from player if they want to draw again
	char again; //gets 'y' or 'n' if they want to play again 
	cout << fixed; 
	cout << setprecision(2);
	
	system("clear"); //clears consoles	

	//start of the game 
	cout << "Welcome to the Blackjack Simulator!\n"; 
	
	//handles error for entering how many players
	do {	
		cout << "How many players will be playing?: ";
		cin >> numPlayers; 
	} while (numPlayers > 4 || numPlayers <= 0); 
	
	//if there is one player 
	if (numPlayers == 1) {
		do {
			cout << '\n' << "Player 1 how much money do you want to start with?: ";
			cin >> startOne; 
		} while (startOne <= 0); 
		
		do {
			playerOneVal = 0; //sets player and dealer values back to 0 
			dealerVal = 0;
			cout << '\n' << "Player 1's turn...\n";
	
			do { //error handles betting amounts, cannot be more than how much they start with
				cout << "How much money do you want to bet you can beat the dealer?: ";
				cin >> betOne;
			} while (betOne > startOne || betOne <= 0);
		
			do { //draws card for player 
				int n = (rand() % 11) + 1; //gets number between 1-11
				cout << "Player 1 got a(n) " << n << "."; 
				playerOneVal +=n; 
				cout << " Running total is " << playerOneVal << ". ";
	
				if (playerOneVal < 21) {
					do {
						cout << "Do you want to draw again? y-yes or n-no: ";
						cin >> draw;
					} while (draw != 'n' && draw != 'y');
				}	
		
				else if (playerOneVal >= 21) {
					draw = 'n'; 
				}
			
			} while (draw == 'y');	
	
			if (draw == 'n' && playerOneVal == 21) {
				cout << '\n' << "You Win! \n";
				startOne +=betOne;
			}	

			else if (draw == 'n' && playerOneVal > 21) {
				cout << '\n' << "You Lose! \n";
				startOne -=betOne; 
			}
		
			//draws card for dealer
			else if (draw == 'n' && playerOneVal < 21) {
				cout << '\n' << "Dealer's Turn..."; 
				
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
						cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
						startOne -=betOne;
					}
					
					else if (dealerVal < playerOneVal) {
						cout << '\n' << "Player 1 value is greater than Dealer's. Player 1 wins! \n";
						startOne +=betOne; 
					}	
				
					else if (dealerVal == playerOneVal) {
						cout << '\n' << "Player 1 tied with the Dealer. No one wins. \n";
					}	
				}
			}
			cout << '\n' << "Player 1 has " << startOne << ".\n";
			if (startOne > 0) {
				do {
					cout << "Do you want to play again? y-yes or n-no: ";
					cin >> again; 
				} while(again != 'y' && again != 'n');
			}
			
			else {
				cout << "You do not have sufficient funds. Game Over \n";
				return 0;
			}
		} while (again == 'y');
	} //end of one player if statement 
	
	//if there are 2 players 
	if (numPlayers == 2) {
		//error handles starting amounts
		do {
			cout << '\n' << "Player 1, how much money do you want to start with?: ";
			cin >> startOne; 
		} while (startOne <= 0); 
		
		do {
			cout << "Player 2, how much money do you want to start with?: ";
			cin >> startTwo;
		} while (startTwo <= 0);	

		//start of "play again" loop
		do {
			//Player 1's turn	
			playerOneVal = 0;
			dealerVal = 0;
		
			//skips first player if they have no more money 
			if (startOne == 0) { 
				cout << '\n' << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
				
				//handles the error if betting amount is greater or lesser than starting amount
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
				//player draws
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 1 got a(n) " << n << "."; 
					playerOneVal +=n; 
					cout << " Running total is " << playerOneVal << ".";
			
					if (playerOneVal < 21) {
						do {
							cout << "Do you want to draw again? y-yes or n-no: ";
							cin >> draw;
						} while (draw != 'n' && draw != 'y');
					}	
				
					else if (playerOneVal >= 21) {
						draw = 'n'; 
					}
			
				} while (draw == 'y');	
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				//dealer draws 
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
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
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startOne -=betOne;
						}
						
						else if (dealerVal < playerOneVal) {
							cout << '\n' << "Player 1 value is greater than Dealer's. Player 1 wins! \n";
							startOne +=betOne; 
						}	
						
						else if (dealerVal == playerOneVal) {
							cout << '\n' << "Player 1 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout <<	'\n' << "Player 1 has " << startOne << ".\n";
			}
			
			//player 2
			dealerVal = 0;
			playerTwoVal = 0;
 		
			//skips player 2 if they do not have any starting amount
			if (startTwo == 0) {
				cout << '\n' << "Player 2 skipped...\n";
			}
		
			else if (startTwo > 0) {
				cout << '\n' << "Player 2's turn...\n";
		
				//handle betting error 	
				do {
					cout << "You have " << startTwo << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betTwo;
				} while (betTwo > startTwo || betTwo <= 0);
				
				//player draws 
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 2 got a(n) " << n << "."; 
					playerTwoVal +=n; 
					cout << " Running total is " << playerTwoVal << ". ";
			
					if (playerTwoVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'y' && draw != 'n');
					}	
				
					else if (playerTwoVal >= 21) {
						draw = 'n'; 
					}
				
				} while (draw == 'y');	
			
				if (draw == 'n' && playerTwoVal == 21) {
					cout << '\n' << "You Win! \n";
					startTwo +=betTwo;
				}	
		
				else if (draw == 'n' && playerTwoVal > 21) {
					cout << '\n' << "You Lose! \n";
					startTwo -=betTwo; 
				}
			
				//dealer draws
				else if (draw == 'n' && playerTwoVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
						dealerVal +=n; 
						cout << "Dealer total is " << dealerVal << "."; 
					} while (dealerVal <= 17);
			
					if (dealerVal == 21) {
						cout << '\n' << "Dealers value is 21, you lose! \n";
						startTwo -=betTwo;
					}
				
					else if (dealerVal > 21) {
						cout << '\n' << "Dealer busted! You win! \n";
						startTwo +=betTwo; 
					}
					
					else if (dealerVal < 21) {
						if (dealerVal > playerTwoVal) {
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startTwo -=betTwo;
						}
						
						else if (dealerVal < playerTwoVal) {
							cout << '\n' << "Player 2 value is greater than Dealer's. Player 2 wins! \n";
							startTwo +=betTwo; 
						}	
						
						else if (dealerVal == playerTwoVal) {
							cout << '\n' << "Player 2 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout << '\n' << "Player 2 has " << startTwo << ".\n";
			}

			if (startOne > 0 || startTwo > 0) {
				do {
					cout << "Do you want to play again? y-yes or n-no: ";
					cin >> again; 
				} while(again != 'n' && again != 'y');
			}
			
			//ends game if no player has any more money
			else if (startOne <= 0 && startTwo <= 0) {
				cout << "You do not have sufficient funds. Game Over \n";
				return 0;
			}
		} while (again == 'y');
	} //end of 2 player if statement 
	  
	//if there are 3 players 
	if (numPlayers == 3) {
		do {
			cout << '\n' << "Player 1, how much money do you want to start with?: ";
			cin >> startOne; 
		} while (startOne <= 0); 
		
		do {
			cout << "Player 2, how much money do you want to start with?: ";
			cin >> startTwo;
		} while (startTwo <= 0);	
	
		do {
			cout << "Player 3, how much money do you want to start with?: ";
			cin >> startThree; 
		} while (startThree <= 0); 
	
		//Start of "play again" loop
		do {
			//Player 1's turn	
			playerOneVal = 0;
			dealerVal = 0;
		
			//skips player if not enough money
			if (startOne == 0) {
				cout << '\n' << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
			
				//handles the error with betting amounts
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
				//player draws 
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 1 got a(n) " << n << "."; 
					playerOneVal +=n; 
					cout << " Running total is " << playerOneVal << ".";
			
					if (playerOneVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'n' && draw != 'y');
					}	
				
					else if (playerOneVal >= 21) {
						draw = 'n'; 
					}
			
				} while (draw == 'y');	
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				//dealer draws
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
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
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startOne -=betOne;
						}
						
						else if (dealerVal < playerOneVal) {
							cout << '\n' << "Player 1 value is greater than Dealer's. Player 1 wins! \n";
							startOne +=betOne; 
						}	
						
						else if (dealerVal == playerOneVal) {
							cout << '\n' << "Player 1 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout <<	'\n' << "Player 1 has " << startOne << ".\n";
			}
			//player 2
			dealerVal = 0;
			playerTwoVal = 0;
 
			//skips player if not enough money 
			if (startTwo == 0) {
				cout << '\n' << "Player 2 skipped...\n";
			}
		
			else if (startTwo > 0) {
				cout << '\n' << "Player 2's turn...\n";
			
				//handles betting error 
				do {
					cout << "You have " << startTwo << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betTwo;
				} while (betTwo > startTwo || betTwo <= 0);
				
				//player draws
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 2 got a(n) " << n << "."; 
					playerTwoVal +=n; 
					cout << " Running total is " << playerTwoVal << ".";
			
					if (playerTwoVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'y' && draw != 'n');
					}	
				
					else if (playerTwoVal >= 21) {
						draw = 'n'; 
					}
				
				} while (draw == 'y');	
			
				if (draw == 'n' && playerTwoVal == 21) {
					cout << '\n' << "You Win! \n";
					startTwo +=betTwo;
				}	
		
				else if (draw == 'n' && playerTwoVal > 21) {
					cout << '\n' << "You Lose! \n";
					startTwo -=betTwo; 
				}
			
				//dealer draws 
				else if (draw == 'n' && playerTwoVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
						dealerVal +=n; 
						cout << "Dealer total is " << dealerVal << "."; 
					} while (dealerVal <= 17);
			
					if (dealerVal == 21) {
						cout << '\n' << "Dealers value is 21, you lose! \n";
						startTwo -=betTwo;
					}
				
					else if (dealerVal > 21) {
						cout << '\n' << "Dealer busted! You win! \n";
						startTwo +=betTwo; 
					}
					
					else if (dealerVal < 21) {
						if (dealerVal > playerTwoVal) {
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startTwo -=betTwo;
						}
						
						else if (dealerVal < playerTwoVal) {
							cout << '\n' << "Player 2 value is greater than Dealer's. Player 2 wins! \n";
							startTwo +=betTwo; 
						}	
						
						else if (dealerVal == playerTwoVal) {
							cout << '\n' << "Player 2 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout << '\n' << "Player 2 has " << startTwo << ".\n";
			}
			
			//Player 3's Turn 
			dealerVal = 0;		
			playerThreeVal = 0;
	
			//skips player if not enough money
			if (startThree == 0) {
				cout << '\n' << "Player 3 skipped...\n";
			}

			else if (startThree > 0) {
				cout << '\n' << "Player 3's turn...\n";
				
				//handles betting error 
				do {
					cout << "You have " << startThree << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betThree;
				} while (betThree > startThree || betThree <=0);
				
				//player draws 
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 3 got a(n) " << n << "."; 
					playerThreeVal +=n; 
					cout << " Running total is " << playerThreeVal << ".";
			
					if (playerThreeVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'n' && draw != 'y');
					}	
				
					else if (playerThreeVal >= 21) {
						draw = 'n'; 
					}
				
				} while (draw == 'y');	
			
				if (draw == 'n' && playerThreeVal == 21) {
					cout << '\n' << "You Win! \n";
					startThree +=betThree;
				}	
		
				else if (draw == 'n' && playerThreeVal > 21) {
					cout << '\n' << "You Lose! \n";
					startThree -=betThree; 
				}
				
				//dealer draws 
				else if (draw == 'n' && playerThreeVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
						dealerVal +=n; 
						cout << "Dealer total is " << dealerVal << "."; 
					} while (dealerVal <= 17);
			
					if (dealerVal == 21) {
						cout << '\n' << "Dealers value is 21, you lose! \n";
						startThree -=betThree; 
					}
				
					else if (dealerVal > 21) {
						cout << '\n' << "Dealer busted! You win! \n";
						startThree +=betThree; 
					}
					
					else if (dealerVal < 21) {
						if (dealerVal > playerThreeVal) {
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startThree -=betThree;
						}
						
						else if (dealerVal < playerThreeVal) {
							cout << '\n' << "Player 3 value is greater than Dealer's. Player 3 wins! \n";
							startThree +=betThree; 
						}	
					
						else if (dealerVal == playerThreeVal) {
							cout << '\n' << "Player 3 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout << '\n' << "Player 3 has " << startThree << ".\n";
			}
		
			if (startOne > 0 || startTwo > 0 || startThree > 0) {
				do {
					cout << '\n' << "Do you want to play again? y-yes or n-no: ";
					cin >> again; 
				} while(again != 'n' && again != 'y');
			}
		
			//ends game if players do not have sufficien funds	
			else if (startOne <= 0 && startTwo <= 0 && startThree <= 0) {
				cout << '\n'<< "You do not have sufficient funds. Game Over \n";
				return 0;
			}
		} while (again == 'y');
	}//end of three player if statement

	//if there are 4 players 	
	if (numPlayers == 4) {
		do {
			cout << '\n' << "Player 1, how much money do you want to start with?: ";
			cin >> startOne; 
		} while (startOne <= 0); 
		
		do {
			cout << "Player 2, how much money do you want to start with?: ";
			cin >> startTwo;
		} while (startTwo <= 0);	
	
		do {
			cout << "Player 3, how much money do you want to start with?: ";
			cin >> startThree; 
		} while (startThree <= 0); 
	
		do {
			cout << "Player 4, how much money do you want to start with?: ";
			cin >> startFour; 
		} while (startFour <= 0);
 
		//start of "play again" loop
		do {
			//Player 1's turn	
			playerOneVal = 0;
			dealerVal = 0;
		
			//skips player if not enough money
			if (startOne == 0) {
				cout << '\n' << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
			
				//handles the error with betting amounts
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
				//player draws 
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 1 got a(n) " << n << "."; 
					playerOneVal +=n; 
					cout << " Running total is " << playerOneVal << ".";
			
					if (playerOneVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'n' && draw != 'y');
					}	
				
					else if (playerOneVal >= 21) {
						draw = 'n'; 
					}
			
				} while (draw == 'y');	
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				//dealer draws
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
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
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startOne -=betOne;
						}
						
						else if (dealerVal < playerOneVal) {
							cout << '\n' << "Player 1 value is greater than Dealer's. Player 1 wins! \n";
							startOne +=betOne; 
						}	
						
						else if (dealerVal == playerOneVal) {
							cout << '\n' << "Player 1 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout <<	'\n' << "Player 1 has " << startOne << ".\n";
			}
			//player 2
			dealerVal = 0;
			playerTwoVal = 0;
 
			//skips player if not enough money 
			if (startTwo == 0) {
				cout << '\n' << "Player 2 skipped...\n";
			}
		
			else if (startTwo > 0) {
				cout << '\n' << "Player 2's turn...\n";
			
				//handles betting error 
				do {
					cout << "You have " << startTwo << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betTwo;
				} while (betTwo > startTwo || betTwo <= 0);
				
				//player draws
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 2 got a(n) " << n << "."; 
					playerTwoVal +=n; 
					cout << " Running total is " << playerTwoVal << ".";
			
					if (playerTwoVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'n' && draw != 'y');
					}	
				
					else if (playerTwoVal >= 21) {
						draw = 'n'; 
					}
				
				} while (draw == 'y');	
			
				if (draw == 'n' && playerTwoVal == 21) {
					cout << '\n' << "You Win! \n";
					startTwo +=betTwo;
				}	
		
				else if (draw == 'n' && playerTwoVal > 21) {
					cout << '\n' << "You Lose! \n";
					startTwo -=betTwo; 
				}
			
				//dealer draws 
				else if (draw == 'n' && playerTwoVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
						dealerVal +=n; 
						cout << "Dealer total is " << dealerVal << "."; 
					} while (dealerVal <= 17);
			
					if (dealerVal == 21) {
						cout << '\n' << "Dealers value is 21, you lose! \n";
						startTwo -=betTwo;
					}
				
					else if (dealerVal > 21) {
						cout << '\n' << "Dealer busted! You win! \n";
						startTwo +=betTwo; 
					}
					
					else if (dealerVal < 21) {
						if (dealerVal > playerTwoVal) {
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startTwo -=betTwo;
						}
						
						else if (dealerVal < playerTwoVal) {
							cout << '\n' << "Player 2 value is greater than Dealer's. Player 2 wins! \n";
							startTwo +=betTwo; 
						}	
						
						else if (dealerVal == playerTwoVal) {
							cout << '\n' << "Player 2 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout << '\n' << "Player 2 has " << startTwo << ".\n";
			}
			
			//Player 3's Turn 
			dealerVal = 0;		
			playerThreeVal = 0;
	
			//skips player if not enough money
			if (startThree == 0) {
				cout << '\n' << "Player 3 skipped...\n";
			}

			else if (startThree > 0) {
				cout << '\n' << "Player 3's turn...\n";
				
				//handles betting error 
				do {
					cout << "You have " << startThree << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betThree;
				} while (betThree > startThree || betThree <=0);
				
				//player draws 
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 3 got a(n) " << n << "."; 
					playerThreeVal +=n; 
					cout << " Running total is " << playerThreeVal << ".";
			
					if (playerThreeVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw;
						} while(draw != 'n' && draw != 'y'); 
					}	
				
					else if (playerThreeVal >= 21) {
						draw = 'n'; 
					}
				
				} while (draw == 'y');	
			
				if (draw == 'n' && playerThreeVal == 21) {
					cout << '\n' << "You Win! \n";
					startThree +=betThree;
				}	
		
				else if (draw == 'n' && playerThreeVal > 21) {
					cout << '\n' << "You Lose! \n";
					startThree -=betThree; 
				}
				
				//dealer draws 
				else if (draw == 'n' && playerThreeVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
						dealerVal +=n; 
						cout << "Dealer total is " << dealerVal << "."; 
					} while (dealerVal <= 17);
			
					if (dealerVal == 21) {
						cout << '\n' << "Dealers value is 21, you lose! \n";
						startThree -=betThree; 
					}
				
					else if (dealerVal > 21) {
						cout << '\n' << "Dealer busted! You win! \n";
						startThree +=betThree; 
					}
					
					else if (dealerVal < 21) {
						if (dealerVal > playerThreeVal) {
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startThree -=betThree;
						}
						
						else if (dealerVal < playerThreeVal) {
							cout << '\n' << "Player 3 value is greater than Dealer's. Player 3 wins! \n";
							startThree +=betThree; 
						}	
					
						else if (dealerVal == playerThreeVal) {
							cout << '\n' << "Player 3 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout << '\n' << "Player 3 has " << startThree << ".\n";
			}
			
			//Player 4's Turn 
			dealerVal = 0;		
			playerFourVal = 0;
	
			//skips player if not enough money
			if (startFour == 0) {
				cout << '\n' << "Player 4 skipped...\n";
			}

			else if (startFour > 0) {
				cout << '\n' << "Player 4's turn...\n";
			
				//handles betting error 
				do {
					cout << "You have " << startFour << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betFour;
				} while (betFour > startFour || betFour <=0);
				
				//player draws 
				do {
					int n = (rand() % 11) + 1; //gets number between 1-11
					cout << "Player 3 got a(n) " << n << "."; 
					playerFourVal +=n; 
					cout << " Running total is " << playerFourVal << ".";
			
					if (playerFourVal < 21) {
						do {
							cout << " Do you want to draw again? y-yes or n-no: ";
							cin >> draw; 
						} while(draw != 'n' && draw != 'y');
					}	
				
					else if (playerFourVal >= 21) {
						draw = 'n'; 
					}
				
				} while (draw == 'y');	
			
				if (draw == 'n' && playerFourVal == 21) {
					cout << '\n' << "You Win! \n";
					startFour +=betFour;
				}	
		
				else if (draw == 'n' && playerFourVal > 21) {
					cout << '\n' << "You Lose! \n";
					startFour -=betFour; 
				}
				
				else if (draw == 'n' && playerFourVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
				
					//dealer draws 	
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
						dealerVal +=n; 
						cout << "Dealer total is " << dealerVal << "."; 
					} while (dealerVal <= 17);
			
					if (dealerVal == 21) {
						cout << '\n' << "Dealers value is 21, you lose! \n";
						startFour -=betFour; 
					}
				
					else if (dealerVal > 21) {
						cout << '\n' << "Dealer busted! You win! \n";
						startFour +=betFour; 
					}
					
					else if (dealerVal < 21) {
						if (dealerVal > playerFourVal) {
							cout << '\n' << "The dealer's total is greater than yours. You lose! \n";
							startFour -=betFour;
						}
						
						else if (dealerVal < playerFourVal) {
							cout << '\n' << "Player 4 value is greater than Dealer's. Player 4 wins! \n";
							startFour +=betFour; 
						}	
					
						else if (dealerVal == playerFourVal) {
							cout << '\n' << "Player 4 tied with the Dealer. No one wins. \n";
						}	
					}
				}
				cout << '\n' << "Player 4 has " << startFour << ".\n";
			}
		
			//prompts player if they want to play again only if at least one player still has money
			if (startOne > 0 || startTwo > 0 || startThree > 0 || startFour > 0) {
				do {
					cout << '\n' << "Do you want to play again? y-yes or n-no: ";
					cin >> again; 
				} while(again != 'y' && again != 'n');
			}
			
			//ends game if all starting values are 0
			else if (startOne <= 0 && startTwo <= 0 && startThree <= 0 && startFour) { 
				cout << '\n'<< "You do not have sufficient funds. Game Over \n";
				return 0;
			}
		} while (again == 'y');
				
	}//end of 4 player if statement
		
	
	
	return 0;
}

