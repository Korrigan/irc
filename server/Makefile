#
# Makefile for IRK IRC daemon
#

NAME=		irkd

SRCD=		src/
CMDD=		commands/
INCD=		inc/ \
		../lib/inc/

SRCF=		main.c \
		oper.c \
		ban.c \
		umatch.c \
		user.c \
		channel.c \
		usermode.c \
		push_message.c \
		buffer.c \
		process_message.c

CMDF=		oper.c \
		user.c \
		nick.c

SRCF+=		$(addprefix $(CMDD), $(CMDF))
SRC=		$(addprefix $(SRCD), $(SRCF))
OBJ=		$(SRC:.c=.o)

CC=		gcc
RM=		@rm -fv

INCFLAGS=	$(addprefix -I, $(INCD))
CFLAGS+=	-W -Wall -Wextra $(INCFLAGS)
LDFLAGS+=	-L../lib -lircproto -lllist

$(NAME):	$(OBJ)
		$(CC) -o $@ $^ $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

