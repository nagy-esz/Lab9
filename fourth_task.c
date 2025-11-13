/* Task description:Removing parts from strings
Visit HP too!

Write the inverse of the previous function: the part delimited 
by the start and end indices should be removed from the original 
text, and the rest is kept! 
The function should not modify the source string received as a 
parameter, a brand new string should be created dynamically, and 
returned by the function.

Write a C program to demonstrate the usage of the function. 
Don't forget to release the memory at the end.


*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substring(char* original, int start, int end){
  //calculate the length of the orgiginal string
  int len = strlen(original);
  //allocate memory for the modified string
  char* new = malloc((len-(end-start)+1)*sizeof(char));

  int j = 0;
  //first copy the fisrt part ot the original string
  for(int i = 0; i<start; i++){
    new[j++] = original[i];
  }
  //now copy the second part, so the removed part was nor copied
  for(int i = end; i<len; i++){
    new[j++] = original[i];
  }

  return new;

}
int main(void){
  char string[101] = "This is a text not containing anything rude or harsh"; // this is an array on the stack, mutable!
  char *substr = substring(string, 5, 10);
  printf("%s\n", substr);
  // Deallocate!!
  free(substr);

  return 0;
}
