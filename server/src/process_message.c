
#include <stdlib.h>
#include <string.h>

#include "irc.h"
#include "proto.h"

static const t_command_caller	caller[CMD_CALLER_SIZE] =
  {
    {OPER, &oper},
    {USER, &user},
    {NICK, &nick}
  };

t_message	*process_message(t_irc *irc, t_user *from, const t_message *msg)
{
  unsigned	i;

  i = 0;
  while (i < CMD_CALLER_SIZE)
    if (caller[i].cmd == msg->command)
      return caller[i].f(irc, from, msg);
  return (NULL);
}
