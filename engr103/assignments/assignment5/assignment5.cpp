/*********************************
** Program: assignment5.cpp
** Author: Bruce Yan
** Date: 06/01/2022 (late)
** Description: takes input to build resume on .txt file
** input: b.fname, b.lname, b.email, b.edu.univ, b.edu.major, b.edu.graduate_year, b.edu.GPA, exp[], sk[], num, snum
** output: [b.lname].txt
***********************************/

#include <iostream> 
#include <string> 
#include <cstring> 
#include <fstream>

using namespace std; 

//the struct to store Education Background
struct Edu { // 4 lines
    char univ[128]; //a c-string to store the university name
    char major[64]; //a c-string to store the major
    int graduate_year; //graduation year
    float GPA; //GPA
};

//the struct to store the basic information
struct Basics { // 4 lines
    char fname[64]; //a c-string to store the first name
    char lname[64]; //a c-string to store the last name
    char email[64]; //a c-string to store the email address
    Edu edu; //an Edu object to store the ed. background
};

//the struct to store one work experience
struct Exp { // 4 lines
    char company[64]; //a c-string to store the company name
    char start_date[64]; //a c-string to the start date 
    char end_date[64]; //a c-string to store the end date
    char des[1024]; //the description of the work experience
};


void arrr_to_int(char n[], int i, int x, int &value);
/*************************************
** Function: arrr_to_int
** Description: Given a cstring, and address of characters within the array, turn to an int
** Parameters: char n[], int i, int x, int& value
** Pre-conditions: take a cstring parameter
** Post-conditions: returns an int value
*************************************/

bool is_slash (char n);
/*************************************
** Function: is_slash
** Description: determines if given character is a slash
** Parameters: char n
** Pre-conditions: takes a char parameter
** Post-conditions: returns true or false whether char is a slash
*************************************/

bool is_num (char n);
/*************************************
** Function: is_num
** Description: determines if given char is an integer
** Parameters: char n
** Pre-conditions: takes a char parameter 
** Post-conditions: returns true or false whether char is an int
*************************************/

bool is_month (char n[]);
/*************************************
** Function: is_month
** Description: determines if given cstring is less than 12 or greater than 0
** Parameters: char n[]
** Pre-conditions: takes a cstring parameter 
** Post-conditions: returns true or false whether cstring is less than 12 or greater than 0
*************************************/

bool is_day (char n[]);
/*************************************
** Function: is_day
** Description: determines if a given cstring is less than 31 or greater than 0
** Parameters: char n[]
** Pre-conditions: takes a cstring parameter
** Post-conditions: returns true or false whether cstring is less than 31 or greater than 0;
*************************************/

bool is_year (char n[]);
/*************************************
** Function: is_year
** Description: determiens if a given cstring is less than a certain year
** Parameters: char n[]
** Pre-conditions: takes a cstring parameter 
** Post-conditions: returns true or false
*************************************/

bool is_date (char n[]);
/*************************************
** Function: is_date
** Description: checks if the given cstring is in correct date format
** Parameters: charn[]
** Pre-conditions: takes a cstring parameter
** Post-conditions: returns true or false
*************************************/

bool is_email (char item[]);
/*************************************
** Function: is_email
** Description: checks to see if email fits email conditions
** Parameters: char item[]
** Pre-conditions: takes a cstring parameter
** Post-conditions: returns true or false
*************************************/

bool is_grad (int n);
/*************************************
** Function: is_grad
** Description: checks to see if given input is within certain range
** Parameters: int n
** Pre-conditions: takes an int parameter
** Post-conditions: returns true or false
*************************************/

void arr_to_int(char n[], int &value);
/*************************************
** Function: arr_to_int 
** Description: takes a cstring and turns it into an int
** Parameters: char n[], int& value
** Pre-conditions: takes cstring and int parameter 
** Post-conditions: passes through cstring as int 
*************************************/

void get_basics(Basics& b, char fname[], char lname[], char email[]); // 6 lines
/*************************************
** Function: get_bascis
** Description: gets the basic information from user
** Parameters: Basics b, char fname[], char lname[], char email[]
** Pre-conditions: takes in structure member, and cstrings as parameters
** Post-conditions: stores inputs into the structure members
*************************************/

void get_education(Edu& edu, Basics& b, char univ[], char major[], int& graduate_year, float& GPA); // 10 lines
/*************************************
** Function: get_education
** Description: gets the education information from user
** Parameters: Edu edu, Basic b, char univ[], char major[], int graduate_year, floatGPA
** Pre-conditions: takes structure, int, flaot, and cstring parameters
** Post-conditions: stores inputs into edu structure and then into basics
*************************************/

int num_exp (); // 4 lines (no declarations)
/*************************************
** Function: num_exp
** Description: counts the number of experiences from user
** Parameters: none
** Pre-conditions: takes in a cstring input from user
** Post-conditions: returns that input as an int
*************************************/

void get_exp (Exp ex[], int ex_size); // 9 lines (no declarations)
/*************************************
** Function: get_exp
** Description: gets experience information from user
** Parameters: Exp ex[], int ex_size
** Pre-conditions: takes structure and int paramters
** Post-conditions: stores the exp structure info into an array
*************************************/

int num_skills(); // 4 lines (no declarations)
/*************************************
** Function: num_skills
** Description: counts the number of skills from user
** Parameters: none
** Pre-conditions: take in a cstring input from user
** Post-conditions: returns that input as an int
*************************************/

void get_skills(string sk[], int sk_size); // 3 lines
/*************************************
** Function: get_skills
** Description: gets skills information from user
** Parameters: string sk[], int sk_size
** Pre-conditions: takes in a string and an int parameters 
** Post-conditions: stores the skils into an array of strings
*************************************/

void read_basics(ofstream& f, Basics& b); // 7 lines
/*************************************
** Function: read_basics
** Description: takes information in structure and displays onto .txt 
** Parameters: f stream and structure
** Pre-conditions: takes structure input 
** Post-conditions: outputs input from structure onto a .txt file
*************************************/

void read_exp (ofstream& f, Exp ex[], int ex_size); // 5 lines
/*************************************
** Function: read_exp
** Description: taeks information in structure and displays onto .txt
** Parameters: f stream and structure
** Pre-conditions: takes structure paramter 
** Post-conditions: outputs input from structure onto a .txt file
*************************************/

void read_skills(ofstream& f, string sk[], int sk_size); // 2 lines
/*************************************
** Function: read_skills
** Description: takes information in strucure and dispalys into .txt
** Parameters: f stream and structure 
** Pre-conditions: takes structure parameter 
** Post-conditions: outputs input from structure onto a .txt file
*************************************/

void build_resume (ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size);
/*************************************
** Function: build_resume
** Description: builds and opens .txt files
** Parameters: Basics b, Exp ex[], int ex_size, string sk[], int sk_size, ofstream f
** Pre-conditions: takes iformation stores from the parmeters 
** Post-conditions: displays that info onto .txt 
*************************************/

int main() { // 9 lines (no declarations)
    char fname[64];
    char lname[64];
    char email[64];	

    char univ[128];
    char major[64];
    int graduate_year;
    float GPA;

    Basics b1;
    Edu edu1;

    get_basics(b1, fname, lname, email); 
    get_education(edu1, b1, univ, major, graduate_year, GPA);
    int num = num_exp(); 
    Exp ex[num];	
    get_exp(ex, num);

    int snum = num_skills();
    string sk[snum];
    get_skills(sk, snum);

    ofstream f;
    build_resume (f, b1, ex, num, sk, snum);
}

//takes a string given the address and turns it into an int
void arrr_to_int(char n[], int i, int x, int &value){ 
    for (;i < x; i++){
	if (n[i] - '\0' < 48 || n[i] - '\0' > 57) {
	    value +=0;
	}
	else {
	    value = value*10 + n[i] - '0'; 
	}
    }
}

//check to see if a char is a slash
bool is_slash (char n){
    if (n - '\0' == 47){
	return true;
    }
    else {
	return false;
    }
}

//checks to see if a char is an integer
bool is_num (char n){
    if (n - '\0' < 47 ||n - '\0' > 57){
	return false;
    }
    else {
	return true;
    }
}

//checks to see if the ctring at a certain index represents the correct month
bool is_month (char n[]){
    if ((is_num(n[0]) && is_num(n[1])) == true){
	int m = 0;
	int mm = 0;
	arrr_to_int (n, 0, 2, m);
	if (m >12 || m <= 0){
	    return false; 	
	}
	else {
	    return true;
	}
    }
    else {
	return false;
    }
}

//checks to see if the cstring at a certain index represents the correct day
bool is_day (char n[]){
    if ((is_num(n[3]) && is_num(n[4])) == true){
	int mm = 0;
	arrr_to_int (n, 3, 5, mm);
	if (mm > 31 || mm <= 0){
	    return false;
	} 
	else {
	    return true;
	}
    }
    else {
	return false;
    }
}

//checks to see if the cstring at a certain index is not farther than this year
bool is_year (char n[]){
    if ((is_num(n[6]) && is_num(n[7]) && is_num(n[8]) && is_num(n[9])) == true){
	int y = 0;
	arrr_to_int (n, 6, 10, y); 
	if (y > 2022) {	
	    return false;
	} 
	else {	
	    return true;
	}
    }
    else {
	return false;
    }
}

//puts together all three is_month, is_day, and is_year fxns in one and if neither are correct then print error statement
bool is_date (char n[]){
    if (!is_slash(n[2]) || !is_slash(n[5]) || !is_month(n) || !is_day(n) || !is_year(n)){
	cout << "Please enter the correct date in the form (mm/dd/yyyy)" << endl;
	return false;
    }
    else {
	return true;
    }
}

//checks to see if the email has one '@' and atleast one '.'
bool is_email (char item[]){
    int total;
    int dot;
    for (int i = 0; i < strlen(item); i++){
	if (item[i] - '\0' == 64) {
	    total++;
	}	
	else if (item[i] - '\0' == 46){
	    dot++;
	}
	else {
	    total +=0;
	}	
    }
    if (total == 1 && dot >=1){
	cout << "yup" << endl; 
	return true;
    }
    else {
	cout << "noe" << endl; 
	return false;
    }
}

//checks if grad year is more than 2050
bool is_grad (int n){
    if (n < 1950 || n > 2050) {
	return false;
    }
    else {
	return true;
    }
}	

//turns an ctring into an int
void arr_to_int(char n[], int &value){
    for (int i= 0;i < strlen(n); i++){
	value = value*10 + n[i] - '0'; 
    }
}

//gets basic info form user
void get_basics(Basics& b, char fname[], char lname[], char email[]){ // 6 lines
    cout << "What is your first name?: ";
    cin.getline(b.fname, 64-1);
    cout << "What is your last name?: ";
    cin.getline(b.lname, 64-1);
    do {
	cout << "What is your email: "; 
	cin.getline(b.email, 64-1);
    }while(is_email(b.email) == false);
}

//fxn gets education
void get_education(Edu& edu, Basics& b, char univ[], char major[], int& graduate_year, float& GPA){ // 10 lines
    cout << "What university do you go to?: ";
    cin.getline(edu.univ, 128-1);
    cout << "What is your major?: ";
    cin.getline(edu.major, 64-1);
    do { 
	cout << "What is your graduation year?: ";
	cin >> edu.graduate_year; 
    }while(is_grad(edu.graduate_year) == false);
    do {
	cout << "What is your GPA?: ";
	cin >> edu.GPA;
    }while(edu.GPA > 4.0 || edu.GPA < 0);
    cin.ignore();
    b.edu = edu;
}

//gets number of experiences user wants to put in
int num_exp (){ // 4 lines (no declarations)
    char num[64];
    int value = 0;
    do {	
	value =0;
	cout << "How many job experiences would you like to submit?: ";
	cin.getline(num, 64 -1);
	arr_to_int(num, value);
    }while(value > 5 || value < 1 );

    return value;
}

//gets the experience information from user
void get_exp (Exp ex[], int ex_size){ // 9 lines (no declarations)
    char company[64];
    char start_date[64];
    char end_date[64];
    char des[1024];
    for (int i = 0; i < ex_size; i++){
	cout << "What company did/do you work at: ";
	cin.getline(ex[i].company, 64-1);
	do {
	    cout << "When was your start date (mm/dd/yyyy): ";
	    cin.getline(ex[i].start_date, 64-1);
	}while (is_date(ex[i].start_date) == false);
	do { 
	    cout << "When was your end date (mm/dd/yyyy): ";
	    cin.getline(ex[i].end_date, 64-1); 
	}while (is_date(ex[i].end_date) == false);
	cout << "Please type a short description of your job: ";
	cin.getline(ex[i].des, 1024-1);
    }
}

//gets the number of skills 
int num_skills(){ // 4 lines (no declarations)
    char num[64];
    int value;
    do {
	value =0;
	cout << "How many skills would you like to submit? max 10: ";
	cin.getline( num, 64 -1);
	arr_to_int (num, value);
    }while (value > 10 || value < 1); 
    return value;	
}

//gets skills from user
void get_skills(string sk[], int sk_size){ // 3 lines
    for (int i = 0; i < sk_size; i++){
	cout << "Type in a skill (max 10): ";
	getline(cin, sk[i]);
    } 
}

//print Basics
void read_basics(ofstream& f, Basics& b){ // 7 lines
    f << "First name: " << b.fname << endl;
    f << "Last name: " << b.lname << endl; 
    f << "Email: " << b.email << endl;
    f << "University: " << b.edu.univ << endl; 
    f << "Major: " << b.edu.major << endl;
    f << "Graduation year: " << b.edu.graduate_year << endl; 
    f << "GPA: " << b.edu.GPA << endl; 
}

//prints experiences
void read_exp (ofstream& f, Exp ex[], int ex_size){ // 5 lines
    for (int i = 0; i < ex_size; i++){
    	f << "Company: " << ex[i].company << endl; 
	f << "Start Date: " << ex[i].start_date << endl; 
	f << "End Date: " << ex[i].end_date << endl;
	f << "Description: " << ex[i].des << endl << endl; 
    }
}

//prints skills
void read_skills(ofstream& f, string sk[], int sk_size){ // 2 lines
    for (int i = 0; i < sk_size; i++){
	f << "Skill " << i+1 << ": " << sk[i] << endl;
    }
}

//prints onto a txt files
void build_resume (ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size){
    char last[64];
    strcpy(last, b.lname); 
    f.open(strcat(last, ".txt"));
    if (!f.is_open()){
	cout << "Error opening the file" << endl;
	return;
    }
    else if (f){
	f << '\t' << '\t' << b.fname << " " << b.lname << endl;
	read_basics(f, b);
	f << '\t' << '\t' << "Experience" << endl;
	read_exp(f, ex, ex_size);
	f << '\t' << '\t' << "Skills" << endl;
	read_skills(f, sk, sk_size); 
    }
    f.close();
}

