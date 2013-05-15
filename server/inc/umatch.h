
#ifndef UMATCH_H_
# define UMATCH_H_

# include "llist.h"

typedef struct
{
  char		*user;
  char		*host;
}		t_umatch;
typedef t_llist t_umatchlist;
typedef int	(*t_umatch_cmp)(t_umatch *a, t_umatch *b);

t_umatch		*new_umatch(char *u, char *h);
int		match_cmp(t_umatch *a, t_umatch *b);
int		add_match(t_umatchlist **list, t_umatch *m);
int		delete_match(t_umatchlist **list, t_umatch *m, t_umatch_cmp cmp);
t_umatch	*find_match(t_umatchlist **list, t_umatch *m, t_umatch_cmp cmp);

#endif	/* !UMATCH_H_ */
