Hi Ella Riis thank you for grading my assignment. Merry Christmas~! 

Name: Bruce Yan
ONID: yanbr@oregonstate.edu
ID: 934144589
Section: [CS162-020]

Description: A program that tests a self-implemented linked list class. A linked list is a 
    type of storage container which includes a node which contains the value that is being 
    stored and a pointer that references the next node or value in the list. In this program 
    we include two .h files one that defines a Node class and another that defines a linked 
    list class. In the linked list class we define a linked list object which has member 
    functions that add values to the list, deletes the list, sorts the list, counts the 
    length of the list, and then counts the number of prime numbers in the list. 

    The test_linked_list.cpp program will take our implemented linked_list class and then 
    check to see if the member functions in the implemented linked_list class does what it's
    supposed to do.

Instructons: In order to use this program, we must insure that we are in the correct file 
    directory. In your terminal, enter "ls", this should list the files in your directory, 
    if assign5.zip is not in there, you will either need to download the zip file or find 
    the directory where assign5.zip is located. Once you are in the directory enter
    "unzip assign5.zip" to unzip the zip file containing the file for this program. Once 
    you've unzipped the assign5.zip file you want to go into the "linked_list" folder, thus 
    you must enter "cd linked_list" into the terminal. Once you are in the linked_list 
    folder, type in "make" into the terminal and the program should compile. Once compiled, 
    type the executive file "linked_list" into the terminal and the progrma should run.

    You will be prompted to press enter and a test will be ran to test the self-implemented
    linked list class

Limitations: no inputs, the program will only test to check if the implemented linked list 
    class is working properly

Complexity Analysis: 
    sort_ascending(): O(log base 2 of n)
    sort_descending(): O(log base 2 of n)
    count_prime(): O(n)