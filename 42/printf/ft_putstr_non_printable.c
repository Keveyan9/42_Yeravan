/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:40:15 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/21 22:37:38 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_hexa(int str)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (str > 16)
	{
		ft_print_hexa(str / 16);
		ft_print_hexa(str % 16);
	}
	else
		write(1, &hex[str], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] > 0)
			|| str[i] == 127)
		{
			write(1, "\\", 1);
			ft_print_hexa(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
