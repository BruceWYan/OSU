/**
** Program: deck.cpp
** Author: Bruce Yan
** Date: 11/7/2022
** Description: function file for deck class functions
** Input: No input taken in
** Output: display information relating to deck
**/
#include <iostream>
#include "deck.h"

using namespace std;

/**
** Function: 
** Description: 
** Parameters:
** Pre-Conditions: 
** Post-Conditions: 
**/
Deck::Deck (){
    this->n_cards = 52;
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = Card(i%13, i/13);
    }
}

/**
** Function: remove_card
** Description: removes a card from deck
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: removes a card from the deck
**/
Card& Deck::remove_card(){
    this->n_cards --;
    return this->cards[this->n_cards];
}

/**
** Function: swap
** Description: swaps card objects 
** Parameters: Cards &, Card &
** Pre-Conditions: takes two Card Object inputs
** Post-Conditions: swaps the Card objects
**/
void Deck::swap(Card &a, Card &b) {
  Card tmp = a;
  a = b;
  b = tmp;
}

/**
** Function: shuffle_deck
** Description: shuffles the deck
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: randomizes array of cards
**/
void Deck::shuffle_deck(){
    srand(time(NULL));
  
    for (int i=0; i < this->n_cards;i++){
        // Random for remaining positions.
        int r = i + (rand() % (52 -i));
  
        swap(this->cards[i], this->cards[r]);
    }
}

/**
** Function: print_deck
** Description: print the deck 
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: displays deck on screen
**/
void Deck::print_deck(){
    for (int i=0; i < this->n_cards; i++){
        this->cards[i].print_card();
    }
}

/**
** Function: get_n_cards
** Description: returns the number of cards in the deck
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns int value
**/
int Deck::get_n_cards(){
    return this->n_cards;
}

//void Deck::set_deck(){}
//Card Deck::get_deck(){}
//void Deck::set_n_cards(){}
//Deck::Deck (int size){}
//Deck::Deck(const Deck& d){}
//Deck& Deck::operator=(const Deck& d){}

