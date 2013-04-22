
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "message.h"

static char	*concat_params(char **params)
{
  int		i;
  int		n;
  int		len;
  char		*str;
  char		*tmp;

  if (!params || !*params)
    return (NULL);
  n = 0;
  len = 0;
  while (params[n])
    len += 1 + strlen(params[n++]);
  if (!(str = malloc(len + 2)))
    return (NULL);
  n = 0;
  i = 0;
  while (params[n])
    {
      str[i++] = ' ';
      tmp = params[n];
      if (!params[n + 1] && strchr(params[n], ' '))
	str[i++] = ':';
      while (*tmp)
	str[i++] = *tmp++;
      n++;
    }
  str[i] = 0;
  return (str);
}

char		*get_string_from_message(const t_message *msg)
{
  char		*str;
  char		*params;
  int		ok;
  const char	*command = command_to_string(msg->command);

  if (!command || !(params = concat_params(msg->params)))
    return (NULL);
  if (msg->prefix)
    ok = asprintf(&str, ":%s %s%s\r\n",
		  msg->prefix, command, (params ? params : ""));
  else
    ok = asprintf(&str, "%s%s\r\n",
		  command, (params ? params : ""));
  free(params);
  if (ok == -1)
    return (NULL);
  return (str);
}
