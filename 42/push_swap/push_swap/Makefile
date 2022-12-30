NAME		= push_swap
SRCS		= $(shell find "." -name "*.c" )
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
CC			= cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
