#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *head = (List *)malloc(sizeof(List));
  head -> root = NULL;
  return head;

}

void add_history(List *list, char *str){
}
char *get_history(List *list, int id);
void print_history(List *list);
void free_history(List *list);

