#ifndef __SYMTABLE_H__
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define __SYMTABLE_H__
#define SYMBOL_TABLE_SIZE  10000
typedef int16_t hack_addr;
typedef struct {
    hack_addr address;
    char* name;
}Symbol;

Symbol* hashArray[SYMBOL_TABLE_SIZE];
int hash(char *str);
struct Symbol *symtable_search(char * key);
void symtable_insert(char* key, hack_addr addr);
void print_table();
 
#endif
