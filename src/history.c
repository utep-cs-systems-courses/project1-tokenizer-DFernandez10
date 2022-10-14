#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *history;
  history = NULL;
  history = malloc(sizeof(List));
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *new = (Item*) malloc(sizeof(Item));
  int a =0;
  while(str[a] != '\0'){
    a++;
  }
  new->str = copy_str(str,a);

  if(list->root == NULL){
    list->root=new;
    new->id=1;
  }
  else{
    Item *temp = list->root;
    while(temp->next != NULL){
      new->id += 1;
      temp = temp->next;
    }

    temp->next=new;
    new->id += 1;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item * current = list->root;
  while(current!= 0){
    if(current->id == id){
      return current->str;
    }
    current=current->next;
  }
  return "not found";
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *current=list ->root;
  int i = 1;
  if(list == NULL){
    printf("Empty list\n");
    return;
  }
  printf("List: \n");
  while(current != NULL){
    printf("[%d] %s \n", i, current->str);
    current = current ->next;
    i++;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
   Item *current;
   while(list->root != NULL){
     current = list->root;
     list->root = list->root->next;
     free(current);
   }
   free(list);
 }
