/**
** Program: driver.cpp
** Author: Bruce Yan
** Date: 10/23/2022
** Description: Acts as pokedex that displays and stores pokemon information
** Input: Takes in user input either as a string or int to choose options or take pokemon information
** Output: Displays pokemon information on the screen or a file
**/

#include "pokemon.h"

using namespace std;

int main(){
    ifstream file; 
    Pokedex pokedex;
    Pokedex tempdex;
    bool result = false;

    if(check_file(file)){
        return 1;
    }    
    populate_pokedex_data(pokedex, file);
    
    file.close();

    do{
        string options;
        display_pokedex_options(options);    
        store_options(pokedex, tempdex, options, result);
    }while(result == false);

    delete_info(pokedex);

    return 0;
}