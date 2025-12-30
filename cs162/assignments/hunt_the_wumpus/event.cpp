/**
** Program: event.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains event class
** Input: n/A
** Output: percept/encounter message
**/
#include "event.h"


/**
** Function: Event
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Event::Event(){   
    this->event_type = '\0';
}

/**
** Function: Event
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Event::Event(char n){
    this->event_type = n;
}

/**
** Function: ~Event
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Event::~Event(){
}

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
char Event::get_event_designator() const{
    return this->event_type;
}

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
