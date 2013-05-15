
#ifndef LLIST_H_
# define LLIST_H

typedef struct s_llist t_llist;
struct		s_llist
{
  void		*data;
  t_llist	*next;
};

typedef int	(*t_llist_cmp)(void *a, void *b);

int		llist_add(t_llist **l, void *d);
int		llist_delete(t_llist **l, void *d, t_llist_cmp cmp);
void		*llist_find(t_llist **l, void *d, t_llist_cmp cmp);

#endif	/* !LLIST_H */
