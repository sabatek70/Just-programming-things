
#include <stdio.h>

int main(int argc, char* argv[])
{
    for(int input_start, input_limit, step, code = scanf("%d%d%d", &input_start, &input_limit, &step, printf("<start> <end> <step>\n" )), start = input_start, limit = input_limit;(input_start<=input_limit)?(start<=limit):(limit<=start); printf("\n", (start%2==0)?printf(" : even", start+=step):printf(" : odd", start+=step))) printf("%d", start);
    return 0;
}

// goes from start to end by step and prints whether the numbers are even or odd
// all only using a bodyless for
//yes it does go backwards, do negative step