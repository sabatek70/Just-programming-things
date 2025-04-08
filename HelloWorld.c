#include <stdio.h>

struct {
   struct {
      int (*printf)(const char* restrict, ...);
   } out;
} System = {&printf};

int main()
{
   System.out.printf("Hello, World! My favourite number is: %d.\n", 4);

   return 0;
}