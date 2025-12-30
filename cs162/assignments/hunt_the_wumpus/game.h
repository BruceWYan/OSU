/**
** Program: game.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains game class
** Input: game variables
** Output: game message
**/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std; 

class Game {
    private: 
        //something to do with a vector maybe vector pointer???
        Event* e_arr[6];
        int side;
        vector <vector<Room> > cave; 
        int n_arrows;
        bool fire_arrow;
        bool move_player;
        bool has_gold;
        bool kill_wumpus;
        bool same_config;
        bool again;
        bool wake_wumpus;
        char player;
        char arrow;
        bool win;
        bool die;
        int arrow_x;
        int arrow_y;
        int x_coord;
        int y_coord;
        int player_x;
        int player_y;
        bool debug;
        string direct;
        int start_coord[14]; //stores positions of events so when player starts again
    public: 
        //constructor, destructors
        Game();
        ~Game();
        Game(int);
        
        //Displaying the game
        void assign_rooms(); //assign rooms an Event*
        void assign_coordinates();
        void assign_player(); //assign player to starting room
        void gen_rand_coord(int &, int &); //generate random coordinates
        void print_cave(); //print the cave
        void print_event_designator(int, int); //print event icon
        void print_player(int, int); //print player icon
        
        void scoreboard(); //updates score i.e. has gold, kill wumpus, 

        //functionality
        bool check_room(int &, int &); //check the rooms if there is an event
        void move();
        void move_arrow();
        void set_coordinates(int, int);
        void print_player_arrow(int, int);
        void print_arrow(int, int);
        void hit_wump();
        void pass_wump(int);
        void wake_wump(int, int);
        void rand_assign_event(int, int, Event*);
        void bat_encounter();
        void pit_encounter();
        void play_again();
        void same_configuration();
        void reinitialize();
        void win_condition();
        void debug_mode();
        void make_arrow();

        void surround_encounter();
        void surround_percept();
        void surround();


        bool error_handle_wasd(string);
        bool error_handle_size(string);
        bool error_handle_again(string);
        void ask_size();

        void ask_direction();
        

        void play();        

};

#endif 