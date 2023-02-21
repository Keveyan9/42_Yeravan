NAME		= fraktal
SRCS		= $(shell find "." -name "*.c" ! -name "hook_bonus.c")
BONUS_SRCS	= $(shell find "." -name "*.c" ! -name "hook.c")
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
INCS		= -I.
CFLAGS		= -Wall -Wextra -Werror $(INCS)
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit 
RM			= rm -f
CC			= cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) *.a

bonus:	${BONUS_OBJS}
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(BONUS_OBJS)  *.a

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
