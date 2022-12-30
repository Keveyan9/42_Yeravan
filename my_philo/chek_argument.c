/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:58:33 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/31 00:21:35 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	chek_argument( char **argv, t_input_argument *input)
{
	input->philo = ft_atoi(argv[1]) - 1;
	input->die = ft_atoi(argv[2]);
	input->eat = ft_atoi(argv[3]);
	input->sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		input->ok_time = ft_atoi(argv[5]);
		if (input->ok_time < 0)
			return (0);
	}
	if (0 > input->philo)
		return (1);
	if (0 > input->die)
		return (1);
	if (0 > input->eat)
		return (1);
	if (0 > input->sleep)
		return (1);
	return (0);
}
