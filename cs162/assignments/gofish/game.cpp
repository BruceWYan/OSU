/**
** Program: Game.cpp
** Author: Bruce Yan
** Date: 11/7/2022
** Description: function file for Game class functions
** Input: Takes in input from user, usually to prompt next part of game
** Output: display information relating to the actual logic of the game
**/

#include "game.h"
#include "hand.h"

/**
** Function: error_handle_name
** Description: error handles name
** Parameters: string 
** Pre-Conditions: takes in a string s parameters, which is name input
** Post-Conditions: returns true or false
**/
bool Game::error_handle_name(string s){
    int size = s.length();
    for (int i = 0; i < size; i++){
        if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

/**
** Function: error_handle_single_letter
** Description: error handles single letter input of "g"
** Parameters: string 
** Pre-Conditions: takes in a string input
** Post-Conditions: returns true or false if input is letter "g"
**/
bool Game::error_handle_single_letter(string s){
    int size = s.length();
    if (size > 1 || size < 1){
        cout << "That's not good input" << endl;
        cout << "Please try again" << endl << endl;
    }
    for (int i = 0; i < size; i++){
        if (!(s[i] == 'g')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

/**
** Function: error_handle_single_int
** Description: errors handles a single integer 
** Parameters: string 
** Pre-Conditions: takes in user input
** Post-Conditions: returns true or false
**/

bool Game::error_handle_single_int(string s){
    int size = s.length();
    if (size < 1 || size > 2){
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
** Function: deal_card
** Description: removes cards from deck and adds to each player's hand
** Parameters: N/A
** Pre-Conditions: have deck and player hands initialized
** Post-Conditions: deal 7 cards to each player from the deck
**/
void Game::deal_card(){
	for (int i = 0; i < 14; i++){
		Card c = this->d.remove_card();
		this->players[i%2].place_a_card(c);
	}
}

/**
** Function: debug_mode
** Description: prompts user to choose to view in debug mode 
** Parameters:
** Pre-Conditions: takes in user input
** Post-Conditions: returns true of false
**/
bool Game::debug_mode(){
    string debug;
    do{
        cout << "Do you want to be in debug mode? (1 - yes, 0 - no): ";
        getline(cin, debug, '\n');
    }while(!error_handle_single_int(debug));
    if (debug == "0"){
        return false;
    }
    else if(debug == "1"){
        return true;
    }
}

/**
** Function: welcome
** Description: prompts the user a welcome statment and asks for name
** Parameters: string &
** Pre-Conditions: initialize string name variable
** Post-Conditions: stores user name in name variable
**/
void Game::welcome(string &name){
    cout << "Welcome to GoFishLandia, where our goal is play GoFish!" << endl;
    do{
        cout << "What is your name: "; 
        getline(cin, name, '\n');
    }while(!error_handle_name(name));
    cout << "Hello~! " << name << " get ready to play!" << endl;
}

/**
** Function: player_hand
** Description: displays user hand
** Parameters: N/A
** Pre-Conditions: player class read_hand function created
** Post-Conditions: read the players hand and displays info
**/
void Game::player_hand(){
    cout << "Your Hand" << endl; 
    players[0].display_hand();
    cout << endl;
    int n_books = players[0].get_n_books();
    cout << "# Books: " << n_books << endl;
    /*cout << "Books: ";
    for (int i = 0; i < n_books; ++i){
        cout << players[0].get_books(i) << " ";
    }*/
    cout << endl;
}

/**
** Function: comp_hand
** Description: display computer hand
** Parameters: N/A
** Pre-Conditions: player class read_hand function created
** Post-Conditions: read the computers hand and displays info
**/
void Game::comp_hand(){
    cout << "Computer Hand" << endl;
    players[1].display_hand();
    cout << endl;
    int n_books = players[1].get_n_books();
    cout << "# Books: " << n_books << endl;
    /*cout << "Books: ";
    for (int i = 0; i < n_books; ++i){
        cout << players[1].get_books(i) << " ";
    }*/
    cout << endl;
}

/**
** Function: player_ask
** Description: gets player input on what card they want to ask the computer for
** Parameters: string &
** Pre-Conditions: display options user can choose from to ask computer
** Post-Conditions: stores user input into ask variable
**/
void Game::player_ask(string &ask){
    do{
        cout << endl << "Player ask options: ";
        //display ask options
        players[0].get_options();
        cout << endl << "What card do you want to ask for?: ";
        //takes in options as input and pass by reference
        getline(cin, ask, '\n');
    }while(!this->players[0].error_handle_options(ask));
}

/**
** Function: comp_ask
** Description: displays computer asking options and randomly chooses rank to ask player
** Parameters: string &, bool
** Pre-Conditions: get debug to see if comp hand should be shown
** Post-Conditions: passes the rank computer will ask user in ask variable
**/
void Game::comp_ask(string &ask, bool debug){
    //cout << endl;
    if (debug){
        cout << "Computer ask options: ";
        players[1].get_options();
    }
    srand(time(NULL));
    int cards = players[1].get_hand()->get_n_cards();
    int rand_ask = rand() % (cards);
    ask = players[1].get_hand()->get_card(rand_ask).map_rank();
    cout << endl << "Computer asked for: " << ask << endl;
    cout << "Enter to continue" << endl;
    string enter;
    getline(cin, enter, '\n');
}

/**
** Function: unmap_rank
** Description: unmaps a string rank to get corresponding rank as an int
** Parameters: string
** Pre-Conditions: takes in a string parameter
** Post-Conditions: returns an int
**/
int Game::unmap_rank(string rank){ //conver string rank to corresponding int
    int ranks;
    if (rank.empty()){
        return -1;
    }
    if (rank == "A"){
        ranks = 0;
        return ranks;
    }
    else if (rank == "J"){
        ranks = 10;
        return ranks; 
    }
    else if (rank == "Q"){
        ranks = 11;
        return ranks;
    }
    else if (rank == "K"){
        ranks = 12; 
        return ranks;
    }
    else {
        ranks = stoi(rank) - 1;
        return ranks;
    }
}

/**
** Function: steal_cards
** Description: steal the cards of the opponenet
** Parameters: string, int, int
** Pre-Conditions: passes in the rank of the card that was asked for and players
** Post-Conditions: takes cards from opponent hand and adds to player hand
**/
void Game::steal_cards(string rank, int player, int opponent){
    Card c;  
    int ranks = unmap_rank(rank);
    while(players[opponent].check_hand(rank)){
        players[opponent].take_a_card(ranks, c);
        players[player].place_a_card(c);
        //make if statement to see who receied what from who
        cout << endl;
        if (player == 0){
            cout << "You ";
        }
        else if (player == 1){
            cout << "Comp ";
        }
        cout << "Received ";
        c.print_card();
    } 


    cout << "Enter to continue" << endl;
    string enter;
    getline(cin, enter, '\n');
    
}

/**
** Function: go_fish
** Description: prompts user to press g to continue after card player asked is not in comp hand
** Parameters: N/A
** Pre-Conditions: comp hand does not have card player asked
** Post-Conditions: displays message
**/
void Game::go_fish(){
    string gf;
    cout << endl << "Your opponent does not have the card you're asking for!" << endl;
    cout << "Go Fish!" << endl;
    do{
        cout << "Enter g to continue: ";
        getline(cin, gf, '\n'); 
    }while(!error_handle_single_letter(gf));
    cout << endl;
}

/**
** Function: go_fish_player
** Description: prompts user to press g to tell computer to "go fish"
** Parameters: N/A
** Pre-Conditions: player does not have card that comptuer asked for 
** Post-Conditions: displays message
**/
void Game::go_fish_player(){
    cout << "You don't have the card your opponent asked for!" << endl;
    string gf;
    do{
        cout << "Press g to tell your opponent to go fish!: "; 
        getline(cin, gf, '\n');
    }while(!error_handle_single_letter(gf));

    if (gf == "g"){
        cout << "Go Fish!" << endl << endl;
    }
}

void Game::books(int player, string ask){
    Card c;
    int rank = unmap_rank(ask);
    if (players[player].has_books(rank)){
        players[player].remove_a_book_from_hand(rank, ask);
        players[player].add_a_book(rank);
    }
}

/**
** Function: draw_stock
** Description: player draws card from the deck
** Parameters: int, string, bool
** Pre-Conditions: opponent does not have card asked
** Post-Conditions: return a card to player hand, remove card from deck
**/
void Game::draw_stock(int player, string ask, bool &m){
    if (d.get_n_cards() == 0){
        return;
    }
    //return a card from the deck to the player/comp
    Card c = d.remove_card();
    //add a card function
    players[player].place_a_card(c);
    
    if (player == 0){
        cout << "You drew a ";
    }
    else if (player == 1){
        cout << "Computer drew a ";
    }
    c.print_card(); 
    cout << "Enter to continue" << endl;
    string enter;
    getline(cin, enter, '\n');

    //if card matches ask return true for player turn again
    if (!players[player].empty_hand()){
        string stuff = c.map_rank();
        books(player, stuff);
        int rank = unmap_rank(ask);
        if (c.get_rank() == rank){
            //player turn again
            m = true;
        }
        else {
            //opponent turn
            m = false;
        }
    }
}

/**
** Function: has_ask
** Description: opponent has the cards player asked for, thus steal cards
** Parameters: string, int, int
** Pre-Conditions: opponent as the cards player asked for
** Post-Conditions: remove all cards asked from opponent and add into player hand
**/
void Game::has_ask(string ask, int player, int opponenent){
    int rank = unmap_rank(ask);
    //removes asked card from opponent hand and adds to player hand
    steal_cards(ask, player, opponenent);
    //check hand if player has books
    books(player, ask);
}

/**
** Function: player_turn
** Description: runs player turn
** Parameters: string &, bool &
** Pre-Conditions: it is player turn
** Post-Conditions: run player turn
**/
void Game::player_turn(string ask, bool &again){
    int player = 0, comp = 1;
    if (!players[0].empty_hand()){
        player_ask(ask);
    }
    //check computer hand have cards
    else if (players[0].empty_hand()){
        draw_stock(player, ask, again);
        player_ask(ask);
    }

    if (players[1].empty_hand()){
        draw_stock(player, ask, again); //unsure
    }
    
    //comp does have ask
    if (players[1].check_hand(ask)){
        has_ask(ask, player, comp); //works
        again = true;
    }
    
    //comp doesn't have ask
    else if(!players[1].check_hand(ask)){
        go_fish();
        draw_stock(player, ask, again); //works
    }

}

/**
** Function: comp_turn
** Description: runs computer turn
** Parameters: string &, bool &, bool
** Pre-Conditions: it is comptuer turn
** Post-Conditions: run comptuer turn
**/
void Game::comp_turn(string ask, bool &again, bool debug){
    int player = 0, comp = 1;
    bool cont = false;
    if (!players[1].empty_hand()){
        comp_ask(ask, debug);
    }
    else if (players[1].empty_hand()){
        draw_stock(comp, ask, again);
        comp_ask(ask, debug);
    }

    if (players[0].empty_hand()){
        draw_stock(comp, ask, again); //unsure
    }
    //if player has the ask
    if (players[0].check_hand(ask)){
        has_ask(ask, comp, player); 
        again = true;
    }
    //player does not have ask
    else if(!players[0].check_hand(ask)){
        go_fish_player(); 
        draw_stock(comp, ask, again);
    }
    books(comp, ask);
}

/**
** Function: update_display
** Description: shows player hand or computer hand/deck
** Parameters: bool
** Pre-Conditions: pass in debug 
** Post-Conditions: dispay hands/deck
**/
void Game::update_display(bool debug){ //take in a bool from user if they want to operate in debug mode
    int d_cards = d.get_n_cards();
    cout << endl << "Deck: " << d_cards << endl;
    if (debug){
       //d.print_deck(); 
       //display books for each player
       cout << endl;
       comp_hand();
       cout << endl;
    }
    
    player_hand();
}

/**
** Function: end_game
** Description: signals the end of the game
** Parameters: N/A
** Pre-Conditions: checks books
** Post-Conditions: returns true or false
**/
bool Game::end_game(){
    int total_hand = players[0].get_hand_n_cards() + players[1].get_hand_n_cards();
    int total_books = players[0].get_n_books() + players[1].get_n_books();
    if (total_hand == 0){
        return true;
    }
    else if (total_books == 13){
        return true;
    }
    else {
        return false;
    }
}

/**
** Function: game_logic
** Description: runs player or computer turn
** Parameters: string &, bool 
** Pre-Conditions: chooses which player goes first
** Post-Conditions: runs the game
**/
void Game::game_logic(string ask, bool debug){
    srand(time(NULL));
    int rands = rand() % 2;

    bool player, comp;
    do {
        if (!end_game() && (rand == 0 || !comp)){
            do{
                update_display(debug); 
                player_turn(ask, player); //when computer asks for card player does not have, prompt a message and enter
            }while(!end_game() && player);  
        }
        if (!end_game() && (rands == 1 || !player)){
            do {
                update_display(debug);
                comp_turn(ask, comp, debug);
            }while(!end_game() && comp);
        }
        rands = -1;
    } while ((!comp || !player) && !end_game()); // need end game condition
    //work on books issue
}

/**
** Function: play_again
** Description: signals if the player wants to play again
** Parameters: string
** Pre-Conditions: takes in a string input
** Post-Conditions: returns true or false
**/
bool Game::play_again(){
    string again;
    do {
        cout << "Do you want to play again? (1-yes, 0-no): ";
        getline(cin, again, '\n');
    }while(!error_handle_single_int(again));
    int play = stoi(again);
    if (play == 0){
        cout << "Thanks for playing!" << endl;
        cout << "Bye!" << endl;
        return false;
    }
    else if (play == 1){
        cout << "Wonderful!" << endl;
        return true;
    }
}

/**
** Function: end_statement
** Description: ending prompt
** Parameters: N/A
** Pre-Conditions: access private class
** Post-Conditions: returns game message
**/
void Game::end_statement(){
    int player_books = players[0].get_n_books();
    int comp_books = players[1].get_n_books();
    cout << "Thank you for playing Gofish~!" << endl;
    if (player_books > comp_books){
        cout << "You won the game!" << endl;
    } 
    else if (player_books < comp_books){
        cout << "You lost! Your opponent won!" << endl;
    }
}

/**
** Function: play
** Description: runs the game with all the logic and functions
** Parameters: N/A
** Pre-Conditions: takes no input
** Post-Conditions: plays gofish
**/
void Game::play(){
    //start of the game
    int player = 0, comp = 1;
    string ask, name;
    bool debug = debug_mode();
    //prompt user for name
    welcome(name);
    //shuffle the deck
    d.shuffle_deck();
    //deal cards
    deal_card();
    //randomly select who goes first
    game_logic(ask, debug);       
    end_statement();

}
