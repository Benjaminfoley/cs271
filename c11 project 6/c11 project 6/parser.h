#ifndef __PARSER_H__
#define __PARSER_H__
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "symtable.h"
#include "hack.h"
#ifndef __PARSER_H__
#define __PARSER_H__
#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH-2
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS
typedef int16_t hack_addr;
typedef int16_t opcode;
char *strip(char *s);
char *extract_label(const char *line, char* label);
int parse(FILE * file, instruction *instructions);
bool is_label(const char*)
bool parse_A_instruction(const char *line, a_instruction *instr);
bool is_Atype(const char*);
bool is_label(const char*);
bool is_Ctype(const char*);
void parse_C_instruction(char *line, c_instruction *instr);
void add_predefined_symbols();
void assemble(const char * file_name, instruction* instructions, int num_instructions);
opcode instruction_to_opcode(c_instruction instr);
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
        a_instruction a_instr;
        c_instruction c_instr;
    };
    bool instr_type;
} instruction;
#endif