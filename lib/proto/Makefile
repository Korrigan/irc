#
# Makefile for lib proto (IRC)
#

NAME=			libircproto.a

SRCD=			src/
INCD=			inc/

SRCF=			parse_command.c \
			parse_message.c \
			parse_params.c \
			parse_prefix.c \
			convert_cmd.c \
			new_message.c \
			get_string_from_message.c

SRC=			$(addprefix $(SRCD), $(SRCF))
OBJ=			$(SRC:.c=.o)

CFLAGS+=		-W -Wall -O2 -I$(INCD) -D_GNU_SOURCE

RM=			@rm -vf
CP=			@cp -v
AR=			ar rcv
RAN=			ranlib

$(NAME):		$(OBJ)
			$(AR) $@ $^
			$(RAN) $@
			$(CP) $@ ../$@

all:			$(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)
			$(RM) ../$(NAME)

re:			fclean all
