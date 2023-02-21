/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:59:26 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/17 22:17:01 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int	*tab, int size)
{
	int	x;
	int	f;
	int	k;

	k = 0;
	f = 0;
	x = 0;
	while (k < size - 1)
	{
		f = 0;
		while (f < size - 1)
		{
			if (tab[f] > tab[f + 1])
			{
			x = tab[f];
			tab[f] = tab[f + 1];
			tab[f + 1] = x;
			}
			f++;
		}
		k++;
	}
}
