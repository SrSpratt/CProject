#include<Recursion/Operations.h>

int Addition(int augend, int addend){
    if (addend == 0)
        return augend;
    else
        return 1 + Addition(augend, --addend);
}