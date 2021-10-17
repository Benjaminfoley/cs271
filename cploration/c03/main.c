//Exercise 1

#define MAX_LIMIT 200
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Exerciase 2

int main(int argc, const char *argv[]){
  if( argc <=1){
    printf("Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  //exercise 3

  FILE *fin = fopen( argv[1], "r" );
  if(fin == NULL){
    perror("Unable to open file!");
    exit(EXIT_FAILURE);
  }
  //Exercise 4

  char out_file[MAX_LIMIT];
    strcpy(out_file, argv[1]);
    strcat(out_file,".echo");
    FILE *fout;
    fout = fopen(out_file, "w+");

    //exercise 5
    char line[MAX_LIMIT] = {0};
    unsigned int line_num = 0;
    while (fgets(line, sizeof(line), fin)){
      line_num++;
      printf("[%04d] %s",line_num, line);
      fprintf(fout,line);
    }

    //Exercise 6

    fclose(fin);
    fclose(fout);
}