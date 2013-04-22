
#ifndef MESSAGE_H_
# define MESSAGE_H_

# define VALID_SPECIAL		".@!_-[]{}\\`^"
# define INVALID_MIDDLE		"\r\n "

typedef enum 
  {
    USER,
    NICK,
    PASS
  }		t_command;

/*
** Used to match commands with the enum
*/
typedef struct {
  t_command	cmd;
  char		*string;
}		t_cmd_converter;

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
** Internal use only
*/
int		parse_prefix(t_message *ret, char **str);
int		parse_command(t_message *ret, char **str);
int		parse_params(t_message *ret, char **str);

#endif	/* !MESSAGE_H_ */
