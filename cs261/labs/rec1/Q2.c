/* CS261- Recitation 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7;
    int y = 8;
    int z = 9;
    int c = 0;
    /*Print the values of x, y and z*/
    printf("x = %d, y = %d, z = %d\n", x, y,z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    c = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("c = %d\n", c);
    /*Print the values of x, y and z again*/
    printf("x = %d, y = %d, z = %d\n", x, y,z);

    /*Is the return value different than the value of z?  Why? */
    //The reason why z is so different than the value we returns from our foo() function
    //is because when we pass in x and y, we pass in the memor address of those variables
    //whereas for z, we are only passing in a copy of the value. In the function
    //we change the values being passed in by pointers whereas we only manipulate the value passed in by copy.
    return 0;
}
    
    
