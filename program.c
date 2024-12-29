#include<stdio.h>
#include<stdlib.h>
#include<General/program.h>
#include<Formatting.h>
#include<Recursion/Operations.h>

#define PRINTBREAK printf("\n")

void program(){
    system("chcp 65001");
    printf("%s", header());
    PRINTBREAK;
    menu();
    printf("%s", footer());
    PRINTBREAK;
}

void menu(){
    short menuController = 0;
    char* optionsName[] = {"Addition", "Multiplication"};
    function_binary* functions[] = {Addition, Multiplication}; 
    short numberOfOptions = sizeof(optionsName) / sizeof(optionsName[0]);

    short operandA = 0;
    short operandB = 0;
    do {
        menuPrinter(numberOfOptions, optionsName);
        scanf("%d", &menuController);
        PRINTBREAK;
        if (menuController > 0 && menuController < numberOfOptions + 1){
            printf("Insira o primeiro operando:");
            scanf("%hd", &operandA);
            printf("Insira o segundo operando:");
            scanf("%hd", &operandB);
            printf("%d\n%d\n", operandA, operandB);
            if (operandA != 0 && operandB != 0){
                function_binary* selectedFunction = optionChooserBinary(menuController, functions);
                printf("A resposta é: %d", selectedFunction(operandA, operandB));
            }
        }
        PRINTBREAK;
    } while (menuController != 0);
}

void menuPrinter(short numberOfOptions, char* optionsName[]){ // J'ai seulement fait ça car je suis paresseux
    if (numberOfOptions < 1 || numberOfOptions > 10)
        printf("O número de opções deve estar entre 1 e 10");
    for (short i = 0; i < numberOfOptions; i++){
        printf("%d \b. %s", i+1, optionsName[i]);
        PRINTBREAK;
    }
    printf("0. Sair");
    PRINTBREAK;
}

function_unary* optionChooserUnary(short chosenOption, function_unary* functions[]){
    return functions[chosenOption-1];
}

function_binary* optionChooserBinary(short chosenOption, function_binary* functions[]){
    return functions[chosenOption-1];
}


