#define MAX_LIMIT 80
#define NUMBER_OF_STRING 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_tokens(char* str);
char** tokenize(char* str);
char *word_start(char* str);
bool non_delim_character(char c);
bool delim_character(char c);

int main()
{
   char str[MAX_LIMIT];
   printf("Enter a sentence to be tokenized:\n");
   fgets(str, MAX_LIMIT, stdin);

   char* pointer = str;
   /* get the num of tokens in given string and call malloc */
   int numTokens = count_tokens(pointer);
   printf("%d\n",numTokens);

   tokenize(pointer);


   /*


   char* new_string = (char*) malloc(numTokens * sizeof(char));
   printf("%d\n", *new_string);

   */




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


    /* Iterate through string until space is seen or the end is reached.
    Do second check when we break out to make sure we are not at end 
    returns pointer to first char of space seperated word*/


    char *pointer = str;

    if(delim_character(*pointer) == true){
        return word_start(pointer+1);
    }

    if(non_delim_character(*pointer) == true){
        char *p = pointer;
        return p;
    }

    return 0;

     

}





/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str){
    
    while(*str != '\0' && *str != ' '){
        str++;
    }
    return str;
}


// counts the number of words or tokens
int count_tokens(char* str){

    /* uses pointer to iterate through array of char and if space is seen then
    we have reached the end of a word and have found a token. Will iterate until end
    and return all tokens     */
    
    char * t;
    int size = 0;
    
    for (t = str; *t != '\0'; t++){

        if(delim_character(*t) == true){
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
    char* word = (char*) malloc(len * sizeof(char));

    for(int i = 0; i< len; i++){
        word[i] = *inStr;
        inStr++;
    }


    return word;

}




char** tokenize(char* str){
    char *newPointer = word_start(str);
    printf("%c\n",*newPointer);
    char *newNew = end_word(str);
    printf("%c\n",*newNew);
    return 0;
}





void print_all_tokens(char** tokens){

}
