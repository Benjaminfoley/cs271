#include "symtable.h"
#include <stdio.h>

struct Symbol* hashArray[SYMBOL_TABLE_SIZE]= {NULL};
struct Symbol*item;

unsigned int hash(char str*){
    unsigned int hash = 5381;
    int i;
    while((c = *key++)){
        hash = ((hash<<5)+ hash)+i;
    }
    return hash% SYMBOL_TABLE_SIZE
}


void symtable_insert(char*key,hack_addr address){
        struct Symbol *item = (struct Symbol*) malloc(sizeof(struct Symbol)):
        item->address = addr;
        item-> name= (char*)malloc(strlen(key)+1);
        strcpy(item->name, key);
        int hashIndex = hash(key);
        while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL){
            hashIndex++
            hashIndex %= SYMBOL_TABLE_SIZE;
        }
        hashArray[hashIndex]=item
    } 


struct Symbol *symtable_search(char* key){
        int index = hash(key);

        while(hashArray[index] != NULL){
            if(hashArray[index]-> name == key){
                return hashArray[index];
            }
            index++
            index %= SYMBOL_TABLE_SIZE;
        }
        return NULL;
} 
    void print_table(){
        for(int i=0;i< SYMBOL_TABLE_SIZE;i++){
            if hash_table[i]!=NULL){
                printf("(%s,%d)",hashArray[i]->name, hashArray[i]->address);
            }else{
                printf(" ~~ ");
            }
            
        }
        printf("/n");
    }
