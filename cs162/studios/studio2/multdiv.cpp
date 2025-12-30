#include "multdiv.h"

using namespace std;

multdiv_entry** create_table(int row, int col){
    multdiv_entry** tables;
    tables = new multdiv_entry*[row];
    for (int p = 0; p < row; p++){
        tables[p] = new multdiv_entry [col]; 
    }

    //create tables
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            tables[i][j].mult = (i + 1) * (j + 1);
            tables[i][j].div = (i + 1.00)/(j + 1.00);
        }
    }

    return tables;

}

void print_table(multdiv_entry** tables, int row, int col){
    cout << "Multiplication Table" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
           cout << setprecision(2) << setw(6) << tables[i][j].mult;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Division Table" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
           cout << setw(6) << tables[i][j].div;
        }
        cout << endl;
    }
}

void delete_table(multdiv_entry** tables, int row){
    for (int i = 0; i < row; i++){
        delete[] tables[i];
        tables[i] = NULL;
    }

    delete[] tables;
    tables = NULL;
}