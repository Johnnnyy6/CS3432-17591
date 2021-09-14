#include <stdio.h>
#define MAX_LIMIT 80

char** tokenize(char* str);


int main()
{
   char str[MAX_LIMIT];
   printf("Enter a sentence to be tokenized:\n");
   fgets(str, MAX_LIMIT, stdin);

   char* x;
   tokenize(x);
   return 0;
}

char** tokenize(char* str){
    return 0;
}