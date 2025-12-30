#include <iostream>


#include <cmath>
using namespace std;



bool PowerOfTwo(int n){
    if ((n & (n - 1)) == 0 && n != 1)
        return true;
    return false;
}
int star(int n){
    int i = n, ans = 0;
    while(i % 2 == 0){
        i /= 2;
        ans++;
    }
    return pow(2, ans);
}

int spaces(int n){
   if(PowerOfTwo(n) == true)
        return 0;
    return (n - 1) / 2;
}
void printpattern(int n){
    int i, sp, st;
    sp = spaces(n);
    for(i = 1; i <= sp; i++)
        cout << "  ";
    st = star(n);
    for(i = 1; i <= st; i++)
        cout << "* ";
}

void print_the_spaces(int spaces){
    if (spaces == 0){
        return;
    }
    for (int j = 0; j < spaces; j++){
        cout << "  ";
    }
}

void pattern(int n, int col){
    int i, j, sp;
    for(i = 1; i<= n; i++){
        print_the_spaces(col);               
        printpattern(i);
        cout << endl;
    }
    sp = n/2;
    for(i = 1; i<= n - 1; i++){             
        for(j = 1; j <= sp; j++)
            cout << "  ";
        print_the_spaces(col);
        printpattern(i);
        cout << endl;
    }
}

int main(){

    cout << "Pattern 2,2" << endl;
    pattern(2,2);
    cout << "Pattern 4,1" << endl;
    pattern(4,1);
    cout << "Pattern 8,0" << endl;
    pattern(8,0);



    return 0;
}