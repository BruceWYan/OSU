#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <iostream> 
#include <fstream> 

using namespace std; 

// dynamic array >> created when program is ran 

struct Student{
    int id; 
    string first_name;
    string last_name; 
    string major;
};

Student* create_student_db(int size);

void populate_student_db_info(Student *roster, int size, ifstream &file);

void output_student_db_info (Student s, ofstream& file_out);

void delete_student_db_info(Student *roster, int size);

void search_student(Student *roster, int size, ofstream& file_out_one);

void unique_majors(Student *roster, int size, ofstream& file_outs);

void bubble_sort(Student *roster, int size);

#endif