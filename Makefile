NAME    =   SELECT_PPSE

SRCS 	:=	$(shell find . -name '*.c')

HEAD	:=	$(shell find . -name '*.h')

OBJS	=	$(SRCS:.c=.o)

.c.o:
			$(GCC) $(FLAG) -c $< -o $(<:.c=.o)

GCC		= 	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -f
C		=	-c
O		=	-o

all:		$(NAME)

$(NAME):    $(OBJS)
			$(GCC) $(FLAG) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

$(OBJS):	$(HEAD)

fclean:		clean
			$(RM) $(NAME)

re:         fclean all

.PHONY:		all clean fclean re
