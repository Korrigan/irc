
#ifndef IRC_H_
# define IRC_H_

# include "proto.h"
# include "mode.h"
# include "user.h"
# include "channel.h"

typedef struct
{
  t_userlist	*users;
  t_chanlist	*channels;
  t_banlist	*klines;
  t_operlist	*olines;
}		t_irc;

typedef int	(*t_cmd_callback)(t_irc *irc, t_user *from, const t_message *msg);

typedef struct
{
  t_command		cmd;
  t_cmd_callback	f;
}			t_command_caller;

# define CMD_CALLER_SIZE	6

int	process_message(t_irc *irc, t_user *from, const t_message *msg);

/*
** Callbacks
*/
int	oper(t_irc *irc, t_user *from, const t_message *msg);
int	user(t_irc *irc, t_user *from, const t_message *msg);
int	nick(t_irc *irc, t_user *from, const t_message *msg);
int	join(t_irc *irc, t_user *from, const t_message *msg);
int	part(t_irc *irc, t_user *from, const t_message *msg);
int	quit(t_irc *irc, t_user *from, const t_message *msg);

#endif	/* !IRC_H_ */
