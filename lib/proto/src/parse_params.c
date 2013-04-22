
#include <string.h>
#include <stdlib.h>

#include "message.h"

static inline int param_valid(char c)
{
  if (strchr(INVALID_MIDDLE, c) || c == ':' || !c)
    return (0);
  return (1);
}

static	int strcount(char *str, char c)
{
  char	*s;
  int	i;

  s = str;
  i = 0;
  while ((s = strchr((s ? s : str), c)))
    {
      s++;
      i++;
    }
  return (i);
}

static	char *parse_param(char **str)
{
  char	*s;
  char	*ret;

  s = *str;
  if (!*s)
    return (NULL);
  while (param_valid(*s))
    s++;
  if (*s != ' ' && *s)
    return (NULL);
  if (*s == ' ')
    s++;
  if (!(ret = strndup(*str, s - *str)))
    return (NULL);
  *str = s;
  return (ret);
}

static	char *parse_last_param(char **str)
{
  char	*s;
  char	*ret;

  s = *str;
  if (!*s)
    return (NULL);
  if (*s != ':')
    return (NULL);
  (*str)++;
  s++;
  while (param_valid(*s) || *s == ' ')
    s++;
  if (*s)
    return (NULL);
  if (!(ret = strndup(*str, s - *str)))
    return (NULL);
  *str = s;
  return (ret);
}

int	parse_params(t_message *msg, char **str)
{
  char	*s;
  char	**p;
  int	n;
  int	i;

  n = strcount(*str, ' ') + 1;
  if (!(p = malloc(n + 1)))
    return (1);
  i = 0;
  while ((s = parse_param(str)))
    {
      p[i++] = s;
    }
  if ((s = parse_last_param(str)))
    p[i++] = s;
  p[i] = NULL;
  if (**str)
    {
      free(p);
      return (1);
    }
  msg->params = p;
  return (0);
}
