
#include <stdlib.h>
#include "llist.h"

static t_llist	*new_llist_node(void *data)
{
  t_llist	*n;

  if (!(n = malloc(sizeof(*n))))
    return (NULL);
  n->data = data;
  return (n);
}

int		llist_add(t_llist **list, void *d)
{
  t_llist	*node;
  t_llist	*it;

  if (!(node = new_llist_node(d)))
    return (1);
  if (!*list)
    {
      *list = node;
      return (0);
    }
  it = *list;
  while ((it = it->next));
  it->next = node;
  return (0);
}

int		llist_delete(t_llist **list, void *d, t_llist_cmp cmp)
{
  int		del;
  t_llist	*prev;
  t_llist	*next;
  t_llist	*it;

  del = 0;
  prev = NULL;
  it = *list;
  while (it)
    {
      if (!cmp(d, it->data))
	{
	  if (prev)
	    prev->next = it->next;
	  else
	    *list = it->next;	    
	  next = it->next;
	  del++;
	  free(it);
	}
      else
	{
	  prev = it;
	  next = it->next;
	}
      it = next;
    }
  return (del);
}

void		*llist_find(t_llist **list, void *d, t_llist_cmp cmp)
{
  t_llist	*it;

  if (!*list)
    return (NULL);
  it = *list;
  while (it)
    {
      if (!cmp(d, it->data))
	return it->data;
      it = it->next;
    }
  return (NULL);
}
