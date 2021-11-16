#include "symtable.h"
     
hash_table(char *str){
unsigned long hash = SYMBOL_TABLE_SIZE ;
int value;

    while (value = *str++)
        hash = ((hash << 5) + hash) + value;

    return hash %SYMBOL_TABLE_SIZE;

    void hash_insert(char*key,hack_addr address){
        int *p1 = malloc(sizeof(Symbol));
        int *p1 address =
        } 


    void hash_search(char* key){
        int index = hash(key);
        if (hash_table[index] != NULL &&
            strncmp(hash_table[index]->key, key, SYMBOL_TABLE_SIZE) == 0{
            }else{
                return NULL;
            }
        }
    void print_table(){
        for(int i=0;i< SYMBOL_TABLE_SIZE;i++){
            if hash_table[i]==NULL){
                printf("\t%i\t---\n",i);
            }else{
                printf("\t%i\t ",i);
                key *tmp != hash_table[i];
                while(tmp != Null) {
                    printf("%s - ", hash_table[i]->key);
                    tmp=tmp-> next
                }
            }
        }
    }
}