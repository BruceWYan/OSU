#include "circle.h"
#include "square.h"

#include <vector>


using namespace std;

void print_shape_info(Shape *some){
    some->print_shape();
    cout << endl;
}

int main(){
    /*string shape1 = "some shape";
    //Shape s1(shape1);
    //s1.print_shape();

    cout << endl;

    string c_name = "some circle";
    Circle c(c_name);
    c.print_circle();

    cout << endl;

    string r_name = "some rectangle";
    Rectangle r(r_name);
    r.print_rectangle();

    cout << endl;

    string s_name = "some square";
    float ss = 4;
    Square s(s_name);
    s.set_width(ss);
    s.set_height(ss);
    s.print_square();*/

    /*Circle c("some circle", "some green", 6);
    print_shape_info(&c);

    Rectangle r("some rectangle", "some red", 4, 5);
    print_shape_info(&r);

    Square s("some square", "some blue", 5, 5);
    print_shape_info(&s);*/

    string c_name = "some circle";
    string r_name = "some rectangle";
    string s_name = "some square";

    string color = "some color";

    float w = 4;
    float h = 5;
    float radius = 6;


    Shape** shp_arr = new Shape* [10];
    shp_arr[0] = new Circle(c_name, color, radius);
    shp_arr[1] = new Rectangle(r_name, color, w, h);
    shp_arr[2] = new Square(s_name, color, w, w);
    shp_arr[3] = new Circle(c_name, color, radius);
    shp_arr[4] = new Rectangle(r_name, color, w, h);
    shp_arr[5] = new Square(s_name, color, w, w);
    shp_arr[6] = new Circle(c_name, color, radius);
    shp_arr[7] = new Rectangle(r_name, color, w, h);
    shp_arr[8] = new Square(s_name, color, w, w);
    shp_arr[9] = new Circle(c_name, color, radius);

    vector <Shape *> shapes;

    for (int i = 0; i < 10; i++){
        shapes.push_back(shp_arr[i]);
    } 



 
    for (int i = 0; i< 10; i++){
        print_shape_info(shapes[i]);
    }    
    
    for (int i = 0; i < 10; i++){
        delete shp_arr[i];
        shp_arr[i] = NULL;
    }

    delete [] shp_arr;
    shp_arr = NULL;



}
