
#include <string.h>
#include <stdlib.h>

#include "message.h"

static const t_cmd_converter	converter[] =
  {
    {USER, "USER"},
    {NICK, "NICK"},
    {PASS, "PASS"}
  };

int		parse_command(t_message *msg, char **str)
{
  unsigned	i;
  unsigned	len;

  i = 0;
  while (i < (sizeof(converter) / sizeof(*converter)))
    {
      len = strlen(converter[i].string);
      if (!strncmp(*str, converter[i].string, len))
	{
	  msg->command = converter[i].cmd;
	  *str += len;
	  if (**str == ' ')
	    (*str)++;
	  return (0);
	}
      i++;
    }
  return (1);
}
