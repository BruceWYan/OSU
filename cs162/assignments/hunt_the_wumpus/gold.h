/**
** Program: gold.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains gold class
** Input: n/A
** Output: percept/encounter message
**/
#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include <iostream>

class Gold : public Event {
    public:
        Gold();
        ~Gold();
        void percept() const;
        void encounter() const;
};

#endif