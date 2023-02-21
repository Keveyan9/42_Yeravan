/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_distroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:14:33 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/11 15:32:21 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	chek_start(t_philo_parametr *philo_a,
t_input_argument *input, int n)
{
	if (input->tred_finish != 0)
		print_s("die is can not eat", &philo_a[n]);
	pthread_mutex_lock(&input->m_print_lock);
	n = 0;
	while (n < input->philo)
	{
		pthread_detach(philo_a[n].thread);
		pthread_mutex_destroy(&input->fork[n++]);
	}
	return (1);
}

int	chek_distroy(t_philo_parametr *philo_a, t_input_argument *input)
{
	int	n;

	n = 0;
	while (n < input->philo)
	{
		if (philo_a[n].start > 10)
		{
			if (philo_a[n].startsleep == 0)
			{				
				if (get_time() - philo_a[n].start > input->die)
					return (chek_start(philo_a, input, n));
			}	
			else
			{
				if (get_time() - philo_a[n].startsleep > input->die)
					return (chek_start(philo_a, input, n));
			}
		}
		n++;
		if (n == input->philo)
			n = 0;
	}
	return (-1);
}
