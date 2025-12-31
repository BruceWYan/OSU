/* CS 261 Recitation 4: Anagram Detector
 */

#include <stdio.h>
#include <string.h>

/*
  The Function checks two given strings (a, b) and return
  1 if they are anagram, and 0 otherwise
  Assuming:
  1. a and b are of the same length
  2. a and b are made up of symbols from the set of 26 lowercase characters
 */

int check_anagram(char *a, char *b)
{
  int letters[26] = {0};
  int len = strlen(a);
  //same lenght
  if (len != strlen(b))
    return 0;
  //ascii 
  for (int i = 0; i < len; i++){
    //offset alphabet
    letters[a[i] - 'a']++;
    letters[b[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++){
    if(letters[i] != 0)
      return 0;
  }

  return 1;
}


int main()
{
  
  printf("Test 1.....\n");
  printf("\"heart\", \"earth\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("heart", "earth"));


  printf("Test 2.....\n");
  printf("\"python\", \"typhon\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("python", "typhon"));

  printf("Test 3.....\n");
  printf("\"race\", \"care\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("race", "care"));

  printf("Test 4.....\n");
  printf("\"listen\", \"silent\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("listen", "silent"));

  printf("Test 5.....\n");
  printf("\"seal\", \"leaf\"\n");
  printf("Expected: 0 \n");
  printf("Acutal: %d\n\n", check_anagram("seal", "leaf"));

  printf("Test 6.....\n");
  printf("\"asdfghjkl\", \"aasdfghjk\"\n");
  printf("Expected: 0 \n");
  printf("Acutal: %d\n\n", check_anagram("asdfghjkl", "aasdfghjk"));

  printf("Test 7.....\n");
  printf("\"ben\", \"fan\"\n");
  printf("Expected: 0 \n");
  printf("Acutal: %d\n\n", check_anagram("ben", "fan"));

  

  return 0;
}

