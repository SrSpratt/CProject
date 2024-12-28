#include<stdio.h>
#include<stdlib.h>
#include<General/program.h>
#include<Formatting.h>
#include<Recursion/Factorial.h>

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
    char* optionsName[] = {"Factorial", "Factorial"};
    function_t functions[] = {Factorial, Factorial}; 
    short numberOfOptions = sizeof(optionsName) / sizeof(optionsName[0]);
    do {
        printf("%d", numberOfOptions);
        PRINTBREAK;
        menuPrinter(numberOfOptions, optionsName);
        scanf("%d", &menuController);
        PRINTBREAK;
        if (menuController > 0 && menuController < numberOfOptions + 1){
            function_t selectedFunction = optionChooser(menuController, functions);
            printf("A resposta é: %d", selectedFunction(1));
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
}

function_t optionChooser(short chosenOption, function_t functions[]){
    return functions[chosenOption-1];
}
