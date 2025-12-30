#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(const string name, string c, float w, float h) : Shape (name){
    this->color = c;
    this->width = w;
    this->height = h;
}

float Rectangle::area() const{
    //float w = get_width();
    //float h = get_height();
    float area_rectangle = this->width * this->height;
    return area_rectangle;
}
/*float Rectangle::get_width(){
    return this->width;
}

float Rectangle::get_height(){
    return this->height;
}

void Rectangle::set_width_r(float new_width){
    this->width = new_width;
}

void Rectangle::set_height_r(float new_height){
    this->height = new_height;
}*/

void Rectangle::print_shape() const{
    float area_rect = area();
    cout << "Name: " << this->name << endl;
    cout << "Color: " << this->color << endl;
    cout << "Width: " << this->width << endl;
    cout << "Height: " << this->height << endl;
    cout << "Area: " << area_rect << endl;
}