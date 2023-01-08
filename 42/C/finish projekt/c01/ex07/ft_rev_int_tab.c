/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:09:28 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/17 17:36:23 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	moment ;

	moment = 0;
	n = 0;
	while (size / 2 > n)
	{
		moment = tab[n];
		tab[n] = tab[size - n - 1];
		tab[size - n - 1] = moment;
		n++;
	}
}
