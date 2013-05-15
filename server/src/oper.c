
#include <stdlib.h>
#include <string.h>

#include "llist.h"
#include "umatch.h"
#include "mode.h"

t_oper		*new_oper(char *u, char *h, char *p)
{
  t_oper	*o;

  if (!(o = malloc(sizeof(*o))))
    return (NULL);
  o->match.user = u;
  o->match.host = h;
  o->password = p;
  return (o);
}

int oper_cmp(t_oper *a, t_oper *b)
{
  if (!match_cmp(&a->match, &b->match)
      && ((!a->password && !b->password)
	  || (a->password && b->password
	      && !strcmp(a->password, b->password))))
    return (0);
  return (1);
}

int add_oper(t_operlist **l, t_oper *m)
{
  return (llist_add((t_llist **)l, (void *)m));
}

int delete_oper(t_operlist **l, t_oper *m, t_oper_cmp cmp)
{
  return (llist_delete((t_llist **)l, (void *)m, (t_llist_cmp)cmp));
}

t_oper *find_oper(t_operlist **l, t_oper *m, t_oper_cmp cmp)
{
  return ((t_oper *)llist_find((t_llist **)l, (void *)m, (t_llist_cmp)cmp));
}
