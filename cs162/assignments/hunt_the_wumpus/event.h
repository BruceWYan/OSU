/**
** Program: event.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains event class
** Input: n/A
** Output: percept/encounter message
**/
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;


class Event {
    protected: 
        char event_type;
    public: 
        Event();
        Event(char);
        ~Event();
        char get_event_designator() const; 
        virtual void percept() const = 0;
        virtual void encounter() const = 0;
        
        
        
    
};


#endif