/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:55:24 by skeveyan          #+#    #+#             */
/*   Updated: 2022/03/18 14:17:20 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include<unistd.h>
#include<string.h>

int	ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s,size_t n);
void *ft_memcpy(void *restrict dst,const void *restrict src, size_t n);
void *ft_memmove(void *dst,const void *src,size_t len);
size_t ft_strcpy(char *restrict dst,const char *restrict src,size_t dstsize);
size_t ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);