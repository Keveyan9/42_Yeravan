/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:36:30 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/14 22:42:37 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_manual(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	f;
	int	s;

	f = 0;
	while (f <= 98)
	{
		s = f + 1;
		while (s <= 99)
		{
			ft_manual((f / 10) + '0');
			ft_manual((f % 10) + '0');
			ft_manual (' ');
			ft_manual ((s / 10) + '0');
			ft_manual ((s % 10) + '0');
			if (f != 98)
				write(1, ", ", 2);
			s++;
		}
		f++;
	}
}
