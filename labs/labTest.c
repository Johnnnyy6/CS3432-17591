#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LIMIT 20

int count_tokens(char* str);
char** tokenize(char* str);
char *word_start(char* str);
bool non_delim_character(char c);
bool delim_character(char c);

int main()
{
    char str[MAX_LIMIT];
    fgets(str, MAX_LIMIT, stdin);

    char* pointer = str;
    int num_tokens = count_tokens(pointer);
    printf("%d\n",num_tokens);
    
    

    /* once we have # tokens, we call malloc*/
    /*
    char* new_string = (char*) malloc(num_tokens * sizeof(char));

    printf("%d\n", *new_string);
    
    */
    tokenize(pointer);




    


}

char** tokenize(char* str) {

    char *new_pointer = word_start(str);
    new_pointer++;
    printf("%c\n",*new_pointer);
    
    return 0;
}


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
bool delim_character(char c){
    if (c == ' ' || c == '\t'){
        return true;
    }
    return false;

}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c){
    if (c != ' ' || c != '\t'){
        return true;
    }
    return false;
}

/* Returns a pointer to the first character of the next
   space-separated word*/
char *word_start(char* str){
    char *pointer = str;
    
    if (non_delim_character(*pointer) == true){
        char *p = pointer;
        return p;
    }
    word_start(pointer +1);
    
    return 0;

}

/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str){
return 0;
}
// counts the number of words or tokens
int count_tokens(char* str){
    char * t; // copy the pointer to not change the original
    int size = 0;

    for (t = str; *t != '\0'; t++) {
        if (delim_character(*t) == true){
            size++;
        }
    }
    size++;

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

void print_all_tokens(char** tokens){

}

