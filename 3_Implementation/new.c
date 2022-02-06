/**
 * @file new.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-03
 *
 * @copyright Copyright (c) 2022
 *
 */

//#include "stdio.h" // used to create user header files
#include <stdio.h>

struct complexNo()
{
    int real;
    int img;
};

int main()
{
    int n1, n2;
    printf("enter 2 no.s");
    scanf("%d %d", &n11, &n12);

    struct complexNo cn1 = {n11, n12};

    int n1, n2;
    printf("enter 2 no.s");
    scanf("%d %d", &n21, &n22);

    struct complexNo cn2 = {n21, n22};

    printf("sum = %d+i %d", cn1.real + cn2.real, cn1.img + c2.img);

    return 0;
}