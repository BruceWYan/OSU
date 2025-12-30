#include <iostream>
#include <string> 
#include <cstring>

using namespace std; 

void get_string(string &str_to_store);
void get_replace_string(string copy_str, string &dash_str); 
int get_search_replace(char c, string copy_str, string &dash_str); 
void read_dash_str(string);

int main() {
	string s;
	string dash;
	char c;
	get_string(s); 
	get_replace_string(s, dash); 	
	read_dash_str(dash); 
	get_search_replace(c, s, dash);
}

void get_string(string &str_to_store){
	cout << "Enter a sentence: "; 
	getline(cin , str_to_store); 
}

void get_replace_string(string copy_str, string &dash_str){
	for (int i = 0; i < copy_str.length(); i++) {
		if (copy_str[i] - '\0' != 32) {
			copy_str[i] = 45;
			dash_str = copy_str;
		}
	}
}

void read_dash_str (string s){
	cout << "You sentence is now: " << s << '\n';
}

int get_search_replace(char c, string copy_str, string &dash_str){
	int i = 0;
	int again;
	int count;
	do{ 
		cout << "type in a character: ";
		cin >> c; 
		for (i = 0; i < copy_str.length(); i++){
			if (c == copy_str[i]){
				dash_str[i] = c; 
				count++;
			}
		}
		cout << dash_str << endl;
		cout << "again?: ";
		cin >> again;
	}while(again == 1);
	return count;
} 

