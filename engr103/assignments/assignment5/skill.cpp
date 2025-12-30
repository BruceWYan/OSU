#include <iostream> 
#include <string>
#include <cstring> 

using namespace std; 

bool bad_skill(){
	string again;
	int total;
	do{
		cout << "Do you want to type in a skills? 1-yes or 0-no: ";
		getline(cin, again);
		for (int i = 0; i < again.length(); i++){
			total = 0;
			total += (again[i] - '\0');  		
		}
		if (total < 48 || total > 49){
			cout << "Please type in 1 or 0, no spaces, etc" << endl;
		}
	}while(total < 48 || total > 49);
	
	if (total == 48){
		return false;
	}
	
	else if (total == 49){
		return true;
	}
}

bool more_skill(){
	


}

void get_skills(string sk[], int sk_size){
	for (int i = 0; i < sk_size; i++){
		cout << "Type in a skill (max 10): ";
		getline(cin, sk[i]);
	} 
}

void display_skills(string sk[], int sk_size){
	for (int i = 0; i < sk_size; i++){
		cout << "Skill " << i+1 << ": " << sk[i] << endl;
	}
}
int main() {
	string sk[10];
	
	get_skills(sk, 10);
	display_skills(sk, 10);

}
