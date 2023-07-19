#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Test.txt"

int main(){
  FILE *fp = NULL;
  char ch;
  int lineCount = 0;

  fp = fopen(FILENAME, "r");

  if(fp == NULL){
    printf("File does not exist\n");
    return -1;
  }

  while ((ch = fgetc(fp)) != EOF){
    if (ch == '\n'){
      lineCount++;
    }
  }
  fclose(fp);
  fp = NULL;

  printf("Total number of lines are %d\n", lineCount);

	return 0;
}
