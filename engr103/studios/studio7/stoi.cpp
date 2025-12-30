#include <iostream> 
#include <string> 

using namespace std; 

int main() {
	int stoi (
		const string& str,
		size_t* idx = 0,
		int base = 10);
	
	string str; 
	cin >> str; 
	cout << stoi(str); 
	

}
