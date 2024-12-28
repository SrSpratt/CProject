#include<stdio.h>
#include<module.h>

#define PRINTBREAK printf("\n")

void program(){
    const char* moduleReturn = module(); 
    printf("Iniciando o programa...");
    PRINTBREAK;
    printf(moduleReturn);
    PRINTBREAK;
}