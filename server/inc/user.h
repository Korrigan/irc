#ifndef USER_H_
# define USER_H_

# include "llist.h"
# include "proto.h"
# include "mode.h"
# include "buffer.h"

typedef t_llist t_chanlist;

typedef struct
{
  char		*name;
  char		*host;
  char		*realname;
  t_mode	mode;
  t_chanlist	*channels;
  t_buffer	obuf;
}		t_user;
typedef t_llist t_userlist;
typedef int	(*t_user_cmp)(t_user *a, t_user *b);

typedef struct
{
  t_user	*user;
  t_mode	mode;
}		t_usermode;
typedef t_llist t_usermodelist;
typedef int	(*t_usermode_cmp)(t_usermode *a, t_usermode *b);

int		push_message_to_user(t_user *user, t_message *msg);

int		user_cmp(t_user *a, t_user *u);
int		add_user(t_userlist **l, t_user *u);
int		delete_user(t_userlist **l, t_user *u, t_user_cmp cmp);
t_user		*find_user(t_userlist **l, t_user *u, t_user_cmp cmp);

int		usermode_cmp(t_usermode *a, t_usermode *b);
int		add_usermode(t_usermodelist **l, t_usermode *um);
int		delete_usermode(t_usermodelist **l, t_usermode *um, t_usermode_cmp cmp);
t_usermode	*find_usermode(t_usermodelist **l, t_usermode  *um, t_usermode_cmp cmp);

#endif	/* !USER_H_ */
