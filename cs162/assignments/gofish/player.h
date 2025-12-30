/**
** Program: player.h
** Author: Bruce Yan
** Date: 11/7/2022
** Description: header file for player class
** Input: No input taken in
** Output: no output
**/
#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "card.h"

class Player {
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
        //constructors, AOO, destructors
        Player(); //default constructor
        Player(int); //non default constructor
        ~Player(); 
        Player(const Player &); //copy constructor
        Player& operator=(const Player &); //assignment operatore overlaod
        
        //accessors, mutators
        Hand* get_hand();
        int get_books(int); //get books at array
        int get_n_books(); 
        void add_a_book(int);
        

        //error handling
        bool error_handle_options(string);
        
        //functions needed
        void place_a_card(Card&); //access add_a_card function in hand class
        void take_a_card(int ,Card &); //access remove_a_card function in hand class
        void get_options();
        void display_hand();
        bool check_hand(string); //checks hand if card opponent asked exists in your hand
        bool empty_hand(); //checks if hand is empty
        bool has_books(int);
        void remove_a_book_from_hand(int, string); //will clear a book from hand if card received creates a book
        int get_hand_n_cards();
}; 

#endif