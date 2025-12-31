#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * return true (1) if n is happy, false (0) otherwise
 */
bool isHappy(int n) {
    int sumOfSquares = n; 
    int seen[100000] = { 0 }; //array
    while (sumOfSquares != 1) { // Loop until we reach 1
        int Sum = 0;
		// Loop through the digits of the current number
        while (sumOfSquares > 0) { 
			// Extract the rightmost digit
            int digit = sumOfSquares % 10; 
			// Add the square of the digtask it to the new sum
            Sum += digit * digit; 
            sumOfSquares /= 10;
        }
        sumOfSquares = Sum; // Set the new sum of squares as the current number
        if (seen[sumOfSquares] == 1) {
            return false; // not a happy number
        }
        seen[sumOfSquares] = 1; 
    }
    return true; // it's a happy number
}


/*
 * Below are testing functions... DO NOT MODIFY!!!
 */

void show_result(int e, int r){
	printf("Expected: %d\nActual: %d...", e, r);
	if (r != e) 
        printf("FAIL\n\n\n");
    else 
        printf("OK\n\n\n");
}



int main()
{
	printf("\nTEST 1...19\n");
	show_result(1, isHappy(19));

	printf("\nTEST 2...2\n");
	show_result(0, isHappy(2));

	printf("\nTEST 3...7\n");
	show_result(1, isHappy(7));

	printf("\nTEST 4...176\n");
	show_result(1, isHappy(176));

	printf("\nTEST 5...36\n");
	show_result(0, isHappy(36));

	

	return 0;
}
