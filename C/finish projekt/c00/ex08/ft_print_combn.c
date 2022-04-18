/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:28:34 by artadevo          #+#    #+#             */
/*   Updated: 2022/02/15 16:55:13 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_tab(int *tab, int n)
{
	int	i;
	int	d;

	d = 1;
	i = 0;
	while (++i < n)
		if (tab[i - 1] >= tab[i])
			d = 0;
	if (!d)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(tab[i] + 48);
	if (tab[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[10];

	if (n > 10 || n < 0)
		return ;
	i = -1;
	while (++i < n)
		tab[i] = i;
	while (tab[0] <= (10 - n) && n >= 1)
	{
		ft_tab(tab, n);
		if (n == 10)
			break ;
		tab[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
		}
	}
}
