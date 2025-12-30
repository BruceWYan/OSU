#include <iostream>
#include <cstdlib>

using namespace std; 

int main(){
    srand(time(NULL));
    int scores[2][10]; 
    int i = 0, j = 0, k = 0; 

    for (j=0; j <10; j++){
        scores[0][j] = rand()%11;
        //cout score 
        scores[1][j] = rand()% (11-scores[0][j]);
        //cout score 
        //wreite text 
    }

    for (i=0;i<2;i++){
        for(j=0;j<10;j++){
            cout << scores[i][j] << " ";
        }
        cout << endl;
    }

    int total_[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int m=0;m<j;m++){
        if (k==0){
            total_[k] = scores[0][m] + scores[1][m]; 
            k++;
        }
        else if (k>0) {
            total_[k] = scores[0][m] + scores[1][m] + total_[k-1];
            k++;
        }
    }

    for (int k = 0; k <10; k++){
        cout << total_[k] << endl; 
    }

}