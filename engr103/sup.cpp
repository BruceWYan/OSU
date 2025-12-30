#include <iostream> 

using namespace std;

int main() {
    int n =13, m =16; 
    int* np= &m;
    *np = 10;
    
    cout << np << endl;
    cout << &n << endl;
    cout << &m << endl;
    cout << *np << endl;
    cout << m << endl;

}
