#include <iostream>
#include <cstring> 

using namespace std; 

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
		arr_to_int (n, 0, 2, m);
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
		arr_to_int (n, 3, 5, mm);
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
		arr_to_int (n, 6, 10, y); 
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

int main() {
	char n[64];
	int value;
	cout << "type something: " << endl; 
	cin.getline (n , 64 -1 );
	is_date(n);
}
