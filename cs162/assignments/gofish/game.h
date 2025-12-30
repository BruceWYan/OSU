/**
** Program: game.h
** Author: Bruce Yan
** Date: 11/7/2022
** Description: header file for game class
** Input: No input taken in
** Output: no output
**/
#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"


using namespace std;
class Game {
    private:
        Deck d;
        Player players[2];
    public:
        //constructor
            //no constructors, no new Deck or Player objects gets created 
        //destructor 
            //no destructors, no Deck or Player objects get deleted
        
        //tools for the game
        
        //display functions
        void welcome(string &); //welcomes player
        void player_hand(); //show player hand
        void comp_hand(); //shows comp hand
        void update_display(bool); //change parameter type for debug mode later
        
        //ask functions
        void player_ask(string &);
        void comp_ask(string &, bool); 
        
        //playing game functions
        void go_fish(); //displays message for user to go_fish
        void go_fish_player(); //displays players option to tell comp to "go fish"
        void steal_cards(string, int, int); //if check_hand returns true, then we will remove card from opponent hand, add to own hand
        int unmap_rank(string); //takes a string value of a rank and turns it into an int between 0-12
        void draw_stock(int, string, bool &); //draw from the stock
        void has_ask(string, int, int); //if 
        void deal_card(); //deals cards to players 
        void books(int, string);
        
        //game logic
        void player_turn(string, bool &);
        void comp_turn(string, bool &, bool);
        void game_logic(string, bool);
        bool debug_mode();
        bool end_game();
        void end_statement();
        bool play_again();

        //error handle
        bool error_handle_name(string);
        bool error_handle_single_letter(string);
        bool error_handle_single_int(string);

        //game
        void play();
};

#endif