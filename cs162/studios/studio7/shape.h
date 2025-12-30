#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

using namespace std;

class Shape {
    protected:
        const string name;
        string color;
    public: 
        //constructor
        Shape(const string);

        //accessor
        string get_name();
        string get_color();

        //mutator
        void set_color(string &);

        virtual float area() const = 0;

        virtual void print_shape() const = 0;
};

#endif