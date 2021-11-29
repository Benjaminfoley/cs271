#include<stdint.h>
#include <stdio.h>   
#include <stdlib.h> 
#include<stdbool.h>
#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__
#define SYMBOL_TABLE_SIZE  100
typedef int16_t hack_addr;
struct Symbol *symtable_find(char * key);
void symtable_insert(char* key, hack_addr addr);
void symtable_display_table();

typedef struct {
    hack_addr address;
    char* name;
}Symbol;

Symbol* hashArray[SYMBOL_TABLE_SIZE];
int hash(char *str);
struct Symbol *find(char * key);
void insert(char* key, hack_addr addr);
void display_table(); 
#endif