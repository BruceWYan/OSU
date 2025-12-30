/**
** Program: hunt.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains int main for unt the wumpus
** Input: N/A
** Output: the game
**/

#include <iostream>
#include "game.h"

void ask_size(int &);
bool error_handle_size(string);

int main (){
    int size = 0;
    ask_size(size);
    Game g(size);
    g.play();
}

/**
** Function: ask_size
** Description: ask user for size of cave
** Parameters: N/a
** Pre-Conditions: takes in input
** Post-Conditions: displays message
**/
void ask_size(int &sizes){
    string size;
    do{
        cout << "how big do you want your cave?: ";
        getline(cin, size, '\n');
    }while(!error_handle_size(size));
    
    sizes = stoi(size);
}

/**
** Function: error_handle_size
** Description: error handles size input
** Parameters: string
** Pre-Conditions: takes in string input 
** Post-Conditions: returns true or false 
**/
bool error_handle_size(string s){
    int size = s.length();
    if (size == 1 && (s[0] < '4' || s[0] > '9')){
        cout << "That's not a good input" << endl;
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if(s[i] < '0' || s[i] > '9'){ //if anything is less than ascii value of 1 or greater than ascii value 5
            cout << "That's not a good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }
    }
    return true;
}