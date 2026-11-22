#include <stdio.h> 
#include <string.h>
#include <openssl/evp.h>

#include "functions.h"
#include "constants.h"

byte_array convert_hex_to_byte(char *hex) {
   // number of characters in string and number of bytes (two characters form one byte (8 bits)
   int number_of_chars = strlen(hex);
   int number_of_bytes = number_of_chars/2;

   byte_array b;
   b.data = malloc(number_of_bytes);
   b.length = number_of_chars/2;

   // convert string (two charactes at the time) into bytes
   for (int i = 0; i < b.length; i++) {
      sscanf(&hex[2 * i], "%2hhx", &b.data[i]);
   }

   return b;
}

char *encode_bytes_into_b64(byte_array b) {
   int output_len = 4 * ((b.length + 2) / 3); //counting encoded string length based on input length
   
   // encode bytes into base64
   unsigned char *output = malloc(output_len);
   int len = EVP_EncodeBlock(output , b.data, b.length); // (output, input, number of bytes) returns length of the ouput

   output[len] = '\0'; // add string end... at the end

   return output;
}

decoded decode_using_key(byte_array b, char key) {
   char *answer = malloc(b.length + 1);
   char letter;
   int counter = 0;
   char table[26] = {0};
   float score = 0;
   float new_score;

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
      new_score = ((float)table[j] / counter) - LETTERS_FREQ[j];
      if (new_score > 0) {
         score += new_score;
      }
      else {
         score -= new_score;
      }
   }
   
   decoded result;
   answer[b.length] = '\0';
   result.answer = answer;
   result.key = key;
   result.score = score;

   return result;
}

