# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 20:59:58 by skeveyan          #+#    #+#              #
#    Updated: 2022/10/09 21:37:00 by skeveyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= pipex
SRCS		= $(shell find "." -name "*.c" )
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
CC			= cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
