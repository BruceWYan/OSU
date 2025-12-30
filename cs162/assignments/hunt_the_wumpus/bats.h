/**
** Program: bat.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains bats class
** Input: n/A
** Output: percept/encounter message
**/
#ifndef BATS_H
#define BATS_H

#include "event.h"
#include <iostream>

using namespace std;

class Bats : public Event {
    public:
        Bats();
        ~Bats();
        void percept() const;
        void encounter() const;
};


#endif