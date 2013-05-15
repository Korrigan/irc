
#include <stdlib.h>
#include <string.h>

#include "llist.h"
#include "umatch.h"
#include "channel.h"

t_channel	*new_channel(char *name)
{
  t_channel	*chan;

  if (!(chan = malloc(sizeof(*chan)))
      || !(chan->name = strdup(name)))
    return (NULL);
  chan->topic = NULL;
  chan->password = NULL;
  chan->limit = 0;
  chan->mode = 0;
  chan->users = NULL;
  chan->banlist = NULL;
  chan->buffer.size = 0;
  chan->buffer.list = NULL;
  return (chan);
}
  
int		channel_cmp(t_channel *a, t_channel *b)
{
  return (strcmp(a->name, b->name));
}

int		add_channel(t_chanlist **l, t_channel *c)
{
  return (llist_add((t_llist **)l, (void *)c));
}

int		delete_channel(t_chanlist **l, t_channel *c, t_channel_cmp cmp)
{
  return (llist_delete((t_llist **)l, (void *)c, (t_llist_cmp )cmp));
}

t_channel	*find_channel(t_chanlist **l, t_channel *c, t_channel_cmp cmp)
{
  return (llist_find((t_llist **)l, (void *)c, (t_llist_cmp )cmp));
}
