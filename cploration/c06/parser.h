#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdint.h>
#include<stdbool.h>
#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH-2
typedef int16_t hack_addr;
typedef int16_t opcode;
char *strip(char *s);
void parse(FILE * file);
bool is_label(const char*)
char *extract_label(const char *line, char* label);
enum instr_type {
    Invalid = -1,
    A_type,
    C_type,
};
typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;

} c_instruction;

typedef struct a_instruction {
    union{
        hack_addr address;
        char * label;
    };
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union{
        enum instr_type a_instruction;
        enum instr_type c_instruction;
    }
} instruction;