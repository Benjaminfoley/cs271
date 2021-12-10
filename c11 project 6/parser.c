#include "parser.h"
#include "error.h"
#include "symtable.h"
int parse(FILE * file, instruction *instructions){
    char line[MAX_LINE_LENGTH]= {0};
    unsigned int line_num = 0;
    unsigned int  instr_num = 0;
    predefined_symbols();
    instruction = instr;

    while(fgets(line,sizeof(line),file)){
        line_num++;
        if(instr_num> MAX_INSTRUCTIONS ){
            exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
        }
        strip(line);
        if(!*line){
            continue;
        }
        if is_Atype(line){
            inst_type = 'A';
            if (! parse_A_instruction(line, & instr.a_instruction){
                exit_program(EXIT_INVALID_A_INSTR,line_num,line);
            }  
            instr.instr_type = A_type;
        }
            else if (is_Ctype(line)) {
            inst_type = 'C';
        
            char tmp_line[MAX_LINE_LENGTH] = {0};
            strcpy(tmp_line, line);
            parse_C_instruction(tmp_line, &instr.c_instr);
            printf("Jump:%d\n\n", instr.c_instr.jump);
            if (instr.c_instr.comp == COMP_INVALID) {
                exit_program(EXIT_INVALID_C_COMP);
            } else if (instr.c_instr.dest == DEST_INVALID) {
                exit_program(EXIT_INVALID_C_DEST);
            } else if (instr.c_instr.jump == JMP_INVALID) {
                exit_program(EXIT_INVALID_C_JUMP);
            }
            instr.instr_type = C_TYPE;
            }
            else if (is_label(line)) {
            if (isalpha(line[0])) {
                exit_program(EXIT_INVALID_LABEL, line_num, line);
            } 
            else if (symtable_find(line) != NULL) {
                exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
            }
            symtable_insert(line, instr_num);
            continue;
            inst_type = 'L';
            char new_label[MAX_LABEL_LENGTH];
            extract_label(line, new_label);
            printf("%c  %s\n", inst_type, new_label);
            continue;
        } 
        instructions[instr_num++] = instr;
    }
    return instr_num;
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
bool is_Atype(const char *line){
    return line[0]== "@";
}
bool is_Ctype(const char *line){
    return !(is_Atype(line) || is_label(line))
}
bool is_label(const char*){
  if(line=[0])== '('&& line [strlen(line)-1] ==')')
  return true;
  else{
    return false;
  }
}


char *extract_label(char *line, char *label, char *line_num){
    strncpy(label, line+1, strlen(line)-2);
    return label;

}

//step 4 cploration 9
void add_predefined_symbols(){
    
    for(int i=0; NUM_PREDEFINED_SYMBOLS; i++){
        predefined_symbol symbol = predefined_symbols[i];
        symtable_insert(symbol.name,symbol.address);
    }
}
bool parse_A_instruction(const char *line, a_instruction *instr){
    char *s = (char*)malloc(strlen(line));
    strcpy(s, line+1);
    char *s_end = NULL;
    long result =strtol (s, & s_end, 10);
    if(s==s_end){
        instr->label = malloc(strlen(line));
        strcpy(instr->label, s);
        instr-> is_addr = false;
    }
    else if(*s_end !=0){
        return false;
    }
    else{
        instr-> address = result;
        instr-> is_addr = true;
    }
    return true

}
void parse_C_instruction(char *line, c_instruction *instr){
    char *temp = strtok(line, ";");
    char *jump = strtok(NULL, ";");
    char *dest = strtok(temp, "=");
    char *comp = strtok(NULL, "=");
    if (comp == NULL) {
    comp = dest;
    dest = NULL;
    }
    int *a = malloc(sizeof (int));
    instr->comp = str_to_compid(comp, a);
    instr->jump = str_to_jumpid(jump);
    instr->dest = str_to_destid(dest);
    instr->a = (*a == 0) ? 0x1 : 0x0; 
}
void assemble(const char * file_name, instruction* instructions, int num_instructions) {
  char* file_name_with_hack = "";
  strcpy(file_name_with_hack, file_name);
  strcat(file_name_with_hack, ".hack"); 
  FILE *fw = fopen(file_name_with_hack, "w");

  for (int i = 0; i < num_instructions; i++) {
    instruction current = instructions[i];
    opcode current_code = 0;

    if (current.a_instr.label) {
      Symbol* entry = symtable_find(current.a_instr.label);
      if (entry == NULL) {
        int16_t nums = 16;
        symtable_insert(current.a_instr.label, nums);
        current_code = nums; 
      } else {
        current_code = entry->address;
      }
      free(current.a_instr.label);
    } else if (current.a_instr.is_addr) {
       current_code = current.a_instr.address;
    } else if (current.instr_type == C_TYPE) {
      current_code = instruction_to_opcode(instructions->c_instr);
    }
    fprintf(fw, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", OPCODE_TO_BINARY(current_code));
    fclose(fw);
    }
}
opcode instruction_to_opcode(c_instruction instr) {
   opcode op = 0;
   op |= (7 << 13);
   op |= (instr.a << 12);
   op |= (instr.comp << 6);
   op |= (instr.dest << 3);
   op |= (instr.jump);
  return op;
}
