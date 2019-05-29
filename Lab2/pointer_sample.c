#include <stdio.h>
int main()
{
    int var = 20;
    int *ip;
    ip = &var;

    printf("Address of var variable is %x\n", &var);


    printf("Address stored in ip variable is %x\n", ip);
    printf("Value of *ip is %d\n", *ip);

    return 0;
}