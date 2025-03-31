#include <stdio.h>

struct{
    struct{
      int (*println)(const char* restrict, ...);  
    } out;
} System;

int main()
{
    System.out.println = &printf;

    System.out.println("Hello World?");

    return 0;
}