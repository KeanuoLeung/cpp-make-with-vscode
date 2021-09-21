#include <cstdio>
#include <cstdlib>

#include "msg.h"

typedef unsigned char byte;

byte *byte_to_binary(byte n)
{
  byte *output = (byte *)calloc(sizeof(byte), 8);
  unsigned int a = 0b10000000;
  for (int idx = 0; idx < 8; idx++)
  {
    byte curChar = ((n & a) >> (7 - idx)) == 0 ? '0' : '1';
    // printf("%d -- %d >> %c\n", n, n & a, curChar);
    a = a >> 1;
    output[idx] = curChar;
  }
  return output;
}

byte *string_to_binary(byte *n, int length)
{
  byte *result = (byte *)calloc(sizeof(byte), length * 9);
  for (int i = 0; i < length; ++i)
  {
    byte *binary = byte_to_binary(n[i]);
    for (int j = 0; j < 8; ++j)
    {
      int offset = j + i * 9;
      result[offset] = binary[j];
    }
    result[i * 9 - 1] = ' ';
  }
  return result;
}
int main(void)
{
  byte a = 'c';
  // printf("%x\n", 0b00000000 >> 7);
  printf("%s\n", byte_to_binary(a));
  byte *str = (byte *)"abc";
  printf("%s -> %s\n", str, string_to_binary(str, 3));
}