#include <iostream>

using namespace std;

void execute(int &x, int y = 200) {
	int temp = x + y;
	x += temp;
	if(y != 200)
		cout << temp << " " << x << " " << y << endl;
}

int main() {
	int a = 50, b = 20;
	cout << a << " " << b << endl;
	execute(a, b);
	cout << a << " " << b << endl; 
	return 0;

}
