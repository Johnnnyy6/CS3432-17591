#define MAX_LIMIT 80
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_tokens(char* str);

int main()
{
   char str[MAX_LIMIT];
   printf("Enter a sentence to be tokenized:\n");
   fgets(str, MAX_LIMIT, stdin);

   char* pointer = str;
   printf("%d",count_tokens(pointer));

}


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
bool delim_character(char c){
    if(c == ' ' || c == '\t'){
        return true;
    }

    return false;

}


/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c){

    if(c != ' ' || c != '\t'){
        return true;
    }

    return false;


}


/* Returns a pointer to the first character of the next
   space-separated word*/
char *word_start(char* str){

    return 0;
}





/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str){
    char* nextChar;


    return nextChar;
}


// counts the number of words or tokens
int count_tokens(char* str){
    
    char * t;
    int size = 0;
    
    for (t = str; *t != '\0'; t++){

        if(delim_character(*t) == true){
            size++;
        }

    }
    size ++;

    return size;

}



/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/


char *copy_str(char *inStr, short len){
    return 0;

}



/*
char** tokenize(char* str){
    char* new_string = (char*) malloc(str_size * sizeof(char));
    printf("%s",new_string);
    return 0;
}
*/





void print_all_tokens(char** tokens){

}
