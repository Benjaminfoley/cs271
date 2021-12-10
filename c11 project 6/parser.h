#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdint.h>
#include<stdbool.h>
#include"hack.h"
#ifndef __PARSER_H__
#define __PARSER_H__
#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH-2
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS
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
    opcode comp:7;
    opcode dest:4;
    opcode jump:4;
} c_instruction;

typedef struct a_instruction {
    union {
        hack_addr address;
        char * label;
    }hack_addr_or_label;
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union {
        enum instr_type a_instruction;
        enum instr_type c_instruction;
    } ;
    bool instr_type;
} instruction;

void add_predefined_symbols();

bool parse_A_instruction(const char *line, a_instruction *instr);

void parse_C_instruction(char *line, c_instruction *instr);

#endif