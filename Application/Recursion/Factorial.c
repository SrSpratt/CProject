#include<Recursion/Factorial.h>

long unsigned Factorial(int n){
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return(n * Factorial(n-1));
}