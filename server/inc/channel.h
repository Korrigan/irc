
#ifndef CHANNEL_H_
# define CHANNEL_H_

# include "llist.h"
# include "mode.h"
# include "user.h"
# include "buffer.h"

struct			s_channel
{
  char			*name;
  char			*topic;
  char			*password;
  unsigned		limit;
  t_mode		mode;
  t_usermodelist	*users;
  t_banlist		*banlist;
  t_buffer		obuf;
};
typedef struct s_channel t_channel;

typedef t_llist t_chanlist;
typedef int	(*t_channel_cmp)(t_channel *a, t_channel *b);

int		chanel_cmp(t_channel *a, t_channel *b);
int		add_channel(t_chanlist **l, t_channel *c);
int		delete_channel(t_chanlist **l, t_channel *c, t_channel_cmp cmp);
t_channel	*find_channel(t_chanlist **l, t_channel *c, t_channel_cmp cmp);

int		push_message_to_chan(t_channel *chan, t_message *msg);

#endif	/* !CHANNEL_H_ */
