/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:02 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/10 23:18:09 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	odd(t_philo_parametr *philo_a, t_input_argument *input)
{
	int	n;

	n = 0;
	while (n < input->philo)
	{
		philo_a[n].number = n;
		philo_a[n].startsleep = 0;
		if (n % 2 == 0)
		{
			if (pthread_create(&(philo_a[n].thread), NULL, &logic, &philo_a[n]))
			{
				printf("creat_tread_problems");
				return (1);
			}
			ft_usleep(10);
		}
		n++;
	}
	return (0);
}

static int	couple(t_philo_parametr *philo_a, t_input_argument *input)
{
	int	n;

	n = 0;
	while (n < input->philo)
	{
		if (n % 2 != 0)
		{
			if (pthread_create(&(philo_a[n].thread), NULL, &logic, &philo_a[n]))
			{
				printf("create_thread_problemsi\n");
				return (1);
			}
			ft_usleep(10);
		}
		n++;
	}
	return (0);
}

int	creat_philo(t_philo_parametr *philo_a, t_input_argument *input)
{
	int	n;

	n = 0;
	pthread_mutex_init(&input->m_print_lock, NULL);
	while (n < input->philo)
	{
		philo_a[n].input = input;
		if (pthread_mutex_init(&(input->fork[n]), NULL))
		{
			printf("mutex_error\n");
			return (1);
		}
		n++;
	}
	if (odd(philo_a, input))
		return (1);
	ft_usleep(100);
	if (couple(philo_a, input))
		return (1);
	return (0);
}
