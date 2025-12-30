#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iostream>
#include <string>

using namespace std;

class Rectangle : public Shape {
    private: 
        float width;
        float height;
    public: 
        Rectangle(const string, string, float, float);
        float area() const;
        //float get_width();
        //float get_height();
        //void set_width_r(float);
        //void set_height_r(float);
        void print_shape() const;
        
};



#endif