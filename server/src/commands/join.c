
#include <string.h>
#include <stdlib.h>
#include "irc.h"
#include "user.h"
#include "proto.h"


static int	check_params(t_user *user, const t_message *msg)
{
  if (!msg->params || !msg->params[0])
    {
      push_message_to_user(user, new_message(ERR_NEEDMOREPARAMS, NULL, 2,
					     strdup("JOIN"),
					     strdup("Not enough parameters")));
      return (1);
    }
  return (0);
}

static int	check_chan_name(t_user *user, char *chan)
{
  if (*chan != '#' && *chan != '&')
    {
      push_message_to_user(user, new_message(ERR_NOSUCHCHANNEL, NULL, 2,
					     strdup(chan),
					     strdup("No such channel")));
      return (1);
    }
  return (0);
}


static int	join_channel(t_channel *chan, t_user *user)
{
  t_ban		*ban;
  t_ban		cmp;
  t_usermode	*mode;

  cmp.match.user = user->name;
  cmp.match.host = user->host;
  if ((ban = find_ban(&chan->banlist, &cmp, &ban_cmp)))
    {
      push_message_to_user(user, new_message(ERR_BANNEDFROMCHAN, NULL, 2,
					     strdup(chan->name),
					     strdup("Cannot join channel (+b)")));
      return (1);
    }
  if (!(mode = malloc(sizeof(*mode))))
    return (1);
  mode->user = user;
  mode->mode = 0;
  add_usermode(&chan->users, mode);
  push_message_to_user(user, new_message(RPL_TOPIC, NULL, 2,
					 strdup(chan->name),
					 (chan->topic ? strdup(chan->topic) : "")));
  push_message_to_chan(chan, new_message(JOIN, user->name, 1, chan->name));
  return (0);
}

static int	create_channel(t_irc *irc, t_user *user, char *name)
{
  t_channel	*chan;

  if (!(chan = new_channel(name))
      || !(mode = malloc(sizeof(*mode))))
    return (1);
  mode->user = user;
  mode->mode = MODE_O;
  add_usermode(&chan->users, mode);
  push_message_to_user(user, new_message(RPL_TOPIC, NULL, 2,
					 strdup(chan->name),
					 (chan->topic ? strdup(chan->topic) : "")));
  if (add_channel(&irc->channels, chan))
    {
      free(mode);
      free_channel(chan);
      return (1);
    }
  return (0);
}

int		join(t_irc *irc, t_user *from, const t_message *msg)
{
  t_channel	*chan;
  t_channel	cmp;

  if (check_params(from, msg)
      || check_chan_name(from, msg->params[0]))
    return (1);
  cmp.name = msg->params[0];
  if ((chan = find_channel(&irc->channels, &cmp, &channel_cmp)))
    return (join_channel(chan, from));
  return (create_channel(irc, from, msg->params[0]));
}
