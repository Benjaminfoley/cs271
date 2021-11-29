#include "parser.h"
#include "error.h"
#include "symtable.h"
void parse(FILE* file){
    char line[MAX_LINE_LENGTH]= {0};
    char line_num = 0;
    char instr_num = 0;
    
    while(fgets(line,sizeof(line),file)){
        line_num++;
        if(instr_num> MAX_INSTRUCTIONS ){
            exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
        }
        strip(line);
        if(!*line){
            continue;
        }
    if (isalpha(line[0])){
        exit_program(EXIT_INVALID_LABEL, line_num, line);
    }
    if (symtable_find(label) == NULL){
        exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
    }
    stymtable_insert(label);
        continue;
        printf("%s\n",line);
        instr_num++;


    }

}

char *strip(char *s){
    char s_new[strlen(s)+1];
    int i = 0;
    for(*s2 = s;*s2;s2++){
        if ((*s2) == '/' && *(s2+1)== '/'){
            break;
        }
        else if(!isspace(*s2)) {
                s_new[i++]= *s2;
        }
    }
    s_new[i]='\0';
    strcpy(s, s_new);
    return s;  
}
bool is_label(const char*){
  if(line=[0])== '('&& line [strlen(line)-1] ==')')
  return true;
  else{
    return false;
  }
}


char*extract_label(char *line, char *label, char *line_num){
    // strncpy(label, line+1, strlen(line)-2);
    // return label;

}

//step 4 cploration 9
void add_predefined_symbols()
