/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:37:11 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/06 23:37:14 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first_row(int x)
{
	int	i;

	i = 2;
	ft_putchar('A');
	if (x >= 2)
	{
		while (i < x)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	print_middle_row(int x)
{
	int	i;

	i = 2;
	ft_putchar('B');
	if (x >= 2)
	{
		while (i < x)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	print_last_row(int x)
{
	int	i;

	i = 2;
	ft_putchar('C');
	if (x >= 2)
	{
		while (i < x)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 2;
	if (x > 2 && y > 2)
	{	
		print_first_row(x);
		if (y >= 2)
		{
			while (i < y)
			{
				print_middle_row(x);
				i++;
			}
			print_last_row(x);
		}
	}
}