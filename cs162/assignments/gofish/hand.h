/**
** Program: hand.h
** Author: Bruce Yan
** Date: 11/7/2022
** Description: header file for hand class
** Input: No input taken in
** Output: no output
**/
#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand {
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand.
    public:
        Hand();
        ~Hand(); //destructor

        
        Hand(const Hand &); //copy constructor
        Hand& operator=(const Hand&); //assignment operator overload
        
        Card get_card(int);
        int get_n_cards();
        //need to do
        void add_a_card(Card &);
        void remove_a_card(int, Card &);
        void print_hand();
        void display_ask_options();
        void swap(Card &, Card &);
};

#endif
