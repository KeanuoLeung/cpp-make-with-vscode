#include <cstdio>

#include "msg.h"

int main(void)
{
  const char *msg = get_hello_message();
  printf("This is a message from get_hello_message(): %s\n", msg);
}