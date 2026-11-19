#include <stdio.h> 
#include <string.h>

#include "functions.h"

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("No arguments...\n");
      return 0;
   }
   
   char *hex = argv[1]; // take command line argument as variable

   byte_array b = convert_hex_to_byte(hex);

   unsigned char *output = encode_bytes_into_b64(b);

   printf("%s\n", output);
   return 0;
}


