#include <iostream>
#include <string>
#include <cstring> 

using namespace std; 

struct Exp {
	char company[64];
	char start_date[64];
	char end_date[64];
	char des[1024];
};

int num_exp (){
	int num;
	cout << "How many job experiences would you like to submit?: ";
	cin >> num;
	return num;
}
void get_exp_members (Exp& exp, char company[], char start_date[], char end_date[], char des[]){
	cout << "What company did/do you work at: ";
	cin.getline(exp.company, 64-1);
	cout << "When was your start date (mm/dd/yyyy): ";
	cin.getline(exp.start_date, 64-1);
	cout << "When was your end date (mm/dd/yyyy): ";
	cin.getline(exp.end_date, 64-1); 
	cout << "Please type a short description of your job: ";
	cin.getline(exp.des, 1024-1);
} 

void get_exp (Exp ex[], int ex_size){
	char company[64];
	char start_date[64];
	char end_date[64];
	char des[1024];
	Exp exp;
	for (int i = 0; i < ex_size; i++){
		get_exp_members(exp, company, start_date, end_date, des); 
		ex[i] = exp;

	}	
}

void print_exp (Exp ex[], int ex_size){
	for (int i = 0; i < ex_size; i++){
		cout << ex[i].company << endl; 
		cout << ex[i].start_date << endl; 
		cout << ex[i].end_date << endl;
		cout << ex[i].des << endl; 
	}
}

int main(){
	Exp ex[5];
	get_exp(ex, 5);
	print_exp(ex, 5); 
}
