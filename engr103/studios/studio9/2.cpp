#include <iostream> 
#include <cstring> 
#include <string.h>
#include <string> 


using namespace std; 

void get_string(char str_to_store[]); 
void set_replace_string(char copy_str[], char dash_str[]); 
int get_search_replace(char c, char copy_str[], char dash_str[]); 
void get_dash(char dash_str[]);

int main() {
	char copy_str[256]; 
	char dash_str[256];
	char c;
	int found;
	get_string(copy_str);
	cout << strlen(copy_str) << '\t' << copy_str << endl;
	set_replace_string(copy_str, dash_str);
	get_dash(dash_str);
	found = get_search_replace(c, copy_str, dash_str);
	cout << "you found " << found << " our of " << strlen(copy_str) << " letters" << endl;
	cout << dash_str << endl; 
}

void get_string(char str_to_store[]){
	cout << "type in a sentence: ";
	cin.getline(str_to_store, 256 - 1);  
}

void set_replace_string(char copy_str[], char dash_str[]){
	strcpy(dash_str, copy_str);
	for (int i = 0; i < strlen(copy_str); i++) {
		if (copy_str[i] != ' ') {
			dash_str[i] = '-';
		}
	}
}

void get_dash(char dash_str[]){
	cout << dash_str << endl;
}

int get_search_replace(char c, char copy_str[], char dash_str[]){
	int count;
	cout << "type in a character: ";
	cin >> c; 
	for (int i = 0; i < strlen(copy_str); i++){
		if (copy_str[i] == c){
			dash_str[i] = c;
			count++;
		}
		else {
			dash_str[i] = dash_str[i]; 
		}
	}
	return count;


} 
 
