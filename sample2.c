#include<stdio.h>
// Importing the POSIX regex library
#include <regex.h> 

int main() {
  regex_t regex;
  int return_value;
  int return_value1;
  int return_value2;
  int return_value3;
  int return_value4;
  char x[20];
  printf("enter an expression : ");
  gets(x);
//   int return_value2;
  return_value = regcomp(&regex, "=", 0);
  return_value = regexec(&regex, x, 0, NULL, 0);
  if (return_value == 0){
      printf("assignment operator");
  }
  

//   return_value = regcomp(&regex,"=",0);
//   return_value = regexec(&regex, "a = b+c", 0, NULL, 0);
//   if (return_value == 0){
//       printf("assignment operator");
//   }
  
return_value1 = regcomp(&regex,"[a-zA-z]",0);
return_value1 = regexec(&regex, x, 0, NULL, 0);
if (return_value1 == 0){
    printf("\nvariables");
}
  
return_value2 = regcomp(&regex,"[+-/%]",0);
return_value2 = regexec(&regex, x, 0, NULL, 0);
if (return_value2 == 0){
  printf("\narthmetic operator");
}
 
return_value3 = regcomp(&regex,";",0);
   return_value3 = regexec(&regex, x, 0, NULL, 0);
   if (return_value3 == 0){
       printf("\ntermination\n");
   }
 
//   return_value2 = regcomp(&regex,"ice",0);
//   return_value2 = regexec(&regex, "frozen yoghurt", 0, NULL, 0);
//   print_result(return_value);
//   print_result(return_value2);
  return 0;
}
