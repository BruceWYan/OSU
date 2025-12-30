/**
** Program: room.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains room class
** Input: n/A
** Output: percept/encounter message
**/
#ifndef ROOM_H
#define ROOM_H

#include "event.h"

#include <iostream>

class Room {
    private: 
        Event* e_ptr; //event pointer, points to an event
        bool player;
        bool arrow;
        int coord_x;
        int coord_y;
    public:
        Room();
        void random_assign();
        void set_event(Event*);
        void set_room_position(int, int);
        char event_designator();
        Event* get_event_ptr();
        void set_player(bool);
        bool get_player();
        bool get_arrow(); // make it 
        void set_arrow(bool); // make it
        
        
};

//keep track of rooms class? 


/*[W ] [ i] [ ]
[ i-1] [i ] [i+1 ]
[ ] [i ] [ ]*/

#endif