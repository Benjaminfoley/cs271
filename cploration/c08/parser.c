#include "parser.h"
void parse(FILE* file){
    char line[MAX_LINE_LENGTH]= {0};
    char line_num;
    char instr_num;
    if(instr_num>MAX_INSTRUCTIONS){
        exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTION + 1);
    }
    while(fgets(line,sizeof(line),file)){
        line_num
        strip(line);
        if(!*line){
            continue;
        }
        printf("%s\n",line);
        instr_num
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


char*extract_label(char *line, char *label);{
    strncpy(label, line+1, strlen(line)-2);
    return label;
}