
#include <string.h>
#include <stdlib.h>

#include "message.h"

static inline int prefix_valid(char c)
{
  if (strchr(VALID_SPECIAL, c)
      || (c <= 'z' && c >= 'a')
      || (c <= 'Z' && c >= 'A')
      || (c <= '9' && c >= '0'))
    return (1);
  return (0);
}

int	parse_prefix(t_message *msg, char **str)
{
  char	*s;

  s = *str;
  if (*s != ':')
    return (0);
  (*str)++;
  s++;
  while (prefix_valid(*s))
    s++;
  if (*s != ' ')
    return 1;
  msg->prefix = strndup(*str, s - *str);
  *str = s + 1;
  return 0;
}
