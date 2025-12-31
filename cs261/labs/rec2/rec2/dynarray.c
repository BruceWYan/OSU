/* CS261 - Reciation 2*/
/* Description: create a array of integers and struct student by giving the size of array, 
                and sort them using sort() and function pointers
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

struct student{
	int id;
	int score;
};

//helper function to compare students by their scores
int compare_student (void* x, void* y){
	struct student *s1 = x;
	struct student *s2 = y;
	return s1->score > s2->score ? 1 : 0;
}

//helper function to compare two ints
int compare_int (void* x, void* y){
	int* a = x, *b = y;
	return *a > *b ? 1 : 0;
}

/* sort the arr array by using a function pointer to 
 * compare its elements
 * Param: 
 *		void** arr                 - array of generic type 
 *      int n                      - array size
 *      int(*cmp)(void* a, void* b)- function pointer to compare two elements in the array 
 */
//void sort(void** arr, int n, int(*cmp)(void* a, void* b))
void sort(void** arr, int n, int(*cmp)(void* a, void* b)){
    //int i, j = n, s = 1;
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (cmp(arr[j], arr[j + 1]) == 1){
                void* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // while(s){
    //     s = 0;
    //     for (i = 1; i< j; i++){
    //         if(cmp(&arr[i], &arr[i - 1]) == 0){
    //             int* temp = arr[i];
    //             arr[i] = arr[i-1];
    //             arr[i-1] = temp;
    //             s = 1;
    //         }
    //     }
    //     j--;
    // }

    return;


    // /*Sort n integers in arr, ascending order*/
	// int i, j = n, s=1;
    // while(s){
    //     s =0;
    //     for (i = 1; i < j; i++){
    //         if (arr[i] < arr[i-1]){
    //             int temp = arr[i];
    //             arr[i] = arr[i-1];
    //             arr[i-1] = temp;
    //             s=1;
    //         }
    //     }
    //     j--;
    // }

	 
}


/* free the memeory allocated by arr
 * Param: 
 *      void** arr                 - array of generic type 
 *      int n                      - array size
 */
void free_arr (void** arr, int n){
	/* free the memory allocated by arr*/
	for (int i = 0; i < n; i++){
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}

int main(){
    srand(time(NULL));

    /*Declare an integer n and assign 10 to it.*/
    int n = 10;
    /***Step 1: sort an integer array ***/
    
    /*Allocate memory for n integers using malloc.*/
    int** arr = malloc(sizeof(int*) * n);
    /*Generate random ints (0-100, inclusive) for the n integers, using rand().*/
    for (int i = 0; i < n; ++i){
        arr[i] = malloc(sizeof(int));
        *(arr[i]) = rand() % 101;
    }
    /*Print the contents of the array of n students.*/
    printf("\nBefore sorting....\n");
    for (int i = 0; i < n; i++){
        printf( "%d ", *(arr[i]));
    }
    /*call sort() function to sort*/
    sort((void**)arr, n, compare_int);
    /*Print the contents of the array of n students.*/
    printf("\nAfter sorting....\n");
    for (int i = 0; i < n; i++){
        printf("%d ", *(arr[i]));
    }



    /***Step 2: After modifying sort() by using function pointer, modify your sort() function call above ****/




    /***Step 3: sort an array of students ***/

    /*Allocate memory for n students using malloc.*/
    struct student** s_arr = malloc(n * sizeof(struct student*));
    
    /*Generate random IDs and scores for the n students, using rand().*/
    /*note: 
     *    1. no two students should have the same ids 
     *    2. score and id range: 0-100, inclusive
     */

    for (int i = 0; i < n; i++){
        int id = rand() % 101;
        int score = rand() % 101;
        s_arr[i] = malloc(sizeof(struct student));
        
        s_arr[i]->id = id;
        
        s_arr[i]->score = score;
       
    }

    /*Print the contents of the array of n students.*/
    printf("\nBefore sorting....\n");
    for(int i = 0; i < n; i++){
        printf("Student: %d \tStudent ID: %d \tScore: %d\n", i + 1, s_arr[i]->id, s_arr[i]->score);
    }

    /*call sort() function to sort*/
    sort((void**)s_arr, n, compare_student);
    
    /*Print the contents of the array of n students.*/
    printf("\nAfter sorting....\n");
    for(int i = 0; i < n; i++){
        printf("Student: %d \tStudent ID: %d \tScore: %d\n", i + 1, s_arr[i]->id, s_arr[i]->score);
    }

    

    /***Step 4: free the memory allocated in Step 1-3 by calling free_arr() ***/

    free_arr((void**)s_arr, n);
    free_arr((void**)arr, n);
    

    return 0;
}
