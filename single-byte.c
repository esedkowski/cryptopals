#include <stdio.h> 
#include <stdlib.h>

#include "functions.h"
#include "constants.h"

int main(int argc, char *argv[]) {

   if (argc < 2) {
      printf("No arguments...\n");
      return 0;
   }
   
   char *hex = argv[1]; // take command line argument as variable

   byte_array b = convert_hex_to_byte(hex);

   decoded result;

   for (char key = '0'; key <='~'; key++) {
      result = decode_using_key(b, key);
      if (result.score <= 0.9) {
         printf("%c %f \n", result.key, result.score);
         printf("%s\n", result.answer);
      }
      free(result.answer);
   }

   free(b.data);
   
   return 0;
}
