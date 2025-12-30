#include "student_db.h"

using namespace std; 

int main(){
    int num_unique_majors = 0;

    ifstream file; //create an input-only file obj

	file.open("input.txt");

	//check if the file is not successfully open
	if (!file.is_open()){
		cout << "Error opening the file..." << endl;
		return 1;
	}

    Student *roster;
    int size = 0;
    file >> size;
    roster = create_student_db(size); //creates a ptr to array in heap
    populate_student_db_info(roster, size, file); //takes information from input.txt and stores into array of structs
    bubble_sort(roster, size); //sorts the information in the array
    
   

    file.close();

    ofstream file_out;
    ofstream file_out_one;
    file_out.open("out.txt");
    
    unique_majors(roster, size, file_out); // counts unique majors

    for (int i = 0; i < size; i++){ //prints information from array in heap to new file 
        output_student_db_info(roster[i], file_out);
    }
    file_out.close();
    
    file_out_one.open("student.txt");

    search_student(roster, size, file_out_one);
    
    file_out_one.close();
    delete_student_db_info(roster, size);

}