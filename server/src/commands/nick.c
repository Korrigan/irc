
#include <stdlib.h>
#include <string.h>
#include "irc.h"
#include "proto.h"
#include "user.h"

static int	check_params(t_user *user, const t_message *msg)
{
  if (!msg->params || !msg->params[0])
    {
      push_message_to_user(user, new_message(ERR_NONICKNAMEGIVEN, NULL, 1,
					     strdup("No nickname given")));
      return (1);
    }
  return (0);
}

static int	check_nick(t_irc *irc, t_user *user, char *name)
{
  t_user	cmp;

  cmp.name = name;
  if (find_user(&irc->users, &cmp, &user_cmp))
    {
      push_message_to_user(user, new_message(ERR_NICKNAMEINUSE, NULL, 2,
					     strdup(msg->params[0]),
					     strdup("Nickname is already in use")));
      return (1);
    }
  return (0);
}

int		nick(t_irc *irc, t_user *from, const t_message *msg)
{
  if (check_params(user, msg)
      || check_nick(irc, user, msg->params[0]))
    return (1);
  free(from->name);
  from->name = strdup(msg->params[0]);
  return (0);
}
