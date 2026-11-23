#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "constants.h"

int main(int argc, char *argv[]) {

   if (argc < 2) {
      printf("No arguments...\n");
      return 0;
   }
   
   char *input = argv[1]; // take command line argument as variable
   // printf("%s", input);

   char *key = "ICE";
   
   unsigned char *output = malloc(200);

   int k;

   for (int i = 0; i < strlen(input); i++) {
      k = i % strlen(key);
      output[i] = input[i] ^ key[k];
   }

   for (int i = 0; output[i] != '\0'; i++) {
      printf("%02x", output[i]);
   }
   
   return 0;
}
