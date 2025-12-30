/**
** Program: recursive_fractal.cpp
** Author: Bruce Yan
** Date: 12/04/2022
** Description: prints out a fractal pattern reursively
** Input: positive, odd integer, n and non-negative integer, col
** Output: fractal pattern
**/
#include <iostream> 

using namespace std;

void pattern(int, int);

int main(){
    // cout << "pattern(3, 2)" << endl; 
    // pattern(3,2);
    // cout << "pattern(5, 1)" << endl;
    // pattern(5,1);
    // cout << "pattern(7, 0)" << endl;
    // pattern(7,0);
    int n = 0;
    int col = 0;
    cout << "How many asteriks would you want to print out? (odd number): ";
    cin >> n;
    cout << "How many blank spaces in front of the asteriks would you want to print out? (positive number): ";
    cin >> col;

    cout << "pattern(" << n << ", " << col << ")" << endl;
    pattern(n, col);
}

/**
** Function: pattern
** Description: creates a fractal pattern recursively
** Parameters: int, int
** Pre-Conditions:  n is an positive odd number, col is a non negative integer
** Post-Conditions: a pattern is printed out
**/
void pattern(int n, int col){
    //when n is less than 1 we exit the function
    if (n < 1){
        return;
    }
    else {
        //subtract n until we get n < 1, when n is 1, we print 1 asterik 
        pattern(n-2, col + 1); 
        //prints out the line of asteriks that user inputted
        for (int i = 0; i < col; ++i){
            cout << "  ";
        }
        for (int i = 0; i < n; ++i){
            cout << "* ";
        }
        cout << endl;    
        //prints out the rest of the pattern
        pattern(n-2, col + 1);        
    }    
}