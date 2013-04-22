
#ifndef MESSAGE_H_
# define MESSAGE_H_

# define VALID_SPECIAL		".@!_-[]{}\\`^"
# define INVALID_MIDDLE		"\r\n "

typedef enum 
  {
    OPER,
    PASS,
    USER,
    NICK,
    NOTICE,
    PRIVMSG,
    MODE,
    INVITE,
    TOPIC,
    KICK,
    JOIN,
    PART,
    QUIT,
    WHO,
    WHOIS,
    WHOWAS,
    NAMES,
    LIST,
    VERSION,
    TIME,
    PING,
    PONG,
    ERROR,
    REHASH,
    RESTART,

    RPL_NONE,
    RPL_USERHOST,
    RPL_ISON,
    RPL_AWAY,
    RPL_UNAWAY,
    RPL_NOWAWAY,
    RPL_WHOISUSER,
    RPL_WHOISSERVER,
    RPL_WHOISOPERATOR,
    RPL_WHOISIDLE,
    RPL_ENDOFWHOIS,
    RPL_WHOISCHANNELS,
    RPL_WHOWASUSER,
    RPL_ENDOFWHOWAS,
    RPL_LISTSTART,
    RPL_LIST,
    RPL_LISTEND,
    RPL_CHANNELMODEIS,
    RPL_NOTOPIC,
    RPL_TOPIC,
    RPL_INVITING,
    RPL_SUMMONING,
    RPL_VERSION,
    RPL_WHOREPLY,
    RPL_ENDOFWHO,
    RPL_NAMREPLY,
    RPL_ENDOFNAMES,
    RPL_LINKS,
    RPL_ENDOFLINKS,
    RPL_BANLIST,
    RPL_ENDOFBANLIST,
    RPL_INFO,
    RPL_ENDOFINFO,
    RPL_MOTDSTART,
    RPL_MOTD,
    RPL_ENDOFMOTD,
    RPL_YOUREOPER,
    RPL_REHASHING,
    RPL_TIME,
    RPL_USERSSTART,
    RPL_USERS,
    RPL_ENDOFUSERS,
    RPL_NOUSERS,
    RPL_TRACELINK,
    RPL_TRACECONNECTING,
    RPL_TRACEHANDSHAKE,
    RPL_TRACEUNKNOWN,
    RPL_TRACEOPERATOR,
    RPL_TRACEUSER,
    RPL_TRACESERVER,
    RPL_TRACENEWTYPE,
    RPL_TRACELOG,
    RPL_STATSLINKINFO,
    RPL_STATSCOMMANDS,
    RPL_STATSCLINE,
    RPL_STATSNLINE,
    RPL_STATSILINE,
    RPL_STATSKLINE,
    RPL_STATSYLINE,
    RPL_ENDOFSTATS,
    RPL_STATSLLINE,
    RPL_STATSUPTIME,
    RPL_STATSOLINE,
    RPL_STATSHLINE,
    RPL_UMODEIS,
    RPL_LUSERCLIENT,
    RPL_LUSEROP,
    RPL_LUSERUNKNOWN,
    RPL_LUSERCHANNELS,
    RPL_LUSERME,
    RPL_ADMINME,
    RPL_ADMINLOC,
    RPL_ADMINEMAIL,

    ERR_NOSUCHNICK,
    ERR_NOSUCHSERVER,
    ERR_NOSUCHCHANNEL,
    ERR_CANNOTSENDTOCHAN,
    ERR_TOOMANYCHANNELS,
    ERR_WASNOSUCHNICK,
    ERR_TOOMANYTARGETS,
    ERR_NOORIGIN,
    ERR_NORECIPIENT,
    ERR_NOTEXTTOSEND,
    ERR_NOTOPLEVEL,
    ERR_WILDTOPLEVEL,
    ERR_UNKNOWNCOMMAND,
    ERR_NOMOTD,
    ERR_NOADMININFO,
    ERR_FILEERROR,
    ERR_NONICKNAMEGIVEN,
    ERR_ERRONEUSNICKNAME,
    ERR_NICKNAMEINUSE,
    ERR_NICKCOLLISION,
    ERR_USERNOTINCHANNEL,
    ERR_NOTONCHANNEL,
    ERR_USERONCHANNEL,
    ERR_NOLOGIN,
    ERR_SUMMONDISABLED,
    ERR_USERSDISABLED,
    ERR_NOTREGISTERED,
    ERR_NEEDMOREPARAMS,
    ERR_ALREADYREGISTRED,
    ERR_NOPERMFORHOST,
    ERR_PASSWDMISMATCH,
    ERR_YOUREBANNEDCREEP,
    ERR_KEYSET,
    ERR_CHANNELISFULL,
    ERR_UNKNOWNMODE,
    ERR_INVITEONLYCHAN,
    ERR_BANNEDFROMCHAN,
    ERR_BADCHANNELKEY,
    ERR_NOPRIVILEGES,
    ERR_CHANOPRIVSNEEDED,
    ERR_CANTKILLSERVER,
    ERR_NOOPERHOST,
    ERR_UMODEUNKNOWNFLAG,
    ERR_USERSDONTMATCH,
    
    NOCOMMAND
  }		t_command;


/*
** Used to match commands with the enum
*/
typedef struct {
  t_command	cmd;
  char		*string;
}		t_cmd_converter;

# define CMD_CONVERTER_SIZE	142
extern const t_cmd_converter	cmd_converter[CMD_CONVERTER_SIZE];

/*
** params: NULL terminated array of params
*/
typedef struct {
  t_command	command;
  char		*prefix;
  char		**params;
}		t_message;

int		parse_message(t_message *ret, const char *msg);

/*
** the returned string has to be freed
*/
char		*get_string_from_message(const t_message *msg);

t_command	command_from_string(const char *str);
const char	*command_to_string(t_command cmd);

/*
** Internal use only
*/
int		parse_prefix(t_message *ret, char **str);
int		parse_command(t_message *ret, char **str);
int		parse_params(t_message *ret, char **str);

#endif	/* !MESSAGE_H_ */
