/**
** Program: pit.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains pit class
** Input: n/A
** Output: percept/encounter message
**/
#include "pit.h"

/**
** Function: percept 
** Description: prints percept message for pit event
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
void Pit::percept() const{
    cout << "You feel a breeze." << endl;
}

/**
** Function: encounter
** Description: prints encounter message for pit event
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
void Pit::encounter() const{
    cout << "AHHHH!! You fell in a pit." << endl;
    cout << "You have died!" << endl;
}

/**
** Function: Pit
** Description: constructor
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
Pit::Pit() : Event(){
    this->event_type = 'p';
}

/**
** Function: ~Pit
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Pit::~Pit(){
}

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
