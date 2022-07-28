/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:15:36 by skeveyan          #+#    #+#             */
/*   Updated: 2022/05/27 23:15:38 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  #include "ft_printf.h"

void printing_convert (int *len,const char *input,va_list argument)
{
	if (*input == 'c')
		ft_print_char(len,(va_arg(argument,char*)));
	else if (*input == 's')
		ft_print_string(len,(va_arg(argument,char*)));
	else if (input[n] == 'p')
		print_addres((len,(va_arg(argument,char*))));
	// else if (input[n] == 'd' || input[n] == 'i')
	// 	print_number();
	// else if (input[n] == 'i')
	// 	print	
	
	// else if (input[n] == 'u')
	// else if (input[n] == 'x')
	// else if (input[n] == '%')
}
int ft_printf(const char *input, ...)
{
	size_t	n;
	va_list	argument;
	int len;

	len = 0;
	n = 0;
	va_start(argument, input);

	while (*input)
	{
		if(*(input++) == '%')
			{
				printing_convert(&len,input,argument);
			}
	}
	va_end(argument);
	return(len);
}
int main ()
{
	char t;
	t = 'd';
	 printf("%d",ft_printf("%s","Hwfw"));
	ft_printf("%p",&t);
//	write(1,&t,14);
}