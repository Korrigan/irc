#include <stdlib.h>
#include <string.h>

#include "llist.h"
#include "umatch.h"
#include "user.h"

int		usermode_cmp(t_usermode *a, t_usermode *b)
{
  return (user_cmp(a->user, b->user));
}

int		add_usermode(t_usermodelist **l, t_usermode *u)
{
  return (llist_add((t_llist **)l, (void *)u));
}

int		delete_usermode(t_usermodelist **l, t_usermode *u, t_usermode_cmp cmp)
{
  return (llist_delete((t_llist **)l, (void *)u, (t_llist_cmp )cmp));
}

t_usermode	*find_usermode(t_usermodelist **l, t_usermode *u, t_usermode_cmp cmp)
{
  return (llist_find((t_llist **)l, (void *)u, (t_llist_cmp )cmp));
}
