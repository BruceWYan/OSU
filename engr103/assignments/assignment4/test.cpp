#include <iostream> 
#include <string> 

using namespace std; 
int length(string); 
int stoi(string);
bool ifstringint(string);
bool ifstring(string);

int main() {
	/*cout << "type in a string: "; 
	string str; 
	cin >> str; 

	int l= length(str);
	int value = stoi(str); 
	cout << value << endl;
	
	cout << str[0]-'\0' << str[1] << endl; 	
	
	cout << ifstring(str) << endl; 
	
	cout << str.length() << endl;*/
	string sentence;
	
	getline(cin , sentence);
	int len = sentence.length();
	cout << len << endl;
}


int length(string str) {
	int q; 
	for (q = 0; str[q]; q++);
	return q;
}
int stoi(string str) {
	int val = 0;
	for (int i = 0; i < length(str); i++) {
		val = val*10 + str[i] - '0';
	}
	return val;

}

bool ifstringint(string str) {
	int gal = 0;
	int g;
	for ( g =0; g <length(str); g++) {
		
	}
}
bool ifstring(string str) { 
	int j;
	for (j=0; j < length(str); j++) {
		if (str[j] - '\0' < 48 || str[j] - '\0' >= 57) {
			return false;
			j = length(str);
		}
		else {
			return true;
		}
	}
}
