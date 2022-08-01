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
  

void printing_convert (int *len,const char *input,va_list *argument)
{
	if (*input == 'c')
		ft_print_char(len,(va_arg(*argument,int )));
	else if (*input == 's')
		ft_print_string(len,(va_arg(*argument,char*)));
	// else if (input[n] == 'p')
	// 	print_addres((len,(va_arg(argument,char*))));
	else if (*input == 'd' || *input == 'i')
		ft_print_number(len,(va_arg(*argument,int)));
	 else if (*input == 'u')
	 	ft_print_unsigned(len,(va_arg(*argument,unsigned int )));
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
				printing_convert(&len,input,&argument);
			}
			else if(*(input))
			{
				write(1,input,1);
				len++;
			}
	}
	va_end(argument);
	return(len);
}
int main ()
{
	char t;
	unsigned int d = INT_MAX;

	d = d + 10;
	t = 'd';
	  printf("--%u--\n",ft_printf("%dawfaw",d));
	//ft_printf("%p",&t);
//ft_printf("%d%c",-147,'c');
//	write(1,&t,14);
}