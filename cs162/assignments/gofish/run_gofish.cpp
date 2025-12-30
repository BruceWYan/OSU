/**
** Program: run_gofish.cpp
** Author: Bruce Yan
** Date: 11/7/2022
** Description: int main file
** Input: takes in no input
** Output: displays the game play
**/
#include "game.h"

using namespace std;

int main(){
    Game c;
    do {
        //creates game object
        Game g;

        //plays the game
        g.play();
	 
    }while(c.play_again());

	return 0;

}