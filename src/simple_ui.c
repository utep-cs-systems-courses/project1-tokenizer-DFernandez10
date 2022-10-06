#include<stdio.h>
#include<stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){

 
  char userInput[100];
  List *hist = init_history();
  while(1){
    printf("h= history, t=tokenize, q=quit");
    printf("== ");
    fgets(userInput, 95, stdin);
    if(userInput[0] == 'h'){
      print_history(hist);
      printf("clear history? y/n");
      printf("==");
      fgets(userInput, 95, stdin);
      if(userInput[0]=='y'){
	free_history(hist);
	break;
      }
    }
    if(userInput[0]=='q'){
      break;
    }
    if(userInput[0]=='t'){
      printf("Type string: \n");
      printf(">");
      fgets(userInput, 95, stdin);
      char **tokens = tokenize(userInput);
      print_tokens(tokens);
      //add_history(hist, userInput);
      // free_tokens(tokens);
    }
  }
  return 0;
}	    
