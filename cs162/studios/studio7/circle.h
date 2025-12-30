#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <iostream>

using namespace std;

class Circle : public Shape {
    private:
        float radius;
    public: 
        Circle(const string, string, float);
        float area() const;
        float get_radius();
        void set_radius(float);
        void print_shape() const;



};




#endif