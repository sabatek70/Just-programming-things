#include <stdio.h>

int main(int argc, char* argv[])
{
    for(int input_start, input_limit, step, last_start, code = scanf("%d%d%d", &input_start, &input_limit, &step, printf("<start> <end> <step>\n")), start = input_start, limit = input_limit, a = printf("", (input_limit-input_start>0&&step<=0)?(start=limit+1):0, (input_limit-input_start<0&&step>=0)?(limit=start+1):0);(input_start<=input_limit)?(last_start = start, start<=limit):(last_start = start, limit<=start); printf("\n", (last_start%2==0)?printf("%d : even", last_start, start+=step):printf("%d : odd", last_start, start+=step)));
    return 0;
}

// goes from start to end by step and prints whether the numbers are even or odd
// all only using a bodyless for
//yes it does go backwards, do negative step
//yes it will stop instead of running towards either one of the infinities if you try to set the step to be directed outwards the scope