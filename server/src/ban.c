
#include <stdlib.h>

#include "llist.h"
#include "umatch.h"
#include "mode.h"

t_ban		*new_ban(char *u, char *h, char *c)
{
  t_ban		*b;

  if (!(b = malloc(sizeof(*b))))
    return (NULL);
  b->match.user = u;
  b->match.host = h;
  b->comment = c;
  return (b);
}

int		ban_cmp(t_ban *a, t_ban *b)
{
  return (match_cmp(&a->match, &b->match));
}

int		add_ban(t_banlist **l, t_ban *m)
{
  return (llist_add((t_llist **)l, (void *)m));
}

int		delete_ban(t_banlist **l, t_ban *m, t_ban_cmp cmp)
{
  return (llist_delete((t_llist **)l, (void *)m, (t_llist_cmp)cmp));
}

t_ban	*find_ban(t_banlist **l, t_ban *m, t_ban_cmp cmp)
{
  return ((t_ban *)llist_find((t_llist **)l, (void *)m, (t_llist_cmp)cmp));
}
