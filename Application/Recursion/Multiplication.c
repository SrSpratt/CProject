#include<Recursion/Operations.h>

int Multiplication(int multiplicand, int multiplier){
    if (multiplier == 1)
        return multiplicand;
    return multiplicand + Multiplication(multiplicand, --multiplier);
}

