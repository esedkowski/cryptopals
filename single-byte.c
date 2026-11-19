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

   char true_key = 'X';

   char *answer;
   char letter;

   char table[26];

   for (char key = '0'; key <='~'; key++) {
      answer = malloc(b.length);
      for (int i=0; i<26; i++) {
         table[i] = 0;
      }
      for (int i = 0; i < b.length; i++) {
         letter = b.data[i] ^ key;
         answer[i] = letter;

         if ((64 < letter && letter < 91) || (96 < letter && letter < 123)) {
            if (letter < 91) {
               letter -= 65;
            }
            else {
               letter -= 97;
            }
            table[letter] += 1;
         }
      }
      if (key == true_key) {
         printf("%s\n", answer);
         for (char l='A'; l <= 'Z'; l++) {
            printf("%c : %d\n", l, table[l-65]);
         }
      }
      // printf("%c: %s\n", key, answer);
      free(answer);
   }
   
   return 0;
}
