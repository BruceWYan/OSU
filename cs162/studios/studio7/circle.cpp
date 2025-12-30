#include "circle.h"

using namespace std;

Circle::Circle(const string name, string c, float r) : Shape (name){
    this->color = c;
    this->radius = r;
}

float Circle::area() const{
    float area_circle = (this->radius * this->radius * 3.14);
    return area_circle;
}

float Circle::get_radius(){
    return this->radius;
}

void Circle::set_radius(float new_radius){
    this->radius = new_radius;
}

void Circle::print_shape() const{
    float area_circle = area();
    cout << "Name: " << this->name << endl;
    cout << "Color: " << this->color << endl;
    cout << "Radius: " << this->radius << endl;
    cout << "Area: " << area_circle << endl;
}

