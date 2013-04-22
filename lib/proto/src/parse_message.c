
#include <string.h>
#include <stdlib.h>

#include "message.h"

static int	parse_crlf(char **str)
{
  int		len;
  char		*s;

  return (0);
  s = *str;
  len = strlen(s);
  if (len && s[len - 1] != '\n')
    return (1);
  s[len - 1] = 0;
  if (len > 1 && s[len - 2 ] == '\r')
    s[len - 2] = 0;
  return (0);
}

int	parse_message(t_message *ret, const char *msg)
{
  char	*begin;
  char	*str;

  if (!ret || !(str = strdup(msg)))
    return (1);
  begin = str;
  if (parse_crlf(&str) ||
      parse_prefix(ret, &str) ||
      parse_command(ret, &str) ||
      parse_params(ret, &str))
    {
      free(begin);
      return (1);
    }
  free(begin);
  return (0);
}
