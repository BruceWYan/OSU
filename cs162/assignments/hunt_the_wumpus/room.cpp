/**
** Program: room.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains room class
** Input: n/A
** Output: percept/encounter message
**/

#include "room.h"

/**
** Function: Room
** Description: constuctor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Room::Room(){ 
    e_ptr = NULL;
    this->coord_x = -1;
    this->coord_y = -1; 
    this->player = false;
    this->arrow = false;
}

/**
** Function: set_event
** Description: takes in an Event pointer and assigns it to the room
** Parameters: Event*
** Pre-Conditions: take in input 
** Post-Conditions: sets Event* in room
**/
void Room::set_event(Event* ptr){
    this->e_ptr = ptr;
}

/**
** Function: get_event_ptr
** Description: gets the event pointer for a room
** Parameters: N/A
** Pre-Conditions: acces private class 
** Post-Conditions: retursn event pointer
**/
Event* Room::get_event_ptr(){
    return this->e_ptr;
}

/**
** Function: set_room_position
** Description: sets the coordinates specifically to each room
** Parameters: int, int
** Pre-Conditions: take in int input
** Post-Conditions: set values
**/
void Room::set_room_position(int x, int y){
    this->coord_x = x;
    this->coord_y = y;
}

/**
** Function: event_designator
** Description: returns the label for the event
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: returns a char
**/
char Room::event_designator(){
    if (e_ptr != NULL){
        return e_ptr->get_event_designator();
    }
}

/**
** Function: set_player
** Description: lets me know if a room has a player
** Parameters: bool
** Pre-Conditions: access private class
** Post-Conditions: sets player
**/
void Room::set_player(bool status){
    this->player = status;
}


/**
** Function: get_player
** Description: gets the status of the player in room 
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns player status
**/
bool Room::get_player(){
    return this->player;
}

/**
** Function: get_arrow
** Description: gets the status of the arow in room
** Parameters: N/A
** Pre-Conditions: access private room
** Post-Conditions: returns arrow status
**/
bool Room::get_arrow(){
    return this->arrow;
}

/**
** Function: set_arrow
** Description: lets me know if arrow is in a room
** Parameters: bool
** Pre-Conditions: access private class
** Post-Conditions: sets arrow
**/
void Room::set_arrow(bool status){
    this->arrow = status;
}

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
