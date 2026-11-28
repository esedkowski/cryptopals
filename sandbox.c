#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main(int argc, char *argv[]) {

   char *test1 = "this is a test";
   char *test2 = "wokka wokka!!!";

   int hamming_distance = count_hamming_distance(test1, test2);
   if (hamming_distance == -1) {
      return 1;
   }

   printf("%d", hamming_distance);



   return 0;
}
