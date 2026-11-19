#include <stdio.h> 
#include <stdlib.h>

#include "functions.h"
#include "constants.h"

int main(int argc, char *argv[]) {

   char *test = "TEST123";
   char *test1 = test;

   test[0] = 'A';

   printf("%s %s", test, test1);
   return 0;
}
