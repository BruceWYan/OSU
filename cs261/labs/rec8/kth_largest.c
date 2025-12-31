#include <stdio.h>
#include <stdlib.h>

void make_heap(int* nums, int numsSize, int i){
    
    int big = i; // assume the biggest element is at i
    // index of left child
    int l = 2 * i + 1;
    // index of right child
    int r = 2 * i + 2;

    // if left child is less than the size of the array and number of the 
    // child is less than the value of the number we are comparing it to
    if (l < numsSize && nums[l] > nums[big]){
        big = l; // set that number equal to the child
    }
    
    // same for right
    if (r < numsSize && nums[r] > nums[big]){
        big = r;
    }

    // if big is not i, which means if either child was less
    if (big != i){ 
        int temp = nums[i]; // swap the child with the parent
        nums[i] = nums[big];
        nums[big] = temp;
        make_heap(nums, numsSize, big); // recursively call function on the swapped element to ensure heap property is maintained
    }
}

void heapsort(int* nums, int numsSize){
    // passes in all parents in the array to organize
    for (int i = numsSize / 2 - 1; i >= 0; i--) 
        make_heap(nums, numsSize, i); // make heap for the array

    // swap the root of the binary tree with the last leaf, 
    // decrease the size of the heap, and restore the heap property

}

int findKthLargest(int* nums, int numsSize, int k)
{
    heapsort(nums, numsSize); //sort the heap from smallest to largest

    int j = numsSize;

    for (int i = 0; i < k - 1; i ++){ 
        int temp = nums[0]; // swap the root with the last element
        nums[0] = nums[j-1];
        nums[j-1] = temp;
        make_heap(nums, j-1, 0); // make heap for the updated sub-array excluding the last element
        j--;
    }

    return nums[0]; //return the kth largest value
}



int main(int argc, char **argv)
{
    
    printf("\nTest 1...\n");
    int num1[6] = {3,2,1,5,6,4};
    printf("2nd largest in [3 2 1 5 6 4]\n");
    printf("Expected: 5\n");
    printf("Actual: %d\n", findKthLargest(num1, 6, 2));

    printf("\nTest 2...\n");
    int num2[9] = {3,2,3,1,2,4,5,5,6};
    printf("4th largest in [3 2 3 1 2 4 5 5 6]\n");
    printf("Expected: 4\n");
    printf("Actual: %d\n", findKthLargest(num2, 9, 4));


    printf("\nTest 3...\n");
    int num3[5] = {10,10,10,10,10};
    printf("5th largest in [10 10 10 10 10]\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", findKthLargest(num3, 5, 5));

    printf("\nTest 4...\n");
    int num4[7] = {-10,10,-10,10,-10,10,0};
    printf("4th largest in [-10 10 -10 10 -10 10 0]\n");
    printf("Expected: 0\n");
    printf("Actual: %d\n", findKthLargest(num4, 7, 4));

    printf("\nTest 5...\n");
    int num5[10] = {10,9,8,7,6,5,4,3,2,1};
    printf("1st largest in [10 9 8 7 6 5 4 3 2 1]\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", findKthLargest(num5, 10, 1));


    return 0;
}