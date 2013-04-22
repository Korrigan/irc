#include <stdio.h>
#include <stdlib.h>

#include "message.h"

int main(int ac, char **av)
{
  t_message msg;
  int ok;
  char **p;

  msg.prefix = NULL;
  msg.command = 0;
  msg.params = NULL;
  if (ac == 2)
    ok = parse_message(&msg, av[1]);
  printf("-- Parsing %s --\n", (!ok ? "OK" : "KO"));
  printf("prefix: %s\n", msg.prefix);
  printf("command: %d\n", msg.command);
  printf("params:\n");
  for (p = msg.params; *p; p++)
    printf("\t%s\n", *p);
  return (0);
}
