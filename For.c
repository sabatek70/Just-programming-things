#include <stdio.h>

//You totally can initialize different typed variables in a for loop

int main(int argc, char** argv)
{
	for(
	struct{int a; char b;}var = {1, 'a'};
	var.a < 5;
	var.a++, var.b++)
	{
		printf("%d:%c\n", var.a, var.b);
	}
	return 0;
}


//the other way of achieving similar scope is a code block:

int main(int argc, char** argv)
{
	{
		int a = 1;
		char b = 'a';
		for(; a < 5; a++, b++)
		{
			printf("%d:%c\n", a, b);
		}
	}
	return 0;
}
