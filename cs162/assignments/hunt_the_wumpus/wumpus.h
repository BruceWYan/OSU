/**
** Program: wumpus.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains wumpus class
** Input: n/A
** Output: percept/encounter message
**/
#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include <iostream>

using namespace std;

class Wumpus : public Event { 
    public:
        Wumpus();
        ~Wumpus();
        void percept() const;
        void encounter() const;
};


#endif