/**
** Program: wumpus.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains wumpus class
** Input: n/A
** Output: percept/encounter message
**/
#include "wumpus.h"

/**
** Function: percept 
** Description: prints percept message for wumpus event 
** Parameters: N/A
** Input: n/A
** Output: percept/encounter message
**/
void Wumpus::percept() const{
    cout << "You smell a terrible stench." << endl;
}

/**
** Function: encounter
** Description: prints encounter message for wumpus event
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
void Wumpus::encounter() const{
    cout << "RAWRRRRR!! You encountered the Wumpus!" << endl;
    cout << "It wakes up and eats you!" << endl;
}

/**
** Function: Wumpus
** Description: constructor
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
Wumpus::Wumpus() : Event(){
    this->event_type = 'w';
}

/**
** Function: ~Wumpus
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Wumpus::~Wumpus(){
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

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/