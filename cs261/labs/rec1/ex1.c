#include <stdio.h>
 
void function (int *x, int n) {
    int i, t, j = n, s = 1;
    // loops infinitely while s = 1
    while (s) {
        //setting s = 0 breaks the while loop, means all numbers have been sorted
        s = 0;
        //loops through each index in the array 
        for (i = 1; i < j; i++) {
            //if current index is less than previous index condition
            if (x[i] < x[i - 1]) {
                //set current idnex value to temp variable t
                t = x[i];
                //current index gets the previous index value
                x[i] = x[i - 1];
                //previous index gets value from temp variable t
                x[i - 1] = t;
                //keeps s = 1 to run while loop
                s = 1;
            }
        }
        //decrement j
        j--;
    }
}
 
int main () {
    int x[] = {15, 56, 12, -21, 1, 659, 3, 83, 51, 3, 135, 0};
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", x[i], i == n - 1 ? "\n" : " ");
    function(x, n);
    for (i = 0; i < n; i++)
        printf("%d%s", x[i], i == n - 1 ? "\n" : " ");
    return 0;
}