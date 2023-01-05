/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:29:28 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/28 20:27:38 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	chek_plus_minus( const char **str, int *minus_counter)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus_counter = -1;
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
		{
			write (1, "non corect input\n", 17);
			return(0);
		}	
	}
	return(1);
}

long int	ft_atoi(const char *str)
{
	long int	res;
	int			minus_counter;

	res = 0;
	minus_counter = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if(0 == (chek_plus_minus(&str, &minus_counter)))
			return(0);
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = (res * 10) +(*str - '0');
		str++;
	}
	if (!(*str))
		return (res * minus_counter);
	write (1, "non corect input\n", 17);
	return(0);
}
