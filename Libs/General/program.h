#ifndef PROGRAM_H
#define PROGRAM_H
#include<Formatting.h>

void program();
void menu();
void menuPrinter(short, char**);
function_unary* optionChooserUnary(short, function_unary**);
function_binary* optionChooserBinary(short, function_binary**);

#endif