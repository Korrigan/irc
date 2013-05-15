
#include <stdlib.h>
#include <string.h>
#include "llist.h"
#include "buffer.h"

void		buffer_clear(t_buffer *buf)
{
  t_stringlist	*next;

  while (buf->list)
    {
      next = buf->list->next;
      free(buf->list->data);
      free(buf->list);
      buf->list = next;
    }
  buf->size = 0;
}

int		buffer_append(t_buffer *buf, char *s)
{
  char		*ap;

  if (!s)
    return (0);
  if (!(ap = strdup(s)) ||
      llist_add((t_llist **)(&buf->list), (void *)s))
    return (1);
  buf->size += strlen(s);
  return (0);
}

char		*buffer_to_string(t_buffer *buf)
{
  int		i;
  int		len;
  char		*s;
  t_stringlist	*it;

  if (!buf->size || !(s = malloc(buf->size + 1)))
    return (NULL);
  i = 0;
  it = buf->list;
  while (it)
    {
      len = strlen((char *)it->data);
      strncpy(s + i, (char *)it->data, len);
      i += len + 1;
      it = it->next;
    }
  s[i] = 0;
  return (s);
}
