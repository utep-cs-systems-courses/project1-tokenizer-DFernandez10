#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t' || '\n'){
    return 1;
  }
  retuen 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(!space_char(c) && c != '\0'){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  if(*str == '\0'){
    return '\0';
  }

  int i = 0;
  while(space_char(*(str+i))){
    i+=1;
  }
  return str+i;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  int i;
  for(i=0; *(str + i) != '\0' && non_space_char (*(str + i)) ; i++){
  }
  return str+i;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int count = 0;
  for(int i=0; *(str + i) != '\0'; i++){
    if(non_space_char(*str)){
      str = word_end(str);
      count += 1;
    }
    else{
      str = word_start(str);
    }
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);
