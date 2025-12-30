#include <iostream> 

using namespace std; 

int main() {
	int test_score = 0; 
	
	cout << "enter your tes score: ";
	cin >> test_score; 

	if (test_score >= 90){
		cout << "you got an A!!!" << endl; 
	}
	else if (test_score < 90 && test_score >= 80) {
		cout << "you got a B" << endl;
	}
	/*if (test_score >= 80)
		cout << "you got a B!!!" << endl;*/

	return 0;

}
