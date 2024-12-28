#include<stdio.h>
#include<stdlib.h>
#include<General/module.h>
#include<Recursion/Factorial.h>

#define PRINTBREAK printf("\n")

void program(){
    system("chcp 65001");
    const char* moduleReturn = module(); 
    printf("Iniciando o programa...");
    PRINTBREAK;
    printf(moduleReturn);
    PRINTBREAK;
    printf("Digite um número:");
    PRINTBREAK;
    int number = 0;
    scanf("%d", &number);
    printf("The result is %lu", Factorial(number));
}