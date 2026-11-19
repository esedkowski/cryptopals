#include <stdio.h> 

#include "functions.h"

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("too litle arguments\n");
      return 0;
   }
   char *hex1 = argv[1]; // take command line argument as variable
   char *hex2 = argv[2]; // take command line argument as variable

   byte_array b1 = convert_hex_to_byte(hex1);
   byte_array b2 = convert_hex_to_byte(hex2);

   for (int i = 0; i < b1.length ; i++) {
      printf("%02x", b1.data[i] ^ b2.data[i]);
   }
   printf("\n");
}
