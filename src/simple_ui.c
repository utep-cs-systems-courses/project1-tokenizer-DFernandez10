#include<stdio.h>
#include<string.h>
#include "tokenizer.h"

int main(){
  char str[100];

  gets(str);

  printf("num of words %d \n", count_words(str));

  return 0;
}

