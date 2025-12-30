#ifndef MULTDIV_H
#define MULTDIV_H

#include <iostream>
#include <iomanip>
using namespace std;

struct multdiv_entry{
        int mult;
        float div;
    };

multdiv_entry** create_table(int row, int col);

void print_table(multdiv_entry** tables, int row, int col);

void delete_table(multdiv_entry** tables, int row);

#endif