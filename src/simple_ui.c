#include<stdio.h>
#include<stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 400

int main(){
  char userInput[MAX];
  char** tokens;
  List *history = init_history();

  printf("> h= history, != specific history, q= quit");
  
  while(userInput[0] != 'q' && userInput[0]){
    putchar('>');
    fgets(userInput,MAX, stdin);

    printf("String typed: %s", userInput);

    tokens = tokenize(userInput);
    print_tokens(tokens);
    add_history(history, userInput);
    
    if (userInput[0] == 'h'){
      print_history(history);
    }
    
    else  if (userInput[0] == '!'){
      char *h = get_history(history,atoi(userInput+1));
      char **tokens = tokenize(h);
      printf("History: %s\n", h);
      printf("Tokenized history:\n");
      
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }
  return 0;
}
