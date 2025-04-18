#include <stdio.h>
// 05.08.2024


int main()
{
   printf("This program counts words and shows the distribution of their lengths.\n");
   printf("Input whatever you want and end with ctrl+Z on Windows or ctrl+D on Linux.\n");
   
   int character;
   int length = 0;
   int lengths[20] = {0};
   
   while ((character = getchar()) != EOF) {
      if ((character <= 'z' && character >= 'a') || (character <= 'Z' && character >= 'A'))
         ++length;
      else {
         ++lengths[length];
         length = 0;
      }
   }
   for (int i = 1; i<20; i++) {
      printf("%d\t", i);
      for (int j = 0; j<lengths[i]; j++)
         printf("|");
      printf("%d\n", lengths[i]);
   }
   
   return 0;
}