#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_IN 300
int main(){
  //Variables
  char user[MAX_IN];
  char *token_history;
  char **tokens;
  int counter;
  List *pointer = init_history();

  while (user[0] != '3'){
    printf("Welcome to Tokenizer!\n1)Lets Tokenize\n2)Tokenization History\n3)Exit\n");
    fgets(user,MAX_IN,stdin);
      if(user[0] == '1'){
	printf("Enter sentence: ");
	fgets(user, MAX_IN, stdin);
	tokens = tokenize(user);
	print_tokens(tokens);
	free_tokens(tokens);
      }
    
    if(user[0] == '2'){
      printf("Not completed");
      pointer = init_history();
      add_history(pointer, user);
      token_history = get_history(pointer, counter);
      printf("%s\n", token_history);
      print_history(pointer);
      free_history(pointer);
    }
    if(user[0] == '3'){
      printf("Thank you for Tokenizing with me!\n");
      break;
    }
  }
}//end of main
