/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:00:54 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/16 21:44:15 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include<stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;

	x = 0;
	if (*b != 0)
	{
		x = *a;
		*a = *a / *b ;
		*b = x % *b;
	}
}