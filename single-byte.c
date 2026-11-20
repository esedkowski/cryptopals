#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

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
   int counter;
   float score1;
   float score2;
   float new_score1;
   float new_score2;

   for (char key = '0'; key <='~'; key++) {
      counter = 0;
      score1 = 0;
      score2 = 0;
      answer = malloc(b.length);
      for (int i=0; i<26; i++) {
         table[i] = 0;
      }
      for (int i = 0; i < b.length; i++) {
         letter = b.data[i] ^ key;
         answer[i] = letter;

         if (letter < 32 || letter > 126) {
            break;
         }

         if ((64 < letter && letter < 91) || (96 < letter && letter < 123)) {
            if (letter < 91) {
               letter -= 65;
            }
            else {
               letter -= 97;
            }
            table[letter] += 1;
            counter++;
         }
      }
      
      for (int j = 0; j < 26; j ++) {
         // printf("%d %d %f\n", table[j], counter, table[j] / counter);
         new_score1 = pow(((float)table[j] / counter) - LETTERS_FREQ[j], 2);
         // printf("%f\n", new_score);
         score1 += new_score1;

         new_score2 = ((float)table[j] / counter) - LETTERS_FREQ[j];
         if (new_score2 > 0) {
            score2 += new_score2;
         }
         else {
            score2 -= new_score2;
         }

         
      }
      if (score1 <= 0.3 && score2 <= 0.9) {
         printf("%s\n", answer);
         printf("%c %f %f\n", key, score1, score2);
      }
      free(answer);
   }
   
   return 0;
}
