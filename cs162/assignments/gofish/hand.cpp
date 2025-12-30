/**
** Program: hand.cpp
** Author: Bruce Yan
** Date: 11/7/2022
** Description: function file for hand class functions
** Input: No input taken in
** Output: display information relating to hand
**/
#include "hand.h"

/**
** Function: Hand
** Description: constructor
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: intiatilize variables
**/
Hand::Hand(){
    this->n_cards = 0;
    this->cards = new Card[52];
}

/**
** Function: ~Hand
** Description: destructor 
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: deletes allocated memory
**/
Hand::~Hand(){
    this->n_cards = 0;
    if(this->cards){
        delete [] this->cards;
        this->cards = NULL;
    }
}

/**
** Function: Hand
** Description: copy constructor
** Parameters: const Hand &
** Pre-Conditions: takes in a Hand & object 
** Post-Conditions: deep copy
**/
Hand::Hand(const Hand& h){
    this->n_cards = h.n_cards; 
    this->cards = new Card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}

/**
** Function: operator=
** Description: AOO
** Parameters: const Hand &
** Pre-Conditions: gets a Hand object by reference
** Post-Conditions: deep copies
**/
Hand& Hand::operator=(const Hand& h){
    this->n_cards = h.n_cards;

    if (this->cards){
        delete [] this->cards;
    }

    this->cards = new Card[this->n_cards];
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}

/**
** Function: get_card
** Description: returns the card at a certain index in card array
** Parameters: int
** Pre-Conditions: takes in a int 
** Post-Conditions: returns card object at index
**/
Card Hand::get_card(int i){
    return this->cards[i]; 
}

/**
** Function: get_n_cards 
** Description: returns the number of cards in player hand
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns number of cards in player hand as an int
**/
int Hand::get_n_cards(){
    return this->n_cards;
}

/**
** Function: swap
** Description: swaps card objects 
** Parameters: Cards &, Card &
** Pre-Conditions: takes two Card Object inputs
** Post-Conditions: swaps the Card objects
**/
void Hand::swap(Card &a, Card &b) {
  Card tmp = a;
  a = b;
  b = tmp;
}

/**
** Function: add_a_card
** Description: adds a card to player hand
** Parameters: Card &
** Pre-Conditions: takes a Card object input
** Post-Conditions: creates a new memory in the heap with size plus 1 array
**/
//hand functions
void Hand::add_a_card(Card& c){
	//allocate a new array of Card objects with the size + 1
	Card* new_arr = new Card [this->n_cards + 1];

	//copy all objects from the old array (cards) into the new array
	for (int i = 0; i < this->n_cards; ++i){
		new_arr[i] = this->cards[i]; // AOO of Card 
	}

	//add the new Card object c into index n_cards
	new_arr[this->n_cards] = c;

	//free the cards array (old array)
	if (this->cards != NULL){
		delete [] this->cards;
    }
	//set cards array to the new array
	this->cards = new_arr;

	//increment the n_cards
	this->n_cards++;
}

/**
** Function: remove_a_card
** Description: removes a card from player hand
** Parameters: int, Card &
** Pre-Conditions: takes an int and Card object input
** Post-Conditions: removes a card by creating new memory in the heap of an array size -1
**/
void Hand::remove_a_card(int r, Card &c){
    //if a card in hand matches card rank opponent asked, then move to back of hand
    for (int i = 0; i < this->n_cards; i++){
        if(r == this->cards[i].get_rank()){
            //set card that matches to Card c
            c = this->cards[i];
            //swap the card that matches to the end of array
            swap(this->cards[i], this->cards[n_cards - 1]);
            break;
        }
    }
    //decrement the n_cards
    this->n_cards--;
    //allocate a new array of Card objects with the size -1
    Card* new_arr = new Card [this->n_cards];

    //copy all objects from the old array (cards) into the new array
    for (int i = 0; i < this->n_cards; ++i){
        new_arr[i] = this->cards[i];
    }

    //free the cards array (old array)
    if(this->cards){
        delete [] this->cards;
    }

    //set cards array to the new array
    this->cards = new_arr;
}

/**
** Function: display_ask_options
** Description: display the optinos that player can ask opponent
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: display message
**/
void Hand::display_ask_options(){
    if (this->n_cards != 0){
        for (int i = 0; i < this->n_cards; i++){
            int j;
            for (j = 0; j < i; j++){
                if (this->cards[i].get_rank() == this->cards[j].get_rank()){
                    break;
                }
            }
            if (i == j){
                this->cards[i].print_rank();
            }
        }       
    }
    else if (this->n_cards ==0){
        cout << "no options to ask" << endl;
    }
}

/**
** Function: print_hand
** Description: prints all cards in player hand
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: display message
**/
//prints cards in hand
void Hand::print_hand(){
    for (int i = 0; i < this->n_cards; i++){
       this->cards[i].print_card();
    }
}
