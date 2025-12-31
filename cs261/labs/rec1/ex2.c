#include <stdio.h>

int function(int num, int ctr) {
  int i;
  //runs a loop from 2 to the midpoint of num
  for(i = 2;i <= num/2; i++){
    //if at any point num is divisible by i, then ctr will increase
    if(num % i==0){
      ctr++;
      //break the loop
      break;
    }
  }
  //a prime number will have ctr == 0 
  if(ctr == 0 && num != 1)
    return 1;
  //if ctr is not 0 then return 0
  else
    return 0;
}

int main(){

  int num, ctr = 0, r = -1;
  printf("Input a number: ");
  scanf("%d",&num);
  
  r = function(num, ctr);
  printf("%d\n", r);

  return 0;
}