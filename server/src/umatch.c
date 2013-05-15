
#include <string.h>
#include <stdlib.h>
#include "umatch.h"

t_umatch	*new_umatch(char *u, char *h)
{
  t_umatch	*m;

  if (!(m = malloc(sizeof(*m))))
    return (NULL);
  m->user = u;
  m->host = h;
  return (m);
}

int		match_cmp(t_umatch *a, t_umatch *b)
{
  if (((!a->user && !b->user)
       || (a->user && b->user && !strcmp(a->user, b->user)))
      && ((!a->host && !b->host)
	  || (a->host && b->host && !strcmp(a->host, b->host))))
    return (0);
  return (1);
}

int		add_match(t_umatchlist **l, t_umatch *m)
{
  return (llist_add((t_llist **)l, (void *)m));
}

int		delete_match(t_umatchlist **l, t_umatch *m, t_umatch_cmp cmp)
{
  return (llist_delete((t_llist **)l, (void *)m, (t_llist_cmp)cmp));
}

t_umatch	*find_match(t_umatchlist **l, t_umatch *m, t_umatch_cmp cmp)
{
  return ((t_umatch *)llist_find((t_llist **)l, (void *)m, (t_llist_cmp)cmp));
}
