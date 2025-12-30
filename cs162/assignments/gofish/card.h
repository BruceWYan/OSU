/**
** Program: card.h
** Author: Bruce Yan
** Date: 11/7/2022
** Description: header file for card class
** Input: No input taken in
** Output: no output
**/
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
    private:
        int rank; // Should be in the range 0-12.
        int suit; // Should be in the range 0-3.
    public:
        Card();
        Card(int , int);
        Card(const Card&);

        int get_rank();
        int get_suit();
        string map_suit(); //convert the int suit to corresponding string
        string map_rank(); //convert the int rank to corresponding string
        void print_card(); //print the card out
        void print_rank();
        // must have constructors, destructor, accessors, and mutators
};

#endif
