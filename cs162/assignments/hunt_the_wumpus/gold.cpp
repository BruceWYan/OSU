
/**
** Program: gold.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains gold class
** Input: n/A
** Output: percept/encounter message
**/

#include "gold.h"

/**
** Function: percept 
** Description: prints percept message for gold event
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
void Gold::percept() const{
    cout << "You see a glimmer nearby." << endl; 
}

/**
** Function: encounter
** Description: prints encounter message for gold event
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
void Gold::encounter() const{
    cout << "You found gold!" << endl;
}

/**
** Function: Gold
** Description: constructor
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
Gold::Gold() : Event() {
    this->event_type = 'g';
}

/**
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Gold::~Gold(){
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
