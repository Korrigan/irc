
#include <string.h>
#include <stdlib.h>

#include "message.h"

int		parse_command(t_message *msg, char **str)
{
  unsigned	i;
  unsigned	len;

  i = 0;
  while (i < (sizeof(cmd_converter) / sizeof(*cmd_converter)))
    {
      len = strlen(cmd_converter[i].string);
      if (!strncmp(*str, cmd_converter[i].string, len))
	{
	  msg->command = cmd_converter[i].cmd;
	  *str += len;
	  if (**str == ' ')
	    (*str)++;
	  return (0);
	}
      i++;
    }
  return (1);
}
