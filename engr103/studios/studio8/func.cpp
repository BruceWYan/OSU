#include <iostream> 
#include <string>

using namespace std; 
//string get_sentence();
void get_sentence(string&);
bool get_something(int&, int&);

int main() {
  	string sentence, s;
	/*
 	sentence = get_sentence();
	cout << sentence << endl;
	*/
	get_sentence(s);
	cout << s << endl;

	int number, something;
	number = 12;
	something = 16;
	get_something(number, something);
	cout << number << '\t' << something << endl;
	return 0;	
	

}

/*string get_sentence(){
   	string s;
	cout << "Type in a sentence: ";
	getline(cin, s); 
	return s;
}
*/

void get_sentence(string &s){
	cout << "type in a sentence: ";
	getline(cin, s);

}

bool get_something(int &number, int &something){
	cout << "the number 12 will appear" << endl; 
	number /= 3;
	something /= 4;
}

