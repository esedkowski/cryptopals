#include <stdio.h> 
#include <stdlib.h>

#include "functions.h"
#include "constants.h"

int main(int argc, char *argv[]) {

   if (argc < 2) {
      printf("No arguments...\n");
      return 0;
   }
   
   char *file_name = argv[1]; // take command line argument as variable

   FILE *fp = fopen(file_name, "r");
   char buffer[100];
   char *line = buffer;
   if (fp == NULL) {
      printf("Unable to open file.");
      return 1;
    }
   
   decoded result;
   byte_array key;
   key.data = malloc(1);
   key.length = 1;
   byte_array b;
   
   while(fgets(buffer, sizeof(buffer), fp)) {
      b = convert_hex_to_byte(line);

      for (char k = '0'; k <='~'; k++) {
         key.data[0] = k;
         result = decode_using_key(b, key);
         if (result.score <= 0.8) {
            printf("%c %f \n", result.key[0], result.score);
            printf("%s\n", result.answer);
         }
         free(result.answer);
      }
      free(b.data);
   }
      

   fclose(fp);
   
   free(key.data);
   
   return 0;
}
