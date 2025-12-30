#include "shape.h"

using namespace std;

Shape::Shape(const string names) : name(names){
    this->color = "some color ";
}

string Shape::get_name(){
    return this->name;
}

string Shape::get_color(){
    return this->color;
}

void Shape::set_color(string &new_color){
    this->color = new_color;
}

/*void Shape::area() const{
    return 0;
}*/

/*void Shape::print_shape(){
    cout << "Name: " << this->name << endl;
    cout << "Color: " << this->color << endl;
}*/