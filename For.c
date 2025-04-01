#include <stdio.h>

int main(int argc, char** argv)
{
    for(struct{int a; char b;}var = {1, 'a'}; var.a < 5; var.a++, var.b++)
    {
        printf("%d:%c\n", var.a, var.b);
    }
    return 0;
}