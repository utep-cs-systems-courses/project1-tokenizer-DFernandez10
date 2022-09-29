#include<stdio.h>
#include<stdlib.h>
#include "tokenizer.h"

int main(){


  // need to create a list for history
  printf(">");
  while(1){
    printf("$");
    char str[256];
    gets(str);
    if(str[1] == '\0'){
      if(str[0] == 'q'){
	break;
      }else if(str[0] == 'h'){
	printf("h pressed");
      }
      continue;
    }else if(str[0] == '!' && str[2] == '\0'){
     printf("meh");
     continue;
    }else{
      char **tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
    }
    // need to use history methods with new list
  }
  //same as last comment
  return 0;
}
