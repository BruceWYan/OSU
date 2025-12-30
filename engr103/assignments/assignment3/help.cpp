
			//Player 1's turn	
			playerOneVal = 0;
			dealerVal = 0;
		
			if (startOne == 0) {
				cout << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
			
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
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
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
			//Player 1's turn	
			//Player 1's turn	
			//Player 1's turn	
			playerOneVal = 0;
			dealerVal = 0;
		
			if (startOne == 0) {
				cout << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
			
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
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
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
			playerOneVal = 0;
			dealerVal = 0;
		
			if (startOne == 0) {
				cout << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
			
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
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
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
			playerOneVal = 0;
			dealerVal = 0;
		
			if (startOne == 0) {
				cout << "Player 1 skipped...\n";
			}
				
			else if (startOne > 0) {
				cout << '\n' << "Player 1's turn...\n";
			
				do {
					cout << "You have " << startOne << ".\n";
					cout << "How much money do you want to bet you can beat the dealer?: ";
					cin >> betOne;
				} while (betOne > startOne || betOne <= 0);
				
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
		
				if (draw == 'n' && playerOneVal == 21) {
					cout << '\n' << "You Win! \n";
					startOne +=betOne;
				}	
		
				else if (draw == 'n' && playerOneVal > 21) {
					cout << '\n' << "You Lose! \n";
					startOne -=betOne; 
				}
			
				else if (draw == 'n' && playerOneVal < 21) {
					cout << '\n' << "Dealer's Turn..."; 
					
					do {
						int n = (rand() % 11) + 1; //gets number between 1-11
						cout << '\n' << "Dealer got a(n) " << n << ". ";
