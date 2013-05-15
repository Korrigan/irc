#
# Makefile for llist library
#

NAME=			libllist.a

SRCD=			src/
INCD=			inc/

SRCF=			llist.c

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
