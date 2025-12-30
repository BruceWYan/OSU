#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
#include <iostream>

using namespace std;

class Square : public Rectangle {
    public: 
        Square(const string, string, float, float);
        //void set_width(float);
        //void set_height(float);
        void print_square() const;
};

#endif