
#include <stdlib.h>
#include <string.h>
#include "irc.h"
#include "proto.h"
#include "user.h"

int	check_params(t_user *user, const t_message *msg)
{
  if (!msg->params
      || !msg->params[0]
      || !msg->params[1]
      || !msg->params[2]
      || !msg->params[3])
    {
      push_message_to_user(user, new_message(ERR_NEEDMOREPARAMS, NULL, 2,
					     strdup("USER"),
					     strdup("Not enough parameters")));
      return (1);
    }
  return (0);
}

static int	check_register(t_user *user)
{
  if (user->realname)
    {
      push_message_to_user(user, new_message(ERR_ALREADYREGISTRED, NULL, 1,
					     strdup("You may not reregister")));
      return (1);
    }
  return (0);
}

int	user(t_irc *irc, t_user *from, const t_message *msg)
{
  (void)irc;
  if (check_params(from, msg)
      || check_register(from))
    return (1);
  from->realname = strdup(msg->params[3]);
  return (0);
}
