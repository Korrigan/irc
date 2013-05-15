
#include <stdarg.h>
#include <stdlib.h>

#include "message.h"

t_message	*new_message(t_command cmd, char *prefix, int np, ...)
{
  t_message	*msg;
  va_list	ap;
  int		i;

  if (!(msg = malloc(sizeof(*msg)))
      || !(msg->params = malloc(sizeof(*(msg->params)) * (np + 1))))
    return (NULL);
  msg->command = cmd;
  msg->prefix = prefix;
  va_start(ap, np);
  i = 0;
  while (i < np)
    msg->params[i++] = va_arg(ap, char *);
  msg->params[i] = NULL;
  va_end(ap);
  return (msg);
}
