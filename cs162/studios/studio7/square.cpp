#include "square.h"

Square::Square(const string name, string c, float w, float h) : Rectangle (name, c, w, h){
    
}

/*void Square::set_width(float new_width){
    set_width_r(new_width);
}

void Square::set_height(float new_height){
    set_height_r(new_height);
}*/

void Square::print_square() const{
    print_shape();
}