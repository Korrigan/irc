
#include <string.h>
#include "proto.h"
#include "mode.h"
#include "user.h"
#include "irc.h"
#include "umatch.h"


static int	check_params(t_user *user, const t_message *msg)
{
  if (!msg->params || !msg->params[0] || !msg->params[1])
    {
      push_message_to_user(user, new_message(ERR_NEEDMOREPARAMS, NULL, 2,
					     strdup("OPER"),
					     strdup("Not enough parameters")));
      return (1);
    }
  return (0);
}		

static int	check_oline(t_irc *irc, t_user *user, char *name, char *password)
{
  t_oper	op;
  t_oper	*oline;

  op.match.user = name;
  op.match.host = user->host;
  op.password = password;
  if (!(oline = find_oper(&irc->olines, &op, &oper_cmp)))
    {
      push_message_to_user(user, new_message(ERR_NOOPERHOST, NULL, 1,
					     strdup("No O-lines for your host")));
      return (1);
    }
  else if (strcmp(password, oline->password))
    {
      push_message_to_user(user, new_message(ERR_PASSWDMISMATCH, NULL, 1,
					     strdup("Password incorrect")));
      return (1);
    }
  return (0);
}

int		oper(t_irc *irc, t_user *user, const t_message *msg)
{
  if (check_params(user, msg)
      || check_oline(irc, user, msg->params[0], msg->params[1]))
    return (1);
  MODE_SET(user->mode, MODE_O);
  push_message_to_user(user, new_message(RPL_YOUREOPER, NULL, 1,
					 strdup("You are now an IRC operator")));
  return (0);
}
