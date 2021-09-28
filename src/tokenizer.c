#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 0;
  }
  return 1;
}
 
int non_space_char(char c){
  if(c != ' ' && c != '\t' && c != '\0'){
    return 0;
  }
  return 1;
}

char *word_start(char *str){
  char *pointer = str;
  int i = non_space_char(*pointer);
  while(i == 0 && *pointer != '\0'){
    i = non_space_char(*pointer);
    if (i == 1){
      break;
    }
    pointer++;
  }
  return pointer;
}


char *word_terminator(char *word){
  char *pointer = word;
  int i = space_char(*pointer);
  while(i == 0 && *pointer != '\0'){
    i = space_char(*pointer);
    if(i == 1){
      break;
    }
    pointer++;
  }
  return pointer;
}

int count_words(char *str){
  int words = 0;
  for (char *pointer = str; *pointer != '\0'; *pointer++){
    if(*pointer == ' '&& *pointer != '\0'){
      pointer = word_terminator(pointer);
    }
    if (*pointer != ' ' && *pointer != '\0'){
      pointer = word_start(pointer);
      words++;
    }
    if(pointer == NULL || *pointer == '\0'){
      break;
    }
  }
  printf("%d words in the sentence\n", words++);
  return words;
}


char *copy_str(char *inStr, short len){
  int i= 0;
  char *pointer = (char *) malloc(len*sizeof(char)+1);
  while(*inStr != '\0' && i < len){
    pointer[i] = *inStr;
    i++;
    inStr++;
  }
  if(len == 1 && *inStr == '\0'){
    pointer[i] = *inStr;
  }
  return pointer;
}

char **tokenize(char* str){
  char *pointer_word = str;
  int words = count_words(str);
  char **tokens = (char **) malloc(sizeof(char *) * (words+1));
  int iter = 0;
  int empty_spaces = 0;
  short len = 0;
  while (iter <= words && *pointer_word != '\0'){
    for(char *pointer = pointer_word; *pointer != '\0' && *pointer != ' '; pointer++){
	len++;
    }
    tokens[iter] = copy_str(pointer_word, len);
    pointer_word += len;
    for (char *pointer = pointer_word; *pointer != '\0' && *pointer == ' ';pointer++){
      empty_spaces++;
    }
    pointer_word += empty_spaces;
    len = 0;
    empty_spaces = 0;
    iter++;
  }
  tokens[iter+1] = copy_str(pointer_word,0);
  return tokens;
}

void print_tokens(char **tokens){
  int j = 0;
  while(tokens[j] != 0){
    printf("Tokens[%d] = %s\n", j, tokens[j]);
    j++;
  }
}

void free_tokens(char **tokens){
  char **tmp = tokens;
  while(*tokens !=0){
    free(*tokens);
    tokens++;
  }
  free(tmp);
}
