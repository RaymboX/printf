SRCS = 			ft_ltoa.c ft_printf.c ft_printf_utils.c

OBJS = 			$(SRCS:.c=.o)

CFLAGS =		-Wall -Werror -Wextra

CC	=			cc

NAME = 			libftprintf.a

RM	=	 		rm -f

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re
