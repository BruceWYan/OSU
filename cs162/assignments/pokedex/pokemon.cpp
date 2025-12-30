#include "pokemon.h"

using namespace std;

/**
** Function: error_handle_options
** Description: Takes in input from user and check to see if input is 1-5
** Parameters: string s
** Pre-Conditions: Takes in a string, checks string if it is correct
** Post-Conditions: returns true or false
**/
bool error_handle_options(string s){
    int size = s.length();
    if (size < 1 || size > 2){
        cout << "That's not a good input" << endl;
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if(s[i] < '1' || s[i] > '5'){ //if anything is less than ascii value of 1 or greater than ascii value 5
            cout << "That's not a good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }
    }
    return true;
}

/**
** Function: error_handle_screen_or_file
** Description: takes in input from user and checks to see if input is 1-2
** Parameters: string s
** Pre-Conditions: Takes in a string, checks string if it is correct
** Post-Conditions: returns true or false
**/
bool error_handle_screen_or_file(string s){
    int size = s.length();
    if (size < 1 || size > 2){
        cout << "That's not a good input" << endl;
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if(s[i] < '1' || s[i] > '2'){ //if anything is less than ascii value of 1 or greater than ascii value 5
            cout << "That's not a good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }
    }
    return true;
}

/**
** Function: error_handle_txt
** Description: takes in input from user and checks to see if it's correct .txt syntax
** Parameters: string s
** Pre-Conditions: Takes in a string, checks string if it is correct
** Post-Conditions: returns true or false
**/
bool error_handle_txt(string s){
    int size = s.length(); 
    if (size < 5){
        return false;
    }
    for (int i = 0; i < size - 5; i++){
        if (s[i] < 'a' || s[i] > 'z'){
            cout << "That's not a good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }
    }
    if (s.substr(size-4,size) != ".txt"){
        cout << "That's not good input" << endl; 
        cout << "Please try again" << endl;
        return false;
    }
    return true;
}

/**
** Function: error_handle_name
** Description: takes in input and checks to see if first letter is capital and rest are letters
** Parameters: string s
** Pre-Conditions: Takes in a string, checks string if it is correct
** Post-Conditions: returns true or false
**/
bool error_handle_name(string s){
    int size = s.length();
    if (s[0] < 'A' || s[0] > 'Z'){
        cout << "That's not good input" << endl; 
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 1; i < size; i++){
        if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }     
    }
    return true;
}

/**
** Function: error_handle_pos_int
** Description: checks if input is all positive ints
** Parameters: string s
** Pre-Conditions: Takes in a string, checks to see if it's an int
** Post-Conditions: returns true or false
**/
bool error_handle_pos_int(string s){
    int size = s.length();
    for (int i = 0; i < size; i++){
        if (s[i] < '0' || s[i] > '9'){
            cout << "That's not good input" << endl;
            cout << "Please try again" << endl << endl;
            return false;
        }
    }
    return true;
}

/**
** Function: create_pokemons
** Description: This function will dynamically allocate an array of Pokemons (of the requested size)
** Parameters: int size
** Pre-Conditions: takes size from pokedex.num_pokemon
** Post-Conditions: creates dynamic array in heap with size pokedex.num_pokemon
**/
Pokemon* create_pokemons(int size){
    Pokemon* p_ptr = new Pokemon[size];
    return p_ptr;
}

/**
** Function: create_moves
** Description: This function will dynamically allocate an array of moves of a Pokemon (of the requested size)
** Parameters: int size
** Pre-Conditions: takes size from pokedex.dex[i].num_moves
** Post-Conditions: creates dynamic array in heap with that size
**/
string* create_moves(int size){
    string* s_ptr = new string[size];
    return s_ptr;
}

/**
** Function: populate_pokemon
** Description: This function will fill a single Pokemon object with information that is read in from dex.txt
** Parameters: Pokemon &pokemon, ifstream &file
** Pre-Conditions: access information from file
** Post-Conditions: populate single Pokemon object 
**/
void populate_pokemon(Pokemon &pokemon, ifstream &file){
    file >> pokemon.dex_num >> pokemon.name >> pokemon.type >> pokemon.num_moves;
    pokemon.moves = create_moves(pokemon.num_moves);
    for (int i = 0; i < pokemon.num_moves; i++){
        file >> pokemon.moves[i];
    }
} 

/**
** Function: populate_pokedex_data
** Description: This function will fill a Pokedex object with information that is read in from dex.txt
** Parameters: Pokemon &pokemon, ifstream &file
** Pre-Conditions: reads in number of pokemon from file
** Post-Conditions: populates pokemon array in pokedex struct in the heap with info from the file
**/
void populate_pokedex_data(Pokedex &pokedex , ifstream &file){
    do {
        cout << "What is your name trainer?: "; 
        getline(cin, pokedex.trainer);
    }while(!error_handle_name(pokedex.trainer));

    cout << endl << "Welcome " << pokedex.trainer << " to your very own Pokedex!" << endl;
    file >> pokedex.num_pokemon;
    
    pokedex.dex = create_pokemons(pokedex.num_pokemon);
    for (int i = 0; i < pokedex.num_pokemon; i++){
        populate_pokemon(pokedex.dex[i], file);
    }
    
}

/**
** Function: delete_info
** Description: This funcdtion will delete all the memory that was dynamically allocated
** Parameters: Pokedex &pokedex
** Pre-Conditions: Access dynamic array in the heap and delete information
** Post-Conditions: array in the heap should be NULL
**/
void delete_info(Pokedex &pokedex){
    for (int i = 0; i < pokedex.num_pokemon; i++){ //runs through pokemon array
        for (int j = 0; j < pokedex.dex[i].num_moves; j++){ //runs through moves away within each index in the pokemon array
            delete [] pokedex.dex[i].moves;
            pokedex.dex[i].moves = NULL;
        }
    }
	delete [] pokedex.dex;
    pokedex.dex = NULL;
}

/**
** Function: check_file
** Description: Takes in file from user checks to see if it exists
** Parameters: ifstream &file
** Pre-Conditions: takes in file input from user, checks if the file exists
** Post-Conditions: return true or false if it exists
**/
bool check_file(ifstream &file){
    string pokedex_file;
    do{
        cout << "Please insert your Pokedex save file: ";
        getline(cin, pokedex_file);
    }while(!error_handle_txt(pokedex_file));
    file.open(pokedex_file);

    if (!file.is_open()){
		cout << "Error opening the file..." << endl;
		return 1;
	}
}

/**
** Function: display_pokedex_options
** Description: Displays options for user to choose from
** Parameters: string &options
** Pre-Conditions: displays options to user
** Post-Conditions: passes user input into options by reference
**/
void display_pokedex_options(string &options){
    do{
        cout << "Please choose from the options below by entering the number assigned to option (1-5): " << endl;
        cout << "[1] Search by dex number" << endl; 
        cout << "[2] Search by name" << endl;
        cout << "[3] Search by type" << endl;
        cout << "[4] Add new Pokemon" << endl;
        cout << "[5] Quit" << endl;
        getline(cin, options);
    }while(!error_handle_options(options));
}

/**
** Function: screen_or_file
** Description: prompts user to choose either to print to scren or file and returns choice as an int
** Parameters: N/A
** Pre-Conditions: displays options to user
** Post-Conditions: returns user option as int
**/
int screen_or_file(){
    int display = 0;
    string displays;
    do {
        cout << endl << "Would you like to display your Pokemon information on the screen or to a text file?:" << endl;
        cout << "[1] Screen" << endl;
        cout << "[2] File" << endl;
        getline(cin,displays);
    }while(!error_handle_screen_or_file(displays));
    display = stoi(displays);
    return display; //returns user choice to either display on screen or file
}

/**
** Function: print_to_screen
** Description: prints pokemon data to screen 
** Parameters: Pokedex &pokedex, int i
** Pre-Conditions: access pokemon array in heap
** Post-Conditions: display information of single pokemon based on user input
**/
void print_to_screen(Pokedex &pokedex, int i){
    cout << "Dex Number: " << pokedex.dex[i].dex_num << endl; 
    cout << "Name: " << pokedex.dex[i].name << endl;
    cout << "Type: " << pokedex.dex[i].type << endl;
    cout << "Moves:";
    for (int j = 0; j < pokedex.dex[i].num_moves; j++){
        cout << " " << pokedex.dex[i].moves[j];
    }
    cout << endl;
    cout << endl;
}

/**
** Function: print_to_file
** Description: print pokemon date to file
** Parameters: Pokedex &pokedex, int i
** Pre-Conditions: access pokemon array in heap, ask user what file they want to print to
** Post-Conditions: displays information in file chosen by user
**/
void print_to_file(Pokedex &pokedex, int i){ 
    ofstream pokemon_out;
    string pokemon_file;

    do {
        cout << "Please insert name of file you would like add this Pokemon's information to: ";
        getline(cin, pokemon_file);
    }while(!error_handle_txt(pokemon_file));

    cout << endl; 
    pokemon_out.open(pokemon_file, ios::app);
    
    pokemon_out << "Dex Number: " << pokedex.dex[i].dex_num << endl;
    pokemon_out << "Name: " << pokedex.dex[i].name << endl;
    pokemon_out << "Type: " << pokedex.dex[i].type << endl;
    pokemon_out << "Moves:"; 
    for (int j = 0; j < pokedex.dex[i].num_moves; j++){
        pokemon_out << " " << pokedex.dex[i].moves[j];
    }
    pokemon_out << endl;
    pokemon_out << endl;
    pokemon_out.close();
}

/**
** Function: search_by_dex
** Description: Searches dex number of pokemon in pokedex and displays pokemon information, either print or onto file
** Parameters: Pokedex &pokedex
** Pre-Conditions: takes in user input for what display option wanted and dex number they want to look up
** Post-Conditions: finds pokemon
**/
bool search_by_dex(Pokedex &pokedex){
    int display_option = screen_or_file(); // takes input from user either screen or file stores in to variable
    int dex = 0;
    string dexs;
    do{
        cout << "Type in the dex number of the Pokemon you want to look for: ";
        getline(cin,dexs);
    }while(!error_handle_pos_int(dexs));
    dex = stoi(dexs);
    for (int i = 0; i < pokedex.num_pokemon; i++){
        if (dex == pokedex.dex[i].dex_num){
            //variable decides what to do
            if (display_option == 1){ 
                print_to_screen(pokedex, i);
            }
            else if (display_option == 2){
                print_to_file(pokedex, i);
            }
            return false; //if we have a match, then we will break the loop by returning false
        }
    }
    cout << "There was no Pokemon with that dex number!" << endl;
    cout << "Please Try again!" << endl;
    return false; //if we don't find any match will return false
}

/**
** Function: search_by_name
** Description: searches name of pokemon in pokedex and displays information, either print or onto file
** Parameters: Pokedex &pokedex
** Pre-Conditions: takes in user input for what display option wanted and name they want to look up
** Post-Conditions: finds pokemon
**/
bool search_by_name(Pokedex &pokedex){
    int display_option = screen_or_file();
    string name;

    do{
        cout << "Type in the name of the Pokemon you want to look for: ";
        getline(cin, name);
    }while(!error_handle_name(name));

    for (int i = 0; i < pokedex.num_pokemon; i++){
        if (name == pokedex.dex[i].name){
            if (display_option == 1){
                print_to_screen(pokedex, i);
            }
            else if (display_option == 2){  
                print_to_file(pokedex, i);
            }
            return false; //if we have a match, then we will break the loop by returning true
        }
    }
    cout << "There was no Pokemon with that name!" << endl;
    cout << "Please Try again!" << endl;
    return false; //if we don't find any match will return false
    //cout a statement at the end that they did not find pokemon by name
}

/*
** Function: print_types_to_screen
** Description: print all pokemon with same type to screen
** Parameters: Pokedex &pokedex, string type
** Pre-Conditions: takes types from user input
** Post-Conditions: displays to screen all information of pokemon with same type
*/
void print_types_to_screen(Pokedex &pokedex, string type){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        if (type == pokedex.dex[i].type){
            print_to_screen(pokedex, i); 
        }
    }
}

/**
** Function: print_types_to_file
** Description: print all pokemon with same type to file
** Parameters: Pokedex &pokedex, string type
** Pre-Conditions: takes in file from user and type by user
** Post-Conditions: displays to file all information of pokemon with same type
**/
void print_types_to_file(Pokedex &pokedex, string type){
    ofstream pokemon_out;
    string pokemon_file;
    do {
        cout << "Please insert name of file you would like add this Pokemon's information to: ";
        getline(cin, pokemon_file);
    }while(!error_handle_txt(pokemon_file));
    cout << endl;
    pokemon_out.open(pokemon_file, ios::app);
    
    for (int i = 0; i < pokedex.num_pokemon; i++){
        if (type == pokedex.dex[i].type){
            pokemon_out << "Dex Number: " << pokedex.dex[i].dex_num << endl;
            pokemon_out << "Name: " << pokedex.dex[i].name << endl;
            pokemon_out << "Type: " << pokedex.dex[i].type << endl;
            pokemon_out << "Moves:"; 
            for (int j = 0; j < pokedex.dex[i].num_moves; j++){
                pokemon_out << " " << pokedex.dex[i].moves[j];
            }
            pokemon_out << endl;
            pokemon_out << endl;
        }
    }
    pokemon_out.close();
}

/**
** Function: search_by_type
** Description: searches the type of pokemons in pokedex and displays all information of pokemon with same type, either on screen or file
** Parameters: Pokedex &pokedex
** Pre-Conditions: 
** Post-Conditions:
**/
bool search_by_type(Pokedex &pokedex){
    int display_option = screen_or_file();
    int ctr = 0;
    string type;
    do {
        cout << "Type in the type of Pokemon you want to look for: ";
        getline(cin, type);
    }while(!error_handle_name(type));
    for (int i = 0; i < pokedex.num_pokemon; i++){ //checks to see if type actually exists
        if (type == pokedex.dex[i].type){
            ctr++; //if type exists add 1
        }
    }

    if (ctr == 0){ //if nothing was added, then type does not exist, return false
        cout << "There was no Pokemon with that type!" << endl;
        cout << "Please Try again!" << endl;
        return false;
    }

    else { 
        if (display_option == 1){
            print_types_to_screen(pokedex, type);
        }
        else if (display_option == 2){
            print_types_to_file(pokedex, type);
        }
    }
}

/**
** Function: populate_temp_pokemon
** Description: Moves pokemon data for single pokmeon from pokedex.dex array to tempdex.dex
** Parameters: Pokedex &pokedex, Pokemon &dex, Pokemon &temp_poke
** Pre-Conditions: stores info from original pokemon array to temp pokemon array
** Post-Conditions: populate temp pokemon array
**/
void populate_temp_pokemon(Pokedex &pokedex, Pokemon &dex, Pokemon &temp_poke){
    temp_poke.dex_num = dex.dex_num;
    temp_poke.name = dex.name;
    temp_poke.type = dex.type;
    temp_poke.num_moves = dex.num_moves;
    temp_poke.moves = create_moves(temp_poke.num_moves);
    for (int j = 0; j < temp_poke.num_moves; j++){
        temp_poke.moves[j] = dex.moves[j];
    }
}

/**
** Function: populate_new_pokemon
** Description: Moves pokemon data for single pokemon from tempdex.dex back into newly dynamically sized pokedex.dex
** Parameters: Pokedex &pokedex, Pokemon &dex, Pokemon &temp_poke
** Pre-Conditions: stores info from temp pokemon array into new sized pokemon array
** Post-Conditions: populates new sized array
**/
void populate_new_pokemon(Pokedex &pokedex, Pokemon &dex, Pokemon &temp_poke){
    dex.dex_num = temp_poke.dex_num ;
    dex.name = temp_poke.name;
    dex.type = temp_poke.type;
    dex.num_moves = temp_poke.num_moves;
    dex.moves = create_moves(dex.num_moves);
    for (int j = 0; j < dex.num_moves; j++){
        dex.moves[j] = temp_poke.moves[j];
    }
}

/**
** Function: delete_temp_dex
** Description: Deletes memory in heap allocated for the tempdex.dex
** Parameters: Pokedex &pokedex, Pokedex &tempdex
** Pre-Conditions: access temporary pokemon array and deletes it
** Post-Conditions: pokemon array should be set to NULL
**/
void delete_temp_dex(Pokedex &pokedex, Pokedex &tempdex){
    for (int i = 0; i < pokedex.num_pokemon - 1; i++){
        for (int j = 0; j < tempdex.dex[i].num_moves; j++){
            if (tempdex.dex[i].moves){
                delete [] tempdex.dex[i].moves;
                tempdex.dex[i].moves = NULL;
            }
        }
    }
    if(tempdex.dex){
	    delete [] tempdex.dex;
        tempdex.dex = NULL;
    }
}

/**
** Function: populate_new_temp_data
** Description: This function will fill a pokedex object with information and dynamically resize array
** Parameters: Pokedex &pokedex, Pokedex &tempdex
** Pre-Conditions: creates temp pokemon array get info from orig. pokemon array and delete it
** Post-Conditions: creates orig. pokmeon array with different size and gets info from temp pokemon array and deletes it
**/
void populate_new_temp_data(Pokedex &pokedex, Pokedex &tempdex){
    tempdex.dex = create_pokemons(pokedex.num_pokemon);
    for (int i = 0; i < pokedex.num_pokemon; i++){
        populate_temp_pokemon(pokedex, pokedex.dex[i], tempdex.dex[i]);
    }
    delete_info(pokedex); //temp array has same size as old array

    pokedex.num_pokemon++; //changes size of number of pokemon to be used to resize the array

    pokedex.dex = create_pokemons(pokedex.num_pokemon); //same array with new size
    for (int i = 0; i < pokedex.num_pokemon - 1; i++){
        populate_new_pokemon(pokedex, pokedex.dex[i], tempdex.dex[i]);
    }
    delete_temp_dex(pokedex, tempdex);
}

/**
** Function: add_new_pokemon
** Description: Takes user input information for new pokemon from user and stores into pokemon object in pokedex
** Parameters: Pokedex &pokedex, Pokedex &tempdex
** Pre-Conditions: creates new array, takes input from user
** Post-Conditions: stores input from user into new array
**/
void add_new_pokemon(Pokedex &pokedex, Pokedex &tempdex){ //not error handled
    populate_new_temp_data(pokedex, tempdex);
    cout << "Please enter in the following parameters: " << endl;
    string dex, name, type, num_moves, moves;

    do{
        cout << "Dex Number: ";
        getline(cin, dex);
    }while(!error_handle_pos_int(dex));
    pokedex.dex[pokedex.num_pokemon - 1].dex_num = stoi(dex);

    do{
        cout << "Name: ";  
        getline(cin, name);
    }while(!error_handle_name(name));
    pokedex.dex[pokedex.num_pokemon - 1].name = name;

    do{
        cout << "Type: ";
        getline(cin, type);
    }while(!error_handle_name(type));
    pokedex.dex[pokedex.num_pokemon - 1].type = type;

    do{
        cout << "Number of Moves: ";
        getline(cin, num_moves);
    }while(!error_handle_pos_int(num_moves));
    pokedex.dex[pokedex.num_pokemon - 1].num_moves = stoi(num_moves);

    cout << "Please enter moves individually in this format (Vine_whip): ";
    pokedex.dex[pokedex.num_pokemon - 1].moves = create_moves(pokedex.dex[pokedex.num_pokemon - 1].num_moves);
    for (int i = 0; i < pokedex.dex[pokedex.num_pokemon - 1].num_moves; i++){
        do{
            cout << "Move " << i + 1 << ": "; 
            getline(cin,moves);
        }while(!error_handle_name(moves));
        pokedex.dex[pokedex.num_pokemon - 1].moves[i] = moves;
    }
}

/**
** Function: quit
** Description: Prints out function telling user they have quitted the program
** Parameters: N/A
** Pre-Conditions: user must choose this option
** Post-Conditions: quits the program
**/
void quit(){
    cout << "Thank you for using the great Pokedex!" << endl;
    cout << "Goodbye!" << endl;
}

/**
** Function: store_options
** Description: Takes user input for options and runs function of chosen option
** Parameters: Pokedex &pokedex, Pokedex &tempdex, string &options, bool &result
** Pre-Conditions: takes input from user 
** Post-Conditions: runs function of option chosen by user
**/
void store_options(Pokedex &pokedex, Pokedex &tempdex, string &options, bool &result){
    int option = 0;
    option = stoi(options);
    if (option == 1){
        search_by_dex(pokedex);
        result = false;
    }

    else if (option == 2){
        search_by_name(pokedex);
        result = false;
    }

    else if (option == 3){
        search_by_type(pokedex);
        result = false;
    }

    else if (option == 4){
        add_new_pokemon(pokedex, tempdex);
        result = false;
    }

    else if (option == 5){
        quit();
        result = true;
    }
}