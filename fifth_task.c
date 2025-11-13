/* Task description:Inserting strings into strings

This task is similar to the previous ones: the function receives a string, and creates a new one.

This time, however, the task is not to remove/cut something from a string,
but to insert another string to somewhere into the original string.
For instance, the result of insertstring("hello!", 5, ", world") is a new string
containing hello, world!: the second string has been inserted between letters "o" and "!".
*/

#include <stdio.h> //don't forget to include the required libraries
#include <string.h>
#include <stdlib.h>

char* insertstring(char* original, int place, char* add){
  int len1 = strlen(original);
  int len2 = strlen(add);
  //allocate memory for a new string containing both the original ones
  char* new = malloc((len1+len2+1)*sizeof(char));
  //first we copy the first part of the original one
  for (int i=0; i<place; i++){
    new[i] = original[i];
  }
  //second, we copy the add string to the right place
  for(int j = 0; j<len2; j++){
    new[place+j] = add[j];
  }
  //
  for(int i = place; i<len1; i++){
    new[place+len2++] = original[i];
  }

  return new;
}
int main(void)
{
  char original[101] = "Hello!";
  char add[101] = ", world";
  char* new = insertstring(original, 5, add);

  printf("%s\n", new);

  free(new);

  return 0;
}
