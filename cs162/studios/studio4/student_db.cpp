#include "student_db.h"

using namespace std;

Student* create_student_db(int size){
    Student* s_ptr = new Student [size]; // sptr points to array of structs in heap
    return s_ptr;
}

void populate_student_db_info(Student *roster, int size, ifstream &file){
    for (int i = 0; i < size; i++){
        file >> roster[i].id >> roster[i].first_name >> roster[i].last_name >> roster[i].major;
    }
}

void output_student_db_info (Student s, ofstream& file_out){
	file_out << s.id << " " << s.first_name << " " << s.last_name << " " << s.major << endl;
}

void delete_student_db_info(Student *roster, int size){
    if (roster){ //if roster does not equal null
        delete [] roster;
	    roster = NULL; 
    } 
}

void search_student(Student *roster, int size, ofstream& file_out_one){
    string user_last;
    cout << "Who do you want to search by last name?: ";
    getline(cin, user_last);
    for (int i = 0; i < size; i++){
        if (roster[i].last_name == user_last){
            file_out_one << "ID: " << roster[i].id << endl; 
            file_out_one << "First Name: " << roster[i].first_name << endl;
            file_out_one << "Last Name: " << roster[i].last_name << endl;
            file_out_one << "Major: " << roster[i].major << endl;
        }
    }
}

void unique_majors(Student *roster, int size, ofstream& file_out){
    int num_majors = 0, ctr = 0, same = 0;
    for (int i = 0; i < size -1; i++){
        for (int j = 0; j < size -1 ; j++){
            if (roster[i].major == roster[j+1].major){
                same++;
            }
            else if (roster[i].major != roster[j+1].major){
                ctr++;
                break;
            }
        }
    }
    file_out << ctr << endl;
}

void bubble_sort(Student *roster, int size){
    bool swapped; 
    for (int i = 0; i < size -1; i++){
        swapped = false;
        for (int j = 0; j < size - i - 1; j++){
            if (roster[j].id > roster[j+1].id){
                swap(roster[j].id, roster[j+1].id);
                swapped = true;
            }
        }

        if (swapped == false){
            break;
        }
    }
}