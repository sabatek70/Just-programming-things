#include <stdio.h>
#define MAX_LENGTH 20

// 05.08.2024

int max(int[]);

int main()
{   
   printf("This program counts words and shows the distribution of their lengths.\n");
   printf("Input whatever you want and end with ctrl+Z on Windows or ctrl+D on Linux.\n");
   
   int character, length = 0;
   int lengths[MAX_LENGTH] = {0};
   
   while ((character = getchar()) != EOF)
   {  
      if (  (character <= 'z' && character >= 'a')
         || (character <= 'Z' && character >= 'A'))
         length++;
      else {
         lengths[length]++;
         length = 0;
      }
   }
   
   for (int columnHeight = max(lengths)+1; columnHeight > 0; --columnHeight) //+1 to include the additional number
   {
      for (int i = 1; i < MAX_LENGTH; ++i)                                 //labels above the columns
      {
         if (lengths[i] == columnHeight-1)                               //-1 to print one above the column
            printf("%2d ", lengths[i]);
         else
         if (lengths[i] >= columnHeight) 
            printf("|x|");
         else printf("   ");    
      }
      printf("\n");
   }
   
   for (int i = 1; i < MAX_LENGTH; ++i)
      printf("---");
   
   printf("\n");
   
   for (int i = 1; i < MAX_LENGTH; ++i)
      printf("%2d ", i);
   
   return 0;
}

int max(int lengths[])
{
   int current_value = 0;
   
   for (int i = 1; i < MAX_LENGTH; ++i) 
   if (lengths[i] > current_value)
      current_value = lengths[i];
   
   return current_value;
}