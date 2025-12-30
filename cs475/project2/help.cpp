#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

unsigned int seed =  0;

float Ranf(unsigned int *seedp, float low, float high) {
    float r = (float) rand_r( seedp ); // 0 - RAND_MAX
    return(low+r*(high-low)/(float)RAND_MAX);
}

// // Returns random int in range
// int Ranf(unsigned int *seedp, int ilow, int ihigh) {
//     float low = (float)ilow;
//     float high = (float)ihigh + 0.9999f;
//     return (int)(Ranf(seedp, low,high));
// }

int main(){ 
    for (int i =0; i < 10; i++){
        int rand = Ranf(&seed, 1, 10);
        cout << rand << endl;
    }
    
}