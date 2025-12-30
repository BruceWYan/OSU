#include <iostream> 
#include <string> 
#include <cstring> 

using namespace std; 

bool is_letters (char item[]){
	int total;
	for (int i = 0; i < strlen(item); i++){
		if ((item[i] - '\0' >= 97 && item[i] - '\0' <= 122) || (item[i] - '\0' >= 65 && item[i] - '\0' <= 90)) {
			total +=0;
		}
		
		else {
			total ++;
		}
	}
	if (total > 0){
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
	
int main () {
	char n[64]; 
	cout << "type something in: ";
	cin.getline (n, 64 - 1);
	is_email(n); 
} 
