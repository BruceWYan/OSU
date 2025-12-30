#include <iostream> 
#include <ctime> //allows time()
#include <cstdlib> //include to allow rand() and srand() 

using namespace std; 

int main () 
{

	int x; 
	srand(time(NULL)); //seeds random number generator. do this just once
		
	x = rand() % 6;
	cout << "x = " << x << endl; 

	if (x == 0)
	{
		cout << "Bummer, I'm zero!!" << endl; 
	} 
	else if ((x%2) == 1) 
	{
		cout << "I'm an odd number!" << endl; 
	}
	else if ((x%2) == 0)
	{
		cout << "I'm an even number!" << endl; 
	}
	else if (x == 1)
	{
		cout << "I'm an odd number!" << endl;
	}
	return 0;
}
