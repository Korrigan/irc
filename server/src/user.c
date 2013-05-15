
#include <stdlib.h>
#include <string.h>

#include "llist.h"
#include "umatch.h"
#include "user.h"

int		user_cmp(t_user *a, t_user *b)
{
  return (strcmp(a->name, b->name));
}

int		add_user(t_userlist **l, t_user *u)
{
  return (llist_add((t_llist **)l, (void *)u));
}

int		delete_user(t_userlist **l, t_user *u, t_user_cmp cmp)
{
  return (llist_delete((t_llist **)l, (void *)u, (t_llist_cmp )cmp));
}

t_user		*find_user(t_userlist **l, t_user *u, t_user_cmp cmp)
{
  return (llist_find((t_llist **)l, (void *)u, (t_llist_cmp )cmp));
}
