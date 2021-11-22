#include "parser.h"

main(int argc, const char *argv[]){
  if (argc != 2) {
    // incorrect number of arguments
    exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);        
}  

    printf("Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE *fin = fopen( argv[1], "r" );
  if(fin == NULL){ 
   exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);

    perror("Unable to open file!");
    exit(EXIT_FAILURE);
  }
  parse(fin);
  fclose(fin);
  return 0;
}


