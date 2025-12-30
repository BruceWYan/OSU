/**
** Program: card.cpp
** Author: Bruce Yan
** Date: 11/7/2022
** Description: function file for card class functions
** Input: No input taken in
** Output: display information relating to cards
**/
#include "card.h"
#include <iostream>
#include <string>

using namespace std;
/**
** Function: Card
** Description: constructor
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: initialize card object 
**/
Card::Card(){
    this->suit = -1; 
    this->rank = -1;
}

/**
** Function: Card 
** Description: non default constructor
** Parameters: int, int
** Pre-Conditions: access private class
** Post-Conditions: initialize card onject 
**/
Card::Card(int r, int s){
    this->rank = r;
    this->suit = s;
}

/**
** Function: Card 
** Description: copy constructor
** Parameters: const Card &
** Pre-Conditions: takes Card object input
** Post-Conditions: returns a copy of object
**/
//copy constructor
Card::Card(const Card& c){
    this->rank = c.rank;
    this->suit = c.suit;
}

/**
** Function: get_rank
** Description: returns the value of card by rank 
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: returns int 
**/
int Card::get_rank(){
    return this->rank;
}

/**
** Function: get_suit
** Description: returns the suit of a card with corresponding int value 
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns int
**/
int Card::get_suit(){
    return this->suit;
}

/**
** Function: map_rank
** Description: converst the int rank to corresponding string
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns string 
**/
string Card::map_rank(){ //convert the int rank to corresponding string
    string ranks;
    if (this->rank > 0 && this->rank < 10){
        ranks = to_string((this->rank + 1));
        return ranks;
    }
    else if (this->rank == 0){
        ranks = "A";
        return ranks;
    }
    else if (this->rank == 10){
        ranks = "J";
        return ranks;
    }
    else if (this->rank == 11){
        ranks = "Q";
        return ranks;
    }
    else if(this->rank == 12){
        ranks = "K";
        return ranks;
    }
} 

/**
** Function: map_suit
** Description: converts the int suit to corresponding string
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: return string 
**/
string Card::map_suit(){ //convert the int suit to corresponding string
    string suits;
    if (this->suit == 0){
        suits = "Clubs";
        return suits;
    }
    else if(this->suit == 1){
        suits = "Diamonds";
        return suits;
    }
    else if (this->suit == 2){
        suits = "Hearts";
        return suits;
    }
    else if (this->suit = 3){
        suits = "Spades";
        return suits;
    }
} 

/**
** Function: print_card 
** Description: prints a card object
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: display message on screen
**/
void Card::print_card(){ //print the card out   
    string ranks = map_rank(); 
    string suits = map_suit();
    cout << ranks << " of " << suits << endl;
}

/**
** Function: print_rank
** Description: prints rank of card onject on screen
** Parameters: N/A
** Pre-Conditions: map_rank a card object
** Post-Conditions: display the rank on screen
**/
void Card::print_rank(){
    string ranks = map_rank();
    cout << ranks << " ";
}
