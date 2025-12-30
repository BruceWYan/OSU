/**
** Program: player.cpp
** Author: Bruce Yan
** Date: 11/7/2022
** Description: function file for player class functions
** Input: No input taken in
** Output: display information relating to player
**/
#include "player.h"

using namespace std; 

/**
** Function: Player
** Description: parameterized constructor
** Parameters: int
** Pre-Conditions: takes an int size value
** Post-Conditions: sets size of array and sets value of books
**/
Player::Player(int size){
    this->n_books = size;
    this->books = new int[size];
}

/**
** Function: Player
** Description: Default constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: initialize array and n_books variable
**/
Player::Player(){
    this->n_books = 0;
    this->books = NULL;
}

/**
** Function: ~Player
** Description: deletes array  
** Parameters: N/A
** Pre-Conditions: there exists an array of books
** Post-Conditions: deletes array and set everything to null
**/
Player::~Player(){
    this->n_books = 0;
    
    if(this->books){
        delete [] this->books; 
        this->books = NULL;
    }
}

/**
** Function: Player
** Description: copy constructor
** Parameters: const Player&
** Pre-Conditions: takes in a player object
** Post-Conditions: copies player opject into another player object
**/
/*Player::Player(const Player& p){
    this->hand = p.hand;
    this->n_books = p.n_books;
    this->books = new int[this->n_books];
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }
}*/

/**
** Function: operator=
** Description: AOO
** Parameters: const Player&
** Pre-Conditions: takes in Player object
** Post-Conditions: returns a deep copy of Player object
**/
Player& Player::operator=(const Player& p){
    this->hand = p.hand;
    this->n_books = p.n_books;

    if (this->books){
        delete [] this->books;
        this->books = NULL;
    }

    this->books = new int[this->n_books]; 
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }

    return *this;
}

/**
** Function: place_a_card
** Description: gets hand and adds a card 
** Parameters: Card &
** Pre-Conditions: pass in a Card object
** Post-Conditions: run add_a_card function in hand class
**/
void Player::place_a_card(Card& c){
    this->hand.add_a_card(c);
}

/**
** Function: take_a_card
** Description: gets hand and removes a card
** Parameters: int , Card &
** Pre-Conditions: pass in a Card object and int 
** Post-Conditions: runs remove_a_card function in hand class
**/
void Player::take_a_card(int ranks, Card& c){
    this->hand.remove_a_card(ranks, c);
}

/**
** Function: get_options
** Description: gets hand and display asking options
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: runs display_ask_options in hand class
**/
void Player::get_options(){
    this->hand.display_ask_options();
}

/**
** Function: display_hand  
** Description: get hand and print the hand
** Parameters: N/A
** Pre-Conditions: Hand object initialized 
** Post-Conditions: runs print_hand function in hand class
**/
void Player::display_hand(){
    this->hand.print_hand();
}

/**
** Function: get_hand
** Description: returns a Hand pointer to player hand
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns hand pointer
**/
Hand* Player::get_hand(){
    return &(this->hand);
}

/**
** Function: get_hand_n_cards
** Description: gets hand and returns number of card in hand
** Parameters: N/A
** Pre-Conditions: hand object is initialized 
** Post-Conditions: return int value
**/
int Player::get_hand_n_cards(){
    return this->hand.get_n_cards();
}

/**
** Function: get_books
** Description: get books at a certain index
** Parameters: int 
** Pre-Conditions: takes in an int input
** Post-Conditions: returns the int corresponding to the book
**/
int Player::get_books(int i){
    this->books[i];
}

/**
** Function: get_n_books
** Description: gets the number books player has
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns int value
**/
int Player::get_n_books(){
    return this->n_books;
}

/**
** Function: remove_a_book_from_hand
** Description: removes all cards in a book from player hand
** Parameters: int, string
** Pre-Conditions: take in input relating to rank and card ask
** Post-Conditions: remove cards from hand
**/
void Player::remove_a_book_from_hand(int rank, string ask){
    Card tmp; //temp card holder
    //
    while(check_hand(ask)){
        for (int i = 0; i < this->hand.get_n_cards(); ++i){
            if (rank == this->hand.get_card(i).get_rank()){
                this->hand.remove_a_card(rank, tmp);
            }
        }
    }   
}

/**
** Function: has_books
** Description: checks if a player hand has books 
** Parameters: int 
** Pre-Conditions: take in input about card rank
** Post-Conditions: returns true or false
**/
//return true or false if a card has books in the hand
bool Player::has_books(int rank){
    int ctr = 0;
    for (int i = 0; i < this->hand.get_n_cards(); ++i){
        if (rank == this->hand.get_card(i).get_rank()){
            ctr++;
        }
    }
    if (ctr == 4){
        return true;
    }
    else {
        return false;
    }
}

/**
** Function: add_a_book
** Description: adds a book to book array
** Parameters: int 
** Pre-Conditions: take in int book
** Post-Conditions: add a book to array
**/
void Player::add_a_book(int new_book){
    //allocate a new array of int objects with the size + 1
    
    int* new_arr = new int[this->n_books + 1];
    //copy all objects from the old array (books) into the new array 
    for (int i = 0; i < n_books; i++){
        new_arr[i] = books[i];
    }
    //add the new int objects new_book into index n_books
    new_arr[n_books] = new_book;
    //free the books array (old array)
    if (books){
        delete [] books;
    }
    //set books array to the new array
    books = new_arr;
    //increment the n_books
    n_books++;
}

/**
** Function: check_hand
** Description: check hand for card 
** Parameters: string
** Pre-Conditions: take in string input
** Post-Conditions: returns true or false
**/
bool Player::check_hand(string s){
    string ranks;
    int ctr = 0;
    for (int i = 0; i < this->hand.get_n_cards(); i++){
        ranks = this->hand.get_card(i).map_rank();
        if (s == ranks)
            return true;
        else
            ctr++;
    }
    if (ctr > 0){
        return false;
    }

}

/**
** Function: empty_hand
** Description: return true or false if hand is empty
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: return true or false
**/
bool Player::empty_hand(){
    if (this->hand.get_n_cards() == 0){
        return true;
    }
    else {
        return false;
    }
    //check if hand has cards return false
    //if empty return true
}

/**
** Function: error_handle_options
** Description: error handle input
** Parameters: string 
** Pre-Conditions: takes in string input
** Post-Conditions: returns true or false
**/
bool Player::error_handle_options(string s){
    int size = s.length();
    int ctr = 0;
    string ranks;
    if (size > 2 || size < 0){
        cout << endl << "That's not good input" << endl; 
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 0; i < this->hand.get_n_cards(); i++){
        ranks = this->hand.get_card(i).map_rank();
        if (s == ranks)
            return true;
        else
            ctr++;
    }
    if (ctr > 0){
        cout << "That's not good input" << endl; 
        cout << "Please try again" << endl;
        return false;
    }
}