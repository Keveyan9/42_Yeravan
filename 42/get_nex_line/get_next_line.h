/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:39:09 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/02 22:39:12 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE

# endif

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include<stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char *return_chekin(char *s1);



#endif