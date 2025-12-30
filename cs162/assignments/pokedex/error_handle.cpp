#include <iostream>
#include <string>

using namespace std;

//Description: handles input types for single characters 
bool error_handle_single_int(string s){
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
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

bool error_handle_letters(string s){
    int size = s.length();
    for (int i = 1; i < size; i++){
        if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

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

bool error_handle_single_letter(string s){
    int size = s.length();
    if (size > 1 || size < 1){
        cout << "That's not good input" << endl;
        cout << "Please try again" << endl << endl;
    }
    for (int i = 1; i < size; i++){
        if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

bool error_handle_wasd(string s){
    int size = s.length();
    if (size > 1 || size < 1){
        cout << "That's not good input" << endl;
        cout << "Please try again" << endl << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if (!(s[i] == 'w' || s[i] == 'a' || s[i] == 's' || s[i] == 'd')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

bool error_handle_y_n(string s){
    int size = s.length();
    if (size > 1 || size < 1){
        cout << "That's not good input" << endl;
        cout << "Please try again" << endl << endl;
        return false;
    }
    for (int i = 0; i < size; i++){
        if (!(s[i] == 'y' || s[i] == 'n')){
            cout << "That's not good input" << endl; 
            cout << "Please try again" << endl << endl;
            return false;
        }     
    }
    return true;
}

//string

int main(){
    string text = "some.txt";
    int size = text.length();
    string file;
    do{ 
        cout << "y/n: ";
        getline(cin, file, '\n');
    }while(!error_handle_y_n(file));
}