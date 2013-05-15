
#ifndef BUFFER_H_
# define BUFFER_H_

# include "llist.h"

typedef t_llist t_stringlist;
typedef struct
{
  unsigned	size;
  t_stringlist	*list;
}		t_buffer;

void		buffer_clear(t_buffer *buf);
int		buffer_append(t_buffer *buf, char *str);
char		*buffer_to_string(t_buffer *buf);

#endif	/* !BUFFER_H_ */
