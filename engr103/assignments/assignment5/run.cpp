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


bool is_letters (char item[]);
void arrr_to_int(char n[], int i, int x, int &value);
bool is_slash (char n);
bool is_num (char n);
bool is_month (char n[]);
bool is_day (char n[]);
bool is_year (char n[]);
bool is_date (char n[]);
bool is_email (char item[]);
bool is_grad (int n);
void arr_to_int(char n[], int &value);
void get_basics(Basics& b, char fname[], char lname[], char email[]); // 6 lines
void get_education(Edu& edu, Basics& b, char univ[], char major[], int& graduate_year, float& GPA); // 10 lines
int num_exp (); // 4 lines (no declarations)
void get_exp (Exp ex[], int ex_size); // 9 lines (no declarations)
int num_skills(); // 4 lines (no declarations)
void get_skills(string sk[], int sk_size); // 3 lines
void read_basics(Basics& b, Edu& edu); // 7 lines
void read_exp (Exp ex[], int ex_size); // 5 lines
void read_skills(string sk[], int sk_size); // 2 lines

bool is_letters (char item[]){
    int total;
    for (int i = 0; i < strlen(item); i++){
	if ((item[i] - '\0' >= 97 && item[i] - '\0' <= 122) || (item[i] - '\0' >= 65 && item[i] - '\0' <= 90)) {
	    total ++;
	}

	else if (item[i] - '\0' >= 48 && item[i] - '\0' <= 57){
	    total +=0;
	}
	else {
	    total++;
	}
    }
    if (total > 0){
	return true;
    }
    else {
	return false;
    }
}

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
bool is_slash (char n){
    if (n - '\0' == 47){
	return true;
    }
    else {
	return false;
    }
}

bool is_num (char n){
    if (n - '\0' < 47 ||n - '\0' > 57){
	return false;
    }
    else {
	return true;
    }
}



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

bool is_date (char n[]){
    if (!is_slash(n[2]) || !is_slash(n[5]) || !is_month(n) || !is_day(n) || !is_year(n)){
	cout << "Please enter the correct date in the form (mm/dd/yyyy)" << endl;
	return false;
    }
    else {
	return true;
    }
}
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

bool is_grad (int n){
    if (n < 1950 || n > 2040) {
	return false;
    }
    else {
	return true;
    }
}	
void arr_to_int(char n[], int &value){
    for (int i= 0;i < strlen(n); i++){
	if (n[i] - '\0' < 48 || n[i] - '\0' > 57) {
	    value +=0;
	}
	else {
	    value = value*10 + n[i] - '0'; 
	}
    }
}
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
    }while(!(cin >> edu.GPA) );
    cin.ignore();
    b.edu = edu;
}

int num_exp (){ // 4 lines (no declarations)
    char num[64];
    int value = 0;
    //arr_to_int (num, value);
    do {	
	cout << "How many job experiences would you like to submit?: ";
	cin.getline(num, 64 -1);
	if (is_letters(num) == false){
	    arr_to_int(num, value);
	}	
    }while(is_letters(num) || value > 5 || value < 1 );

    return value;
}

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

int num_skills(){ // 4 lines (no declarations)
    char num[64];
    int value;
    do {
	cout << "How many skills would you like to submit? max 10: ";
	cin.getline( num, 64 -1);
	if (is_letters(num) == false){
	    arr_to_int (num, value);
	}
	cout << value << endl;
    }while (is_letters(num) == true || value > 10 || value < 1); 
    return value;	
}

void get_skills(string sk[], int sk_size){ // 3 lines
    for (int i = 0; i < sk_size; i++){
	cout << "Type in a skill (max 10): ";
	getline(cin, sk[i]);
    } 
}

//print Basics
void read_basics(Basics& b, Edu& edu){ // 7 lines
    cout << "First name: " << b.fname << endl;
    cout << "Last name: " << b.lname << endl; 
    cout << "Email: " << b.email << endl;
    cout << "University: " << b.edu.univ << endl; 
    cout << "Major: " << b.edu.major << endl;
    cout << "Graduation year: " << b.edu.graduate_year << endl; 
    cout << "GPA: " << b.edu.GPA << endl; 
}

void read_exp (Exp ex[], int ex_size){ // 5 lines
    for (int i = 0; i < ex_size; i++){
	cout << ex[i].company << endl; 
	cout << ex[i].start_date << endl; 
	cout << ex[i].end_date << endl;
	cout << ex[i].des << endl; 
    }
}

void read_skills(string sk[], int sk_size){ // 2 lines
    for (int i = 0; i < sk_size; i++){
	cout << "Skill " << i+1 << ": " << sk[i] << endl;
    }
}

void build_resume (ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size){
    ofstream out;
    out.open("bruh.txt", ios::app);
    if (out){
	out << b.fname << b.lname << b.email << b.edu.univ << b.edu.major << b.edu.graduate_year << b.edu.GPA << ex[ex_size].company << ex[ex_size].start_date << ex[ex_size].end_date << ex[ex_size].des << sk[sk_size] << endl;  
    }
    out.close();
}

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

    //get_basics(b1, fname, lname, email); 
    //get_education(edu1, b1, univ, major, graduate_year, GPA);
    int num = num_exp(); 
    Exp ex[num];	
    get_exp(ex, num);

    int snum = num_skills();
    string sk[snum];
    get_skills(sk, snum);

    read_basics(b1, edu1);
    read_exp(ex, num);
    read_skills(sk, snum);
    ofstream f;
    build_resume (f, b1, ex, num, sk, snum);
}
