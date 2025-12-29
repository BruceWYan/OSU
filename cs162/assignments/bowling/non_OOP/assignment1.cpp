/******************************************************
** Program: assignment1.cpp
** Author: Bruce Yan
** Date: 10/09/2022
** Description: Bowling simulator 
** Input: name, enter, again 
** Output: The game
******************************************************/
#include <iostream> 
#include <string> 
#include <ctime>
#include <cstdlib> 
#include <iomanip>

using namespace std;
/*************************************
** Function: is_name
** Description: checks to see if input is all characters
** Parameters: string &name
** Pre-conditions: takes a string parameter
** Post-conditions: returns true or false
*************************************/
bool is_name(string &name){
    int size = name.length();
    
    for (int i = 0; i < size; i++){
        if (!((name[i] - '\0' > 64 && name[i] - '\0' < 91) || (name[i] - '\0' > 96 && name[i] - '\0' < 123))){
            return false;
        }

    }
    return true;
}
/*************************************
** Function: get_name
** Description: gets a user name as input
** Parameters: string &name
** Pre-conditions: takes a string parameter
** Post-conditions: stores the input into name
*************************************/
void get_name(string &name){
    cout << "Welcome to the Bowling Simulator!" << endl;
    do{
        cout << "Pleaes enter your first name: ";
        getline(cin, name);
    }while(!is_name(name));
}
/*************************************
** Function: get_enter
** Description: gets user enter
** Parameters: N/A
** Pre-conditions: takes no input
** Post-conditions: continues the game
*************************************/
void get_enter(){
    char letter;
    do{
        cout << "Press Enter to roll..." << endl;
        cin.get(letter);
        //cin.ignore();
    }while(letter != '\n');
}

/*************************************
** Function: is_again
** Description: checks if play_again input is good or bad
** Parameters: string &again
** Pre-conditions: takes a string parameter
** Post-conditions: returns true or false
*************************************/
bool is_again(string &again){
    int size = again.length();
    if (size < 1 || size > 2 ){
        cout << "That's not a good input" << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if (again[i] < '0' || again[i] > '1'){
            cout << "That's not a good input" << endl;
            return false;
        }
    }
    return true;
}

/*************************************
** Function: play_again
** Description: checks if play_again input is good or bad
** Parameters: string &again
** Pre-conditions: takes a string parameter
** Post-conditions: returns true or false
*************************************/
bool play_again(string &again){
    do{
        cout << "Do you want to play again? 1(yes) or 0(no): ";
        getline(cin, again); // might do it in a separate function
        //cin.ignore();
    }while(!is_again(again));

    if (again == "1"){
        return true;
    }
    else if (again == "0"){
        cout << "thanks for playing!" << endl;
        return false;
    }
}
/*************************************
** Function: initial_str_arr
** Description: initializes a string array
** Parameters: string score[], int size
** Pre-conditions: takes a string array and int parameter
** Post-conditions: initializes an array
*************************************/
void initial_str_arr(string score[], int size){
    for (int i = 0; i < size; i++){
		score[i] = "\0";
	}
}
/*************************************
** Function: initial_int_arr
** Description: initializes an int array
** Parameters: int total[], int size
** Pre-conditions: takes an array and int paramtere
** Post-conditions: initializes an array
*************************************/
void initial_int_arr(int total[], int size){
    for (int i = 0; i < size; i++){
        total[i] = 0;
    }
}
/*************************************
** Function: print_string_arr
** Description: print array
** Parameters: string score[]
** Pre-conditions: take string array
** Post-conditions: prints array
*************************************/
void print_string_arr(string score[]){
    for (int i=0; i < 21; i++){ // make into function
        if (score[i]=="\0"){
            score[i] = " ";
            if (i %2 != 0 && i != 19){
            cout << score[i] << "  |";
            }
            else {
                cout << score[i] << "  ";
            } 
        }
        else {
            if (i %2 != 0 && i != 19){
                cout << score[i] << "  |";
            }
            else {
                cout << score[i] << "  ";
            } 
        }
    }
    cout << "| ";
}
/*************************************
** Function: print_int_arr
** Description: print array
** Parameters: int arr[]
** Pre-conditions: takes int array
** Post-conditions: prints array
*************************************/
void print_int_arr(int arr[]){
    for (int i=0; i < 10; i++){
        if (arr[i] == 0){;
            if (i == 9){
                cout << setw(6) << " " << "   |";
            }
            else {
                cout << setw(4) << " " << "  |";
            }
        }
        else{
            if (i == 9){
                cout << setw(6) << arr[i] << "   |";
            }
            else {
                cout << setw(4) << arr[i] << "  |";
            }
        }
    }
}
/*************************************
** Function: print_frame
** Description: prints the scoreboard
** Parameters: string score[], int total[], int total_sum, string name
** Pre-conditions: takes string array, int, and string parameters
** Post-conditions: prints the scoreboard and updates values
*************************************/
void print_frame(string score[], int total[], int total_sum, string name){
    cout << "Name          |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   10    | Total" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << name << setw(15-name.size()) << "|";
    print_string_arr(score);
    cout << total_sum << endl << setw(15) << "|";
    print_int_arr(total);
    cout << endl << "----------------------------------------------------------------------------------------------" << endl;
}
/*************************************
** Function: add_score_index
** Description: changes index within score arr until the very last roll
** Parameters: int &score_index
** Pre-conditions: takes an int parameter 
** Post-conditions: updates score_index
*************************************/
void add_score_index(int &score_index){
    if (score_index < 20){
        score_index++;
    }
}
/*************************************
** Function: statements1
** Description: takes pins and pins2 values and updates scoreboard
** Parameters: int &pins, int &pins2, int &score_index, int &total_index
** Pre-conditions: takes in integer parameters
** Post-conditions: changes integer parameteres and prints out score board statments
*************************************/
void statements1(int &pins, int &pins2, int &score_index, int &total_index){
    if (pins == 1){
            cout << "You knocked down " << pins << " pin!" << endl;
            add_score_index(score_index);
    }
    else if (pins == 10) {
        cout << "You knocked down " << pins << " that's a STRIKE!" << endl;             
        if (score_index < 18){
                score_index += 2;
            }
        else if (score_index >= 18){
            add_score_index(score_index);
        }
    }
    else if (pins == 0) {
        cout << "You knocked down " << pins << " that's a GUTTER" << endl;
        add_score_index(score_index);
    }
    else {
        cout << "You knocked down " << pins << " pins!" << endl;
        add_score_index(score_index);
    }
}
/*************************************
** Function: statements2
** Description: takes pins and pins2 values and updates scoreboard
** Parameters: int &pins, int &pins2, int &score_index, int &total_index
** Pre-conditions: takes in integer parameters
** Post-conditions: changes integer parameteres and prints out score board statments
*************************************/
void statements2(int &pins, int &pins2, int &score_index, int &total_index){
     if (pins2 == 1){
            cout << "You knocked down " << pins2 << " pin!" << endl;
            add_score_index(score_index);
    }
    else if (pins2 == 0) {
        cout << "You knocked down " << pins2 << " that's a GUTTER!" << endl;
        add_score_index(score_index);
    }
    else if ((pins + pins2) == 10){
        cout << "You knocked down " << pins2 << " that's a SPARE!" << endl;
        add_score_index(score_index);
    } 
    else {
        cout << "You knocked down " << pins2 << " pins!" << endl;
        add_score_index(score_index);
    }
}
/*************************************
** Function: print_knock_down
** Description: updates scorebaord depending on roll1 or roll2
** Parameters: int &pins, int &pins2, int &score_index, int &total_index
** Pre-conditions: takes in integer parameters
** Post-conditions: updates score board
*************************************/
void print_knock_down (int &pins, int &pins2, int &score_index, int &total_index){
    if (score_index % 2 == 0){
        statements1(pins, pins2, score_index, total_index);
    }

    else if (score_index % 2 != 0){
        statements2(pins, pins2, score_index, total_index);
    }
}
/*************************************
** Function: strike
** Description: changes score to "X" if there rolls 10 pins
** Parameters: tring score[], int &score_index, int &total_index
** Pre-conditions: takes in string array and integer parameters 
** Post-conditions: changes frames
*************************************/
void strike(string score[], int &score_index, int &total_index){
    score[score_index] = "X";
    if (total_index < 9){
        total_index++;
    }
}
/*************************************
** Function: gutter
** Description: changes score to "-" if rolls are 0
** Parameters: string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum
** Pre-conditions: takes in a string array, integer array, and integers parameters
** Post-conditions: updates the scoreboard and moves onto next frame
*************************************/
void gutter(string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum){
    if (score_index % 2 == 0){
        score[score_index] = "-";
    }
    else if (score_index % 2 != 0){
        score[score_index] = "-";
        total[total_index] += (pins + pins2);
        total_sum += (pins + pins2);
        if (total_index >= 1){
            total[total_index] += total[total_index - 1];
        }
        if (total_index < 9){
            total_index++;
        }
    }
}
/*************************************
** Function: spare
** Description: if spare, then update sapre to "\"
** Parameters: string score[], int &score_index, int &total_index
** Pre-conditions: takes a string array and integer parameters
** Post-conditions: updates scoreboard 
*************************************/
void spare(string score[], int &score_index, int &total_index){
    score[score_index] = "/";
    if (total_index < 9){
        total_index++;
    }
}
/*************************************
** Function: double_strike
** Description: handles doubl_strikes
** Parameters: int total[], int &total_index, int &pins, int &total_sum
** Pre-conditions: takes in int array and integer parameters 
** Post-conditions: updates scoreboard
*************************************/
void double_strike(int total[], int &total_index, int &pins, int &total_sum){
    total[total_index-2] += (20 + pins + total[total_index-3]);
    total_sum = total[total_index-2];
}
/*************************************
** Function: prev_spare
** Description: checks if prev is spare
** Parameters: int total[], int &score_index, int &total_index, int &pins, int &total_sum
** Pre-conditions: takes a bunch of paramters
** Post-conditions: updates scoreboard
*************************************/
void prev_spare(int total[], int &score_index, int &total_index, int &pins, int &total_sum){
    if (score_index > 18){
        total[total_index] += (pins + 10 + total[total_index - 1]);
        total_sum = total[total_index];
    }
    else {
        total[total_index-1] += (pins + 10 + total[total_index - 2]);
        total_sum = total[total_index-1];
    }
}
/*************************************
** Function: prev_strike
** Description: checks if prev is strike
** Parameters: string score[], int total[], int &total_index, int &pins, int &pins2, int &total_sum
** Pre-conditions: takes a bunch of paramters
** Post-conditions: updates scoreboard
*************************************/
void prev_strike(string score[], int total[], int &total_index, int &pins, int &pins2, int &total_sum){
    if (score[19] == "/"){
        total[total_index] += (10 + pins);
        total_sum = total[total_index];
    }
    else{
        total[total_index-1] += (pins + pins2 + 10 + total[total_index - 2]);
        total_sum = total[total_index-1];
    }
}
/*************************************
** Function: cont_roll2
** Description: continues roll2
** Parameters: string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index)
** Pre-conditions: takes a bunch of paramters
** Post-conditions: updates scoreboard
*************************************/
void cont_roll2(string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum){
    score[score_index] = to_string(pins2);
        total[total_index] += (pins + pins2);
        total_sum += (pins + pins2);
        if (total_index >= 1){
            total[total_index] += total[total_index - 1];
        }
        total_index++;
}
/*************************************
** Function: is_prev_spare
** Description: checks previous roll to see if it was a spare
** Parameters: string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index)
** Pre-conditions: takes a bunch of paramters
** Post-conditions: returns true or false
*************************************/
bool is_prev_spare(string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index){
    if (score_index != 0 && score[score_index-1] == "/"){
        return true;
    }
    else {
        return false;
    }

}
/*************************************
** Function: is_prev_strike
** Description: checks to see if there was a strik in prev roll
** Parameters: string score[], int &score_index
** Pre-conditions: takes a string array and int paramater
** Post-conditions: returns true or false
*************************************/
bool is_prev_strike(string score[], int &score_index){
    if (score_index > 3 && score[score_index - 3] == "X" && score_index != 18){
        return true;
    } 

    else {
        return false;
    }
}
/*************************************
** Function: is_double_strike
** Description: checks to see if there were two strikes
** Parameters: string score[], int &score_index
** Pre-conditions: takes a string array and int paramater
** Post-conditions: returns true or false
*************************************/
bool is_double_strike(string score[], int &score_index){
    if (score_index >= 3 && score[score_index - 4] == "X" && score[score_index - 2] == "X") {
        return true;
    }
    else {
        return false;
    }
}
/*************************************
** Function: roll1
** Description: generates random roll for first roll
** Parameters: string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum
** Pre-conditions: takes in a bunch of parameters
** Post-conditions: runs an array of functions
*************************************/
void roll1(string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum){
    get_enter();
    srand(time(NULL));
    pins = rand() % 11;

    if (is_double_strike(score, score_index)) {
        double_strike(total, total_index, pins, total_sum);
    }

    if (is_prev_spare(score, total, pins, pins2, score_index, total_index)){
        prev_spare(total, score_index, total_index, pins, total_sum);
    }

    if (is_prev_strike(score, score_index)){
        prev_strike(score, total, total_index, pins, pins2, total_sum);
    }

    if (pins == 10){ 
        strike(score, score_index, total_index);
    }
    else if (pins == 0){
        gutter(score, total, pins, pins2, score_index, total_index, total_sum);
    }
    else {
        score[score_index] = to_string(pins);
    }
    
}
/*************************************
** Function: roll2
** Description: generates random roll for second roll
** Parameters: string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum
** Pre-conditions: takes in a bunch of parameters
** Post-conditions: runs an array of functions
*************************************/
void roll2(string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum){
    get_enter();
    srand(time(NULL));
    pins2 = rand() % (11 - pins);

    if (is_prev_strike(score, score_index)){
        prev_strike(score, total, total_index, pins, pins2, total_sum);
    }

    if ((pins + pins2) == 10){
        spare(score, score_index, total_index); 
    }
    else if (pins2 == 0){
        gutter(score, total, pins, pins2, score_index, total_index, total_sum);
    }
    else {
        cont_roll2(score, total, pins, pins2, score_index, total_index, total_sum);
    }   
}
/*************************************
** Function: rollOne
** Description: runs the program for roll 1
** Parameters: int &pins, int &pins2, int &score_index, int &total_index, int &total_sum
** Pre-conditions: takes in a bunch of parameters
** Post-conditions: updates score board
*************************************/
void rollOne(string score[], int total[], string &name, int &pins, int &pins2, int &score_index, int &total_index, int &total_sum){
    get_enter();
    roll1(score, total, pins, pins2, score_index, total_index, total_sum);
    print_knock_down(pins, pins2, score_index, total_index);
    print_frame(score, total, total_sum, name);
}

/*************************************
** Function: rollTwo
** Description: runs the program for roll 2
** Parameters: string score[], int total[], int &pins, int &pins2, int &score_index, int &total_index, int &total_sum
** Pre-conditions: takes in a bunch of parameters
** Post-conditions: updates scoreboard
*************************************/
void rollTwo(string score[], int total[], string &name, int &pins, int &pins2, int &score_index, int &total_index, int &total_sum){
    get_enter();
    roll2(score, total, pins, pins2, score_index, total_index, total_sum);
    print_knock_down(pins, pins2, score_index, total_index);
    print_frame(score, total, total_sum, name);
}

int main(){
    string again;
    do {
        string score[21], name; 
        int total[10], pins = 0, pins2 = 0, score_index = 0, total_index = 0, total_sum = 0;
    
        initial_str_arr(score, 21);
        initial_int_arr(total, 10);
        get_name(name);
        for (int i=0; i < 20; i++){
            
            if (score_index == 20 && (pins + pins2) < 10 && score[18] != "X"){
                break;
            }
            else if ((score_index == 20 && (pins + pins2 == 10)) || ((score_index < 21 && score_index > 18) && score[score_index - 1] == "X") || score_index % 2 == 0){
                roll1(score, total, pins, pins2, score_index, total_index, total_sum);
                print_knock_down(pins, pins2, score_index, total_index);
                print_frame(score, total, total_sum, name);
            }
            else if ((score[18] == "X" && score[19] != "X") || score_index % 2 != 0){
                roll2(score, total, pins, pins2, score_index, total_index, total_sum);
                print_knock_down(pins, pins2, score_index, total_index);
                print_frame(score, total, total_sum, name);
            }
            
        }
    }while(play_again(again));

    return 0;
}