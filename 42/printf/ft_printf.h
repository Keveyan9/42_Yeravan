#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <stdarg.h>
#include<limits.h>


void	ft_print_char(int *len, char c);
void	ft_print_string(int *len, char *c);
void	ft_print_number (int *len, int number);
void ft_print_unsigned( int *len,unsigned int num);
#endif