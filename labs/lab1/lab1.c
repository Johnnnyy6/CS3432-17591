#define MAX_LIMIT 1000
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_tokens(char* str);
char** tokenize(char* str);
char *word_start(char* str);
bool non_delim_character(char c);
bool delim_character(char c);
void print_all_tokens(char** tokens,int len);


int main()
{
   char str[MAX_LIMIT];
   printf("Enter a sentence to be tokenized:\n");
   
   char* new_string = (char*) malloc(MAX_LIMIT * sizeof(char));
   scanf("%999[^\n]", new_string);
   
   char ** tokens = tokenize(new_string);
   int len = count_tokens(new_string);
   print_all_tokens(tokens,len);

   return 0;






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


    /*iterate through string and call delim_character method and non_delim method
    in order to check what type of char is in the index we are at. If current pos is a space
    call word_start method and move pointer. Method will be called until a non_delim char is seen*/


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
    
    /*base case, in case pointer is at the end of array*/
    if (*str == '\0'){
        return str;
    }
    /*Call recursively until we get the end of the word*/
    char *pointer = str; 
    if (delim_character(*pointer) == true){
        char *p = pointer;
        return p;
    }
    return end_word(pointer +1);
}


// counts the number of words or tokens
int count_tokens(char* str){

    /* uses pointer to iterate through array of char and if space is seen then
    we have reached the end of a word and have found a token. Will iterate until end
    and return all tokens */
    
    char * t;
    int size = 0;
    
    for (t = word_start(str); *t != '\0'; t++){

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

/* we start by creating a pointer of and filling it with all the characters of the given word. Once we fill it we return the word  */
char *copy_str(char *inStr, short len){
    char* word = (char*) malloc(len * sizeof(char));

    for(int i = 0; i< len; i++){
        word[i] = *inStr;
        inStr++;

    }


    return word;

}



/* we start by getting the number/len of tokens. We then create 3 different things, a pointer of pointers, a pointer to hold 
the start word and the end word. Once we create these we can then iterate with a loop and subtract the addresses of the start
and end pointer in order to obtain our word. We then copy that into our tokens pointer pointer. Once we iterate through all we 
return our double pointer. */
char** tokenize(char* str){

    int len = count_tokens(str);

    char** tokens = (char**) malloc(len * sizeof(char*));

    char* start = word_start(str);

    char* end = end_word(start);

    for(int i = 0; i < len; i++){
        tokens[i] = copy_str(start,end-start);
        start = word_start(end);
        end = end_word(start);
    }

    return tokens;
    
}





//iterate and print all tokens
void print_all_tokens(char** tokens,int len){

    int i = 0;
    for (char **p = tokens; *p; p++){
        printf("Token[%d] = %s\n",i,*p);
        i++;
    }

}