/**
** Program: pit.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains pit class
** Input: n/A
** Output: percept/encounter message
**/
#ifndef PIT_H
#define PIT_H

#include "event.h"
#include <iostream>

class Pit : public Event {
    public:
        Pit();
        ~Pit();
        void percept() const;
        void encounter() const;
};

#endif