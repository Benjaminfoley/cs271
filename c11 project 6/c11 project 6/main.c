#include "parser.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_INSTRUCTION_COUNT 30000

main(int argc, const char *argv[]){
  assemble(argv[1], instructions, num_instructions);
  if (argc != 2) {
    exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);     
  

    printf("Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  instruction *instructions = malloc(MAX_INSTRUCTION_COUNT * sizeof(instruction));
  FILE *fin = fopen( argv[1], "r" );
  if (fin == NULL){ 
    exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
    perror("Unable to open file!");
    exit(EXIT_FAILURE);
  }
  int num_instructions = parse(fin, instructions);
  fclose(fin);

  free(instructions);
  return 0;
}



