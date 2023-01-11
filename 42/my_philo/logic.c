/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:28:24 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/11 15:29:53 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*logic(void *arg)
{
	t_philo_parametr	*philos;
	int					siqel;

	siqel = 0;
	philos = arg;
	philos->start = get_time();
	philos->input->tred_finish = 1;
	while (philos->input->ok_siqel == -1 || philos->input->ok_siqel > siqel++)
	{
		take_forks(philos);
		philos->starteat = get_time();
		print_s("is eating", philos);
		ft_usleep(philos->input->eat);
		put_forks(philos);
		philos->startsleep = get_time();
		print_s("is sleeping ", philos);
		ft_usleep(philos->input->sleep);
		philos->startthink = get_time();
		print_s("is thinking ", philos);
	}
	philos->input->tred_finish = 0;
	return (NULL);
}
