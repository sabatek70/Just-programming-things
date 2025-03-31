#include <stdio.h>

int main(int argc, char* argv[])
{
    for(int limit, start, step, code = scanf("%d%d%d", &start, &limit, &step, printf("<start> <end> <step>\n" ));start<=limit; printf("\n", (start%2==0)?printf(" : even", start+=step):printf(" : odd", start+=step))) printf("%d", start);
    return 0;
}

// goes from start to end by step and prints whether the numbers are even or odd
// all only using a bodyless for lol