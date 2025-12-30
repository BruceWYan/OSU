#ifndef POKEMON_H
#define POKEMON_H

#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

//error handle functions
bool error_handle_options(string s);
bool error_handle_screen_or_file(string s);
bool error_handle_txt(string s);
bool error_handle_name(string s);
bool error_handle_pos_int(string s);

//required functions
Pokemon* create_pokemons(int size);
string* create_moves(int size);
void populate_pokemon(Pokemon &pokemon, ifstream &file); 
void populate_pokedex_data(Pokedex &pokedex , ifstream &file);
void delete_info(Pokedex &pokedex);

//checks if file exists
bool check_file(ifstream &file);

//displays options
void display_pokedex_options(string &options);

//choose screen of rile to print
int screen_or_file();

//seach by dex and name functions
void print_to_screen(Pokedex &pokedex, int i);
void print_to_file(Pokedex &pokedex, int i);
bool search_by_dex(Pokedex &pokedex);
bool search_by_name(Pokedex &pokedex);

//search by type functions
void print_types_to_screen(Pokedex &pokedex, string type);
void print_types_to_file(Pokedex &pokedex, string type);
bool search_by_type(Pokedex &pokedex);

//add pokemon functions
void populate_temp_pokemon(Pokedex &pokedex, Pokemon &dex, Pokemon &temp_poke);
void populate_new_pokemon(Pokedex &pokedex, Pokemon &dex, Pokemon &temp_poke);
void delete_temp_dex(Pokedex &pokedex, Pokedex &tempdex);
void populate_new_temp_data(Pokedex &pokedex, Pokedex &tempdex);
void add_new_pokemon(Pokedex &pokedex, Pokedex &tempdex);

//quit function
void quit();

//gets options from user
void store_options(Pokedex &pokedex, Pokedex &tempdex, string &options, bool &result);

#endif