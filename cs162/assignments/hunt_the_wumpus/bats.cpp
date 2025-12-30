/**
** Program: bat.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains bats class
** Input: n/A
** Output: percept/encounter message
**/
#include "bats.h"

/**
** Function: percept
** Description: print percept message for bats event
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
void Bats::percept() const{
    cout << "You hear wings flapping." << endl;
}

/**
** Function: encounter
** Description: prints encounter message for bats event
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
void Bats::encounter() const{
    cout << "You entered a room with bats!" << endl;
    cout << "They're carrying you somewhere else oh no!!" << endl;
}

/**
** Function: Bats
** Description: constructor
** Parameters: N/A
** Pre-Conditions: 
** Post-Conditions: 
**/
Bats::Bats() : Event(){
    this->event_type = 'b';
}

/**
** Function: ~Bats
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
Bats::~Bats(){
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
