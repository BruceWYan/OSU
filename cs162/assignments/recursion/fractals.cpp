#include <iostream>

using namespace std;

void pattern(int n, int col){
    if (n == 0){
        return;
    }
    pattern(n/2, col);
    // A loop to print exactly col columns
    for (int i = 0; i < col; i++) 
        cout << "  ";
    // A loop to print n asterisks, each one followed by a space:
    for (int i = 0; i < n; i++) 
        cout << "* ";
    cout << endl;
    pattern(n/2, col + (n/2));
}

int main(){
    pattern(2,2);
    pattern(4,1);
    pattern(8,0);
}


