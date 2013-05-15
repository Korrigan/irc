
#ifndef MODE_H_
# define MODE_H_

# include "umatch.h"
# include "llist.h"

# define MODE_O		(1 << 0)
# define MODE_P		(1 << 1)
# define MODE_S		(1 << 2)
# define MODE_I		(1 << 3)
# define MODE_T		(1 << 4)
# define MODE_N		(1 << 5)
# define MODE_M		(1 << 6)
# define MODE_L		(1 << 7)
# define MODE_B		(1 << 8)
# define MODE_V		(1 << 9)
# define MODE_K		(1 << 10)
# define MODE_W		(1 << 11)

# define MODE_SET(mask, mode)		(mask |= mode)
# define MODE_UNSET(mask, mode)		(mask ^= mode)
# define MODE_ISSET(mask, mode)		(mask & mode)

typedef unsigned t_mode;


typedef struct
{
  t_umatch	match;
  char		*comment;
}		t_ban;

typedef t_llist t_banlist;
typedef int	(*t_ban_cmp)(t_ban *a, t_ban *b);

typedef struct
{
  t_umatch	match;
  char		*password;
}		t_oper;
typedef t_llist t_operlist;
typedef int	(*t_oper_cmp)(t_oper *a, t_oper *b);

int	ban_cmp(t_ban *a, t_ban *b);
int	add_ban(t_banlist **l, t_ban *b);
int	delete_ban(t_banlist **l, t_ban *b, t_ban_cmp cmp);
t_ban	*find_ban(t_banlist **l, t_ban *b, t_ban_cmp cmp);

int	oper_cmp(t_oper *a, t_oper *o);
int	add_oper(t_operlist **l, t_oper *o);
int	delete_oper(t_operlist **l, t_oper *o, t_oper_cmp cmp);
t_oper	*find_oper(t_operlist **l, t_oper *o, t_oper_cmp cmp);

#endif	/* !MODE_H_ */
