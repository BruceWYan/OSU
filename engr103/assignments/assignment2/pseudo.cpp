Print Welcome the use and ask user which direction they want to go
Read 1 to go left or 2 to go right from user

//asks user to type in an input to move on
if the user first_input is 1, 
	print that they are in a city and they meet a stranger
	read y to befriend or n to walk away from user
	
	//the user entered in the wrong answer and exits program
	if the user second_input is y
		print they have been kidnapped 
		exit program 
	
	//user continues on the path
	else if the user second_input is n
		print that user has succesfully avoided danger however the stranger challenges them
		read the age(third_input) of user to choose a weapon 

		//takes input and calculates birth year 
		birthyear = 2022 - third_input
		
		//continues the path if birthyear >= 2000
		if birthyear >= 2000
			print that user has been given a pokeball for a weapon. They summon Pikachu and it uses thunderbolt
			print It's super effective! The stranger turns out to be Jesus and he asks what is 9 + 10? 
			read answer (fourth_input) from the user
			
			//continues the path if the fourth_input is 19 or 21
			if fourth_input == 19 || fourth_input == 21
				print Jesus has allowed you to decide your fate with a flip of a coin
				print Do you accept the offer? 
				read y for yes or n for no from user
				
				//entering 'y' prompts the computer to start the random coin flip 
				//the coin flip will be determined through numbers 0-5, with even numbers including zero being heads and vice versa
				if fifth_input == y 
					srand(time(null)) 
					n = rand()%6 
					
					//if an even number is chosen then the game is won and vice versa 
					if n%2 == 0 || n == 0
						print you landed on heads and won the game! 
						exit program 
					else if n%2 == 1 || n == 1 
						print you landed on tails and have lost the game!  
						exit program
				
				//exits program, wrong input
				else if fifth_input == n
					print Jesus has sent you home because you refused his offer
					exit program
		
			//exits program, wrong input		
			else 
				print You failed the math test and will be sent back home
				exit program
		
		
		//exits program, wrong input
		else 
			print your pokeball was ineffective 
			exit program


//second path, prompted a question
else if first_input == 2
	print You have entered a spooky forest. Do you wish to continue? 
	read y for yes or n for no from the user 
	
	//user inputs correct input and continues on path. Another questions is prompted
	if second_input == y
		print You encounter a green creature in a swamp. Enter the following to pass 
		read height(third_input) and weight(fourth_input) in inches and pounds from user 
		bmi = 703 * (weight / pow(height, 2)) 
		
		//if user bmi is >= 18.5 then user continues on the path and a question is prompted
		if bmi >= 18.5 
			print bmi, the creature turned out to be Yoda and trains you to be a jedi.
			print He asks you to join him in his crusade to save the galaxy. 
			read j to join yoda or r to refuse from the user (fifth_input)
			
			//continues path and prompts for another input
			if fifth_input == j
				print You fly to fight Darth Vader. You engage him in a fierce and dangerous battle. 
				print Solve the following problem to keep fighting: (9+9)(6-5)/(5-3) 
				read sixth_input from the user 
				
				//continues path 
				//input the enter key to continue 
				//users fate will be decided randomly with randomly generated number from 0-5
				//any even number or 0 wins the game and vice versa
				if sixth_input == 9 
					print fate is now out of your hands and the gods of randomness will decide your fate. 
					print Press enter to continue 
					read seventh_input (continue) 
					
					srand(time(NULL))
					n = rand()%6
					
					//gets an even number 
					if n%2 == 0 || n == 0 
						print fate is one your side and you defeat Darth Vader. You are now the hero of the galaxy 			
						exit program
					//gets an odd number 
					else if n%2 == 1 || n == 1
						print fate has deserted you and Darth Vader defeats you! 
						exit program					
				
				//wrong input, exit program 
				else 
					print you miscaculated and vader gets the best of you	
					exit program			

			//wrong input, exit program
			else if fifth_input == r
				print you refuse, leaving yoda no choice but to slay you out of the fear that you would become sith
				exit program 
		
		//wrong input, exit program 
		else 
			print you are not strong enough to take on the challenge
			exit program
	
	//wrong input, exit program
	else 
		print You decided to walk back home, but tripped and fell in a hole! 
		exit program
