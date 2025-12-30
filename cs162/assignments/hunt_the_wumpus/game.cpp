/**
** Program: game.cpp
** Author: Bruce Yan
** Date: 11/##/2022
** Description: contains game class
** Input: game variables
** Output: game message
**/
#include "game.h"

/**
** Function: Game
** Description: Constructor
** Parameters: N/A
** Pre-Conditions: sets class items
** Post-Conditions: intializes
**/
Game::Game(){
    this->side;
    this->cave = vector <vector<Room> > (this->side, vector<Room> (this->side, Room()));
}

/**
** Function: Game
** Description: non-default constructor
** Parameters: int
** Pre-Conditions: takes in an int input 
** Post-Conditions: creates a 2d of int by int size 
**/
Game::Game(int s){
    this->side = s;
    this->cave = vector <vector<Room> > (5, vector<Room> (5, Room()));
    reinitialize();
    e_arr[0] = new Gold();
    e_arr[1] = new Wumpus();
    e_arr[2] = new Bats();
    e_arr[3] = new Bats();
    e_arr[4] = new Pit();
    e_arr[5] = new Pit();
}


/**
** Function: reinitialize
** Description: initializes variables
** Parameters: N/A
** Pre-Conditions: taccess private class
** Post-Conditions: initialize values
**/
void Game::reinitialize(){
    //initialize variables
    this->n_arrows = 0;
    this->player = '*';
    this->arrow = '^';
    this->same_config = false;
    this->fire_arrow = false;
    this->move_player = false;
    this->has_gold = false;
    this->kill_wumpus = false;
    this->wake_wumpus = false;
    this->die = false;
    this->x_coord = 0;
    this->y_coord = 0;
    this->again = true;
    this->win = false;
}

/**
** Function: ~Game
** Description: destructor
** Parameters: N/A
** Pre-Conditions: checks if there are any dynamically allocated memory
** Post-Conditions: deletes memory in the heap
**/
Game::~Game(){
    for (int i = 0; i < 6; ++i){
        if (e_arr[i])
            delete e_arr[i];
        e_arr[i] = NULL;
    } 

}

/**
** Function: check_room
** Description: checks room if there is an event in it
** Parameters: int & , int & 
** Pre-Conditions: take in int input
** Post-Conditions: returns true or false
**/
bool Game::check_room(int &x, int &y){
    //return true if event pointer in room is not NULL
    if (cave[x][y].get_event_ptr() != NULL){
        return true;
    }
    else {
        return false;
    }
}

/**
** Function: gen_rand_coord
** Description: generates random coordinates
** Parameters: int &, int &
** Pre-Conditions: take in int inputs
** Post-Conditions: change by reference
**/
void Game::gen_rand_coord(int &x, int &y){
    srand(time(NULL));
    int s = this->side;
    do {
        x = rand() % s; 
        y = rand() % s;
    }while(check_room(x, y));

}

/**
** Function: assign_player
** Description: assigns player room 
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: assigns player to a room
**/
void Game::assign_player(){
    this->player_y = this->side/2;
    //stores player coordinates
    start_coord[13] = this->player_y;
    this->player_x = this->side - 1;
    //stores player coordinates
    start_coord[12] = this->player_x;
    cave[player_x][player_y].set_player(true);

}

/**
** Function: assign_rooms
** Description: assign event pointers to room
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: assign location to event pointers
**/
void Game::assign_rooms(){
    //loops through each row
    for (int i = 0; i < this->side; ++i){
        //loops through each column
        for (int j = 0; j < this->side; ++j){
            //reset the room
            cave[i][j].set_event(NULL);
            cave[i][j].set_player(false);
            cave[i][j].set_arrow(false);
            //set the room coordinates
            cave[i][j].set_room_position(i, j);
        }
    }
    //assign player a spot in the cave
    assign_player();
    //assign the events coordinates
    assign_coordinates();
    reinitialize();
}
/**
** Function: assign_coordiantes
** Description: assign coordinates to a roon/event pointers
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: assign location to event pointers
**/
void Game::assign_coordinates(){
    for (int i = 0; i < 6; ++i){
        if (this->same_config == true){
            cave[start_coord[i*2]][start_coord[i*2 + 1]].set_event(e_arr[i]);
        }
        else {
            //generate random coordinates to assign room event
            gen_rand_coord(this->x_coord, this->y_coord);
            //sets the event pointer in the room
            if (cave[this->x_coord][this->y_coord].get_player() == false){
                cave[this->x_coord][this->y_coord].set_event(e_arr[i]); 
                start_coord[i*2] = this->x_coord;
                start_coord[i*2 + 1] = this->y_coord;
            }
        }
    } 
}


/**
** Function: print_event_designator
** Description: prints event
** Parameters: int, int
** Pre-Conditions: takes in int inputs
** Post-Conditions: prints out event logos
**/
void Game::print_event_designator(int i, int j){
    if (cave[i][j].get_event_ptr() != NULL && this->debug == true){
        char e = cave[i][j].event_designator();
        cout << e;
    }
    else {
        cout << " ";
    }
}

/**
** Function: print_player
** Description: prints player icon
** Parameters: int, int
** Pre-Conditions: takes in int input
** Post-Conditions: pritns player icon
**/
void Game::print_player(int i, int j){
    //if the room has the arrow
    if (cave[i][j].get_arrow() == true){
        cout << this->arrow;
        cave[i][j].set_arrow(false);
    }
    //if the room has the player
    else if (cave[i][j].get_player() == true){
        cout << this->player;
    }
    else {
        cout << " ";
    }
}

/**
** Function: print_player_arrow
** Description: prints arrow and player
** Parameters: int, int
** Pre-Conditions: takes in int inputs
** Post-Conditions: prints out 
**/
void Game::print_arrow(int i, int j){
    if (cave[i][j].get_arrow() == true){
        cout << this->arrow;
    }

}




/**
** Function: create_cave
** Description: creates the cave
** Parameters: int 
** Pre-Conditions: take in int input
** Post-Conditions: prints cave
**/
void Game::print_cave(){ //if room has nothing in it, assing the thing to the room, but print out nothing
    int s = this->side;
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            cout << "+---+";
        }
        cout << endl;

        for (int j = 0; j < s; j++){
            //if (debug)
            cout << "| ";
            print_event_designator(i, j);
            cout << " |";
        }
        cout << endl;

        for (int j = 0; j < s; j++){
            cout << "| ";
            // print_arrow(i, j);
            print_player(i, j);
            cout << " |";
        }
        cout << endl;      
        
        for (int j = 0; j < s; j++){
            cout << "+---+";
        }
        cout << endl;         
    }
    cout << endl;
}

/**
** Function: check_surround
** Description: checks around player if there is an event around them
** Parameters: N/A
** Pre-Conditions: checks around player
** Post-Conditions: prints precept message
**/
void Game::surround_percept(){ //redo bounds
    //checks south
    if (this->player_x < this->side - 1){
        if (cave[this->player_x + 1][this->player_y].get_event_ptr() != NULL ){
            cave[this->player_x + 1][this->player_y].get_event_ptr()->percept();
        }
    }
    
    //checks north
    if (this->player_x > 0){
        if (cave[this->player_x - 1][this->player_y].get_event_ptr() != NULL ){
            cave[this->player_x - 1][this->player_y].get_event_ptr()->percept();
        }
    }

    //checks east
    if (this->player_y < this->side - 1){
        if (cave[this->player_x][this->player_y + 1].get_event_ptr() != NULL ){
            cave[this->player_x][this->player_y + 1].get_event_ptr()->percept();
        }
    }

    //checks west
    if (this->player_y > 0){
        if (cave[this->player_x][this->player_y - 1].get_event_ptr() != NULL ){
            cave[this->player_x][this->player_y - 1].get_event_ptr()->percept();
        }
    }
}

/**
** Function: surround_encounter
** Description: perfroms encounter actions
** Parameters: N/A
** Pre-Conditions: acces prviate class 
** Post-Conditions: cout statemetns
**/
void Game::surround_encounter(){ //kill wumpus 
    if (cave[this->player_x][this->player_y].get_event_ptr() != NULL){
        cave[this->player_x][this->player_y].get_event_ptr()->encounter();
    }
    
    //if player encounters gold, delete gold pointer
    if (cave[this->player_x][this->player_y].get_event_ptr() == e_arr[0]){
        this->has_gold = true;
        cave[this->player_x][this->player_y].set_event(NULL);
    }

    if (cave[this->player_x][this->player_y].get_event_ptr() == e_arr[1]){
        this->die = true;
    }
    bat_encounter();
    pit_encounter();
}

/**
** Function: bat_encounter
** Description: randomizes player location
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: moves player to another room
**/
void Game::bat_encounter(){
    if (cave[this->player_x][this->player_y].get_event_ptr() == e_arr[2] || cave[this->player_x][this->player_y].get_event_ptr() == e_arr[3]){
        cave[this->player_x][this->player_y].set_player(false);
        gen_rand_coord(this->player_x, this->player_y);
        cave[this->player_x][this->player_y].set_player(true);
    }
}

/**
** Function: pit_encounter
** Description: kills players 
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: sets die to true
**/
void Game::pit_encounter(){
    if (cave[this->player_x][this->player_y].get_event_ptr() == e_arr[4] || cave[this->player_x][this->player_y].get_event_ptr() == e_arr[5]){
        this->die = true;
    }

}


/**
** Function: move
** Description: moves player
** Parameters: string
** Pre-Conditions: takes in string input
** Post-Conditions: moves player
**/
void Game::move(){ //set bounds for moving
    //move north
    if (this->direct == "w"){
        if(this->player_x > 0){ //checks bounds
            cave[this->player_x][this->player_y].set_player(false);
            this->player_x--; //moves the player
            cave[this->player_x][this->player_y].set_player(true);
        }
    }

    //move south  
    else if (this->direct == "s"){ 
        if(this->player_x < this->side - 1){ //checks bounds
            cave[this->player_x][this->player_y].set_player(false);
            this->player_x++; //moves the player
            cave[this->player_x][this->player_y].set_player(true);
        }
    }

    //move west
    else if (this->direct == "a"){
        if(this->player_y > 0){ //checks bounds
            cave[this->player_x][this->player_y].set_player(false);
            this->player_y--; //moves the player
            cave[this->player_x][this->player_y].set_player(true);
        }
    }

    //move east
    else if (this->direct == "d"){
        if(this->player_y < this->side - 1){ //checks bounds
            cave[this->player_x][this->player_y].set_player(false);
            this->player_y++; //moves the player
            cave[this->player_x][this->player_y].set_player(true);
        }
    }
}

/**
** Function: move_arrow
** Description: fire the in game arrow
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: fires arrow
**/
void Game::move_arrow(){
    this->arrow_x = this->player_x, this->arrow_y = this->player_y; //makes arrow position same as player
    for (int i = 0; i < 3; ++i){
        cave[this->arrow_x][this->arrow_y].set_arrow(false); //resets the arrow
        make_arrow();
        pass_wump(i); // figure out the loop shit if the arrow about to hit the wumpus, the wumpus wakes up
        //if arrow is in the same room as wumpus
        if (cave[this->arrow_x][this->arrow_y].get_event_ptr() == e_arr[1] && cave[this->arrow_x][this->arrow_y].get_arrow() == true){
            hit_wump();
            break;
        }
    }
    if(this->direct == " w" || this->direct == " a" || this->direct == " s" || this->direct == " d")
        this->n_arrows++;
}

/**
** Function: make_arrow
** Description: fire the in game arrow
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: fires arrow
**/
void Game::make_arrow(){
    //fire north
    if (this->direct == " w"){
        if (this->arrow_x > 0){ //checks the bounds
            this->arrow_x--; //moves the arrow
            cave[this->arrow_x][this->arrow_y].set_arrow(true); //show the arrow
        }
    }
    //fire west
    else if (this->direct == " a"){
        if (this->arrow_y > 0){ //checks the bounds 
            this->arrow_y--; //moves the arrow
            cave[this->arrow_x][this->arrow_y].set_arrow(true); 
        }
    }
    //fire south
    else if (this->direct == " s"){
        if (this->arrow_x < this->side - 1){
            this->arrow_x++;
            cave[this->arrow_x][this->arrow_y].set_arrow(true);
        }
    }
    //fire east
    else if (this->direct == " d"){
        if(this->arrow_y < this->side - 1){
            this->arrow_y++;
            cave[this->arrow_x][this->arrow_y].set_arrow(true);
        }
    }
}

/**
** Function: error_handle_wasd
** Description: handles wasd controls
** Parameters: string
** Pre-Conditions: takes in string input
** Post-Conditions: error handles
**/
bool Game::error_handle_wasd(string s){
    int size = s.length();
    if (size > 2 || size < 1){
        cout << "That's not good input" << endl;
        cout << "Please try again" << endl << endl;
        return false;
    }
    if (!(s == "w" || s == "a" || s == "s" || s == "d" || s == " w" || s == " a" || s == " s" || s == " d")){
        cout << "That's not good input" << endl; 
        cout << "Please try again" << endl << endl;
        return false;
    }
    if(this->n_arrows > 2 && (s == " w" || s == " a" || s == " s" || s == " d")){
        cout << "no more arrows" << endl;
        return false;
    }
    return true;
}

/**
** Function: ask_direction
** Description: ask player for direction to go to
** Parameters: N/A
** Pre-Conditions: takes string input
** Post-Conditions: stores value
**/
void Game::ask_direction(){
    do{
        cout << "Use w, a, s, d to move or space before w, a, s, d to shoot an arrow: ";
        getline(cin, this->direct, '\n');
    }while(!error_handle_wasd(this->direct));
}

/**
** Function: scoreboard
** Description: displays the score board of information
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: prints to display
**/
void Game::scoreboard(){
    cout << "Board" << endl;
    cout << "Gold: "; 
    if (this->has_gold == true){
        cout << "True" << endl;
    }
    else if (this->has_gold == false){
        cout << "False" << endl;
    }
    cout << "Killed Wumpus: ";
    if (this->kill_wumpus == true){
        cout << "True" << endl;
    }
    else if (this->kill_wumpus == false){
        cout << "False" << endl;
    }
    cout << "wake wump: ";
    if (this->wake_wumpus == true){
        cout << "True" << endl;
    }
    else if (this->wake_wumpus == false){
        cout << "False" << endl;
    }
}

/**
** Function: hit_wump
** Description: 
** Parameters:
** Pre-Conditions: 
** Post-Conditions: 
**/
void Game::hit_wump(){
    this->kill_wumpus = true;
    cave[this->arrow_x][this->arrow_y].set_event(NULL);
}

/**
** Function: pass_wump
** Description: 
** Parameters:
** Pre-Conditions: 
** Post-Conditions: 
**/
void Game::pass_wump(int i){ // make a huge ass if statement and then do else if
    if(this->player_x != this->arrow_x || this->player_y != this->arrow_y){
        if (this->arrow_x < this->side - 1)
            if (cave[this->arrow_x + 1][this->arrow_y].get_event_ptr() == e_arr[1] && i == 2) //and if arrow is true or false
                wake_wump(this->arrow_x + 1, this->arrow_y);

        if (this->arrow_x > 0)
            if (cave[this->arrow_x - 1][this->arrow_y].get_event_ptr() == e_arr[1] && i == 2)
                wake_wump(this->arrow_x - 1, this->arrow_y);
        
        if (this->arrow_y < this->side - 1)
            if (cave[this->arrow_x][this->arrow_y + 1].get_event_ptr() == e_arr[1] && i == 2)
                wake_wump(this->arrow_x, this->arrow_y + 1);
        
        if (this->arrow_y > 0)
            if (cave[this->arrow_x][this->arrow_y - 1].get_event_ptr() == e_arr[1] && i == 2)
                wake_wump(this->arrow_x, this->arrow_y - 1);
    }
}

/**
** Function: wake_wump
** Description: wakes up the wumpus
** Parameters: int int
** Pre-Conditions: takes in int input
** Post-Conditions: moves wumpus or wakes it up
**/
void Game::wake_wump(int i, int j){
    if (cave[i][j].get_event_ptr() == e_arr[1]){
        this->wake_wumpus = true;
        cout << "You woke up the Wumpus! He could've moved rooms!" << endl;
        srand(time(NULL));
        int r = rand() % 100;
        if (r < 75){
            rand_assign_event(i,j,e_arr[1]);
        }
    }
}

/**
** Function: rand_assign_event
** Description: assign a room a random event
** Parameters: int, int, event*
** Pre-Conditions: take in inputs
** Post-Conditions: assigns room a random event
**/
void Game::rand_assign_event(int i, int j, Event* e_arr){
    int x = -1, y = -1;
    do {
        gen_rand_coord(x, y);
    }while(x == i && y == j);

    if (cave[x][y].get_player() == false && cave[x][y].get_event_ptr() == NULL){
        cave[i][j].set_event(NULL);
        cave[x][y].set_event(e_arr);
    }
}

/**
** Function: surround
** Description: runs both surround functions
** Parameters: N/A
** Pre-Conditions: access member functions 
** Post-Conditions: runs member functions
**/
void Game::surround(){
    if (this->die == false){
        surround_encounter(); //make sure that if encounter runs, surround runs later, if encounter then remove gold pointer
        surround_percept(); //make sure it is in bounds
    }
}


/**
** Function: win_condition
** Description: runs the winning game condition
** Parameters: N/A
** Pre-Conditions: access private class 
** Post-Conditions: display message
**/
void Game::win_condition(){
    if (cave[start_coord[12]][start_coord[13]].get_player() == true && this->has_gold == true && this->kill_wumpus == true){
        cout << "You succesfully escaped!" << endl;
        cout << "You win!" << endl;
        this->win = true;
    }
}


/**
** Function: play
** Description: plays the game
** Parameters: int
** Pre-Conditions: takes in int input 
** Post-Conditions: plays the game
**/
void Game::play(){
    while(this->again == true){
        debug_mode();
        assign_rooms();
        do {
            scoreboard();
            print_cave();
            ask_direction();
            move();
            if (this->n_arrows < 3){
                move_arrow();
            }
            surround();
            win_condition();
        }while(this->die == false && this->win == false); //create a winning statement
        play_again();
    }
}


/**
** Function: play_again
** Description: asks player to play again
** Parameters: N/A
** Pre-Conditions: takes in input  
** Post-Conditions: display message
**/
void Game::play_again(){
    string agains;
    do{
        cout << "Do you want to play again? 1-yes, 0-no: ";
        getline(cin, agains, '\n'); 
    }while(!error_handle_again(agains));


    if (agains == "1"){
        this->again = true;
        same_configuration();
    }
    else if (agains == "0"){
        this->again = false;
    }


}

/**
** Function: same_confiuration
** Description: asks player if they want to play with the same or different configuration
** Parameters: N/A
** Pre-Conditions: takes in input  
** Post-Conditions: display message
**/
void Game::same_configuration(){
    string same; 
    do{
        cout << "do you want to play with the same configuration? 1-yes, 0-no: ";
        getline(cin, same, '\n');
    }while(!error_handle_again(same));

    if (same == "1"){
        this->same_config = true;
    }
    else if  (same == "0"){
        this->same_config = false;
        ask_size();
        this->cave = vector <vector<Room> > (this->side, vector<Room> (this->side, Room()));

    }
}





/**
** Function: error_handle_again
** Description: error handles play again statemetn
** Parameters: string
** Pre-Conditions: takes in string input
** Post-Conditions: returns true or false
**/
bool Game::error_handle_again(string s){
    int size = s.length();
    if (size < 0 || size > 1){
        cout << "That's not a good input" << endl;
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if(s[i] < '0' || s[i] > '1'){ //if anything is less than ascii value of 1 or greater than ascii value 5
            cout << "That's not a good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }
    }
    return true;
}

/**
** Function: ask_size
** Description: ask user for size of cave
** Parameters: N/a
** Pre-Conditions: takes in input
** Post-Conditions: displays message
**/
void Game::ask_size(){
    string size;
    do{
        cout << "how big do you want your cave?: ";
        getline(cin, size, '\n');
    }while(!error_handle_size(size));
    
    this->side = stoi(size);
}

/**
** Function: error_handle_size
** Description: error handles size input
** Parameters: string
** Pre-Conditions: takes in string input 
** Post-Conditions: returns true or false 
**/
bool Game::error_handle_size(string s){
    int size = s.length();
    if (size == 1 && (s[0] < '4' || s[0] > '9')){
        cout << "That's not a good input" << endl;
        cout << "Please try again" << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if(s[i] < '0' || s[i] > '9'){ //if anything is less than ascii value of 1 or greater than ascii value 5
            cout << "That's not a good input" << endl; 
            cout << "Please try again" << endl;
            return false;
        }
    }
    return true;
}

/**
** Function: debug_mode
** Description: prompts if player wants to play in debug mode
** Parameters: N/A
** Pre-Conditions: takes in input 
** Post-Conditions: plays debug mode
**/
void Game::debug_mode(){
    string bug; 
    do{
        cout << "Do you want to play in debug mode? 1-yes 0-no: ";
        getline(cin, bug, '\n');
    }while(!error_handle_again(bug));

    if (bug == "1"){
        this->debug = true;
    }
    else if (bug == "0"){
        this->debug = false;
    }
}

/**
** Function: 
** Description: 
** Parameters:
** Pre-Conditions: 
** Post-Conditions: 
**/




