/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:29:28 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/12 20:57:13 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	long int	res;
	int			minus_counter;

	res = 0;
	minus_counter = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_counter = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = (res * 10) +(*str - '0');
		str++;
	}
	if (!(*str))
		return (res * minus_counter);
	write (1, "non corect input\n", 17);
	exit(0);
}
