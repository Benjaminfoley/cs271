#define MAX_LIMIT 100
#include<stdio.h>
#include<string.h>

int main(void) {
char hello[5] = "Hello";
// declare an empty string
char name[MAX_LIMIT];
char welcome[MAX_LIMIT];
char str1[4] =" ";

// prompt user
printf("What is your name? ");

// read in a string from user and save in variable
// [^\n] means to discard the newline character
scanf("%[^\n]s", name);
int n = strlen(name);

// print out "hello <name>"
printf("%s %s!\n\n", hello, name);

strcpy(welcome, hello);
strcat(welcome,str1);
strcat(welcome,name);
printf("%s\n",welcome);

 printf("Your name is %i charcters long\n", n);

char prof[8] = {'P','a','t','r','i','c','k','\0'};
int compare = strcmp (name,prof);
if (compare<0){
  printf("%s is before %s \n", name,prof);}
  else if(compare>0){
    printf("%s is after %s", name,prof);}
    else{
      printf("%s is %s", name, prof );}
}