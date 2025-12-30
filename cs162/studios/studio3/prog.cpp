#include "multdiv.h"

using namespace std;
int main(){
    int again = 0;
    
    do{
    int row = 0;
    int col = 0;

    cout << "How many rows do you want: ";
    cin >> row;

    cout << "How many columns do you want: ";
    cin >> col;


    
    multdiv_entry** tables = create_table(row, col);
    print_table(tables, row, col);
    delete_table(tables, row);
    cout << "would like you to make another table with different columns and rows? 1- yes 0-no: ";
    cin >> again;
    }while(again == 1);
}
