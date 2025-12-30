#include <iostream>
#include <cstdlib> 

using namespace std; 

//function: 
int* create_heap1(){
    int* p = new int;
    return p;
}
//function: 
void create_heap2(int **p){
    *p = new int;
}
//function:
void create_heap3(int* &p){
    p = new int;
}

void populate_heap1(int *p){
    *p = rand() % 5;
}

void print(int *p){
    cout << *p << endl;
}
int main(){
   srand(time(NULL)); 

   int *g = create_heap1();
   cout << "&g: " << &g << " g: " << g << endl;
   populate_heap1(g);
   print(g);

    int *f; 
    create_heap2(&f); 
    cout << "&f: " << &f << " f: " << f << endl; 
    populate_heap1(f);
    print(f);

    int *h; 
    create_heap3(h);
    cout << "&h: " << &h << " h: " << h << endl;
    populate_heap1(h);
    print(h);

    delete g;
    delete f;
    delete h;

    return 0;
}