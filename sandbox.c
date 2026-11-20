#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) {

   char test1[2] = {'1', '2'};
   char *test2 = malloc(2);
   test2[0] = 'A';
   test2[1] = 'B';

   printf("%c\n", test1[0]);
   test1[0] = '=';
   printf("%c\n", test1[0]);
   test1[0] = test2[0];
   printf("%c\n", test1[0]);
   test2[0] = '-';
   printf("%c\n", test1[0]);


   return 0;
}
