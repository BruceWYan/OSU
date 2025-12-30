/**
** Program: deck.h
** Author: Bruce Yan
** Date: 11/7/2022
** Description: header file for deck class
** Input: No input taken in
** Output: no output
**/
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <ctime>
#include <cstdlib> 
#include <iomanip>

class Deck {
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; // Number of cards remaining in the deck.
    public:
        //constructors
        Deck();
        //destructor
            //no memory allocated in heap, no need for a destructor

        //What the deck need to do
        void swap(Card&, Card&);
        Card& remove_card();
        void shuffle_deck();
        void print_deck();
        int get_n_cards();
        
        /*
        Card get_deck();
        void set_deck();
        void set_n_cards();
        */        
        //Deck(int size);
        //Deck(const Deck &);
        //Deck& operator=(const Deck &);

};

#endif