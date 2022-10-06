#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *pointHead = malloc(sizeof(List));
  pointHead -> root = NULL;
  return pointHead;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *current = list -> root;
  if(current == NULL){
    Item *new = malloc(sizeof(Item));
    new -> id = 0;
    new -> str = str;
    new -> next = NULL;
    list ->root = new;
  }
  else{
    while(current->next != NULL){
      current = current->next;
    }
    Item *tempData = malloc(sizeof(Item));
    tempData ->id = current->id+1;
    tempData->str = str;
    tempData->next = NULL;
    current->next = tempData;
  }
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item * current = list->root;
  while(current!= NULL){
    if(current->id == id){
      return current->str;
    }
    current=current->next;
  }
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *current=list ->root;
  while(current !=NULL){
    printf("%s", current->str);
    current =current->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
   Item *current= list->root;
   Item *temp;
   while(current != NULL){
     temp= current;
     free(temp->str);
     current = current -> next;
     free(temp);
   }
   free(list);
 }
