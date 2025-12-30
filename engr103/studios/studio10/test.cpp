#include <iostream> 
#include <string> 
#include <cstring> 
#include <fstream>

using namespace std;

struct student{
	unsigned int id; 
	string name;
	string major;
	float GPA;
}; 

void populate_student_db_info(student std_arr[], int n, ifstream & fin);
float avg_gpa(student std_arr[], int total_students);
int num_cs (student std_arr[], int total_students);
void highest_gpa(student std_arr[], int n); 

int main() {
	ifstream fin;
	//ofstream fout;
	fin.open("input.txt"); //can ask them to cin the file name 
	
	if (!fin.is_open()){
		cout << "File does not exist" << endl; 
		return 1; 
	}

	int total_students;
	student students[50]; 
	fin >> total_students; //like the cin func 
	populate_student_db_info(students, total_students, fin); 
	highest_gpa(students, total_students);
	cout << avg_gpa(students, total_students) << endl;
	cout << num_cs(students, total_students) << endl;

	fin.close();

	return 0;
}

void populate_student_db_info(student std_arr[], int n, ifstream & fin){
	for (int i = 0; i < n; i++){
		fin >> std_arr[i].id;
		fin >> std_arr[i].name;
		fin >> std_arr[i].major;
		fin >> std_arr[i].GPA;
	
	}
}

void highest_gpa(student std_arr[], int n){ 
	float highest;
	for (int i = 0; i < n; i++){
		if (std_arr[i].GPA < std_arr[i+1].GPA){
			highest = std_arr[i+1].GPA;
		}
		else if (std_arr[i].GPA > std_arr[i+1].GPA){
			highest = std_arr[i].GPA;
		}
		else if (std_arr[i].GPA == std_arr[i+1].GPA){
			highest = std_arr[i].GPA;
		}
	}
	for (int i =0; i < n; i++){
		if (std_arr[i].GPA == highest){
			cout << std_arr[i].name << " has the highest GPA" << endl;
		}
	
	}
}

float avg_gpa(student std_arr[], int total_students){
	float total =0 ;
	for (int i = 0; i < total_students; i++){
		total += std_arr[i].GPA;
	}
	total /= total_students;
	return total;
}

int num_cs (student std_arr[], int total_students){
	int total = 0;
	for (int i = 0; i < total_students; i++){
		if (std_arr[i].major == "CS"){
		total++; 
		}
	}
	return total;
}
