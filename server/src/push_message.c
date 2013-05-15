
#include <stdlib.h>

#include "buffer.h"
#include "user.h"
#include "channel.h"
#include "proto.h"

int	push_message_to_user(t_user *user, t_message *msg)
{
  char	*str;
  int	ret;

  if (!(str = get_string_from_message(msg)))
    return (1);
  ret = buffer_append(&user->obuf, str);
  free(str);
  free(msg->params);
  free(msg->prefix);
  free(msg);
  return (ret);
}

int	push_message_to_chan(t_channel *chan, t_message *msg)
{
  char	*str;
  int	ret;

  if (!(str = get_string_from_message(msg)))
    return (1);
  ret = buffer_append(&chan->obuf, str);
  free(str);
  free(msg->params);
  free(msg->prefix);
  free(msg);
  return (ret);
}
