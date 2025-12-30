#include <iostream> 
#include <string>
#include <cstring> 

using namespace std;

//the struct to store personal information 
struct person {
	char first[128]; //a c-string to store the first name
	char last[128]; //a c-string to store the last name
	char email[128]; //a c-string to store the email
};

//the struct to store Education Background
struct Edu {
	char univ[128]; //a c-string to store the university name
	char major[64]; //a c-string to store the major
	int graduate_year; //graduation year
	float GPA; //GPA
	//additional members go here…
};

//the struct to store one work experience
struct Exp {
	char company[64]; //a c-string to store the company name
	char start_date[64]; //a c-string to store the start date
	char end_date[64]; //a c-string to store the end date
	char des[1024]; //the description of the work experience
	//additional members go here…
};
void get_person (

//get each skill, as a string, from the user, and store them into the array of string, sk. The size of the array is sk_size.
void get_skills (string sk[], int sk_size);

//get each work experience, as an Exp struct object, from the user, and store them into the array of Exp, ex. The size of the array is ex_size.
void get_exp (Exp ex[], int ex_size);

//the function to build the resume with all user inputs. Create your own design of resume template here. Be creative! :)
void build_resume (ofstream& f,
	Basics b,
	Exp ex[], int ex_size,
	string sk[], int sk_size);

int main() {



}
