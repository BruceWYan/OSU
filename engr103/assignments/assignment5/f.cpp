#include <iostream> 
#include <fstream> 

using namespace std;

int main() {
	//f.open("fuck.text");
	//f << "hi there bitch ass mof0" << endl;

	ofstream fout;
	fout.open("fuc.text", ios::trunc);
	if (!fout.is_open()){
		cout << "Error bitch" << endl;
		return 1;
	}
		
	fout << "fuck you" << endl; 
	fout.close();


}
