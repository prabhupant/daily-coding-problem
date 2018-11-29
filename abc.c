#include<stdio.h>
#include<stdlib.h>

struct myStructure
{
    int a;
    int b;
};

void modifyMe1(struct myStructure* param1)
{
    param1->a = 7;
}

void modifyMe2(struct myStructure** param1)
{
    (*param1)->a = 7;
}

int main(int argc, char* argv[])
{
    struct myStructure* test1;

    test1 = malloc(sizeof(test1));
    test1->a =5;
    test1->b = 6;

    modifyMe1(test);

    printf("a: %d, b: %d\n", test1->a, test1->b);

    test1->a = 5;
    
    modifyMe2(&test1);

    printf("a: %d, b: %d\n", test1->a, test1->b);

    free(test1);
    return 0;
}
