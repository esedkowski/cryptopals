#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
   unsigned char *data;
   int length;
} byte_array;

byte_array convert_hex_to_byte(char *hex);
char *encode_bytes_into_b64(byte_array b);

#endif
