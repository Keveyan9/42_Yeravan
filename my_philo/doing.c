/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:14:17 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/10 23:30:27 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

void	print_s(char *s, t_philo_parametr *philos)
{
	pthread_mutex_lock(&(philos->input->m_print_lock));
	printf("%lld _in_ms _%u_ %s\n", get_time(), philos->number + 1, s);
	pthread_mutex_unlock(&(philos->input->m_print_lock));
}

void	take_forks(t_philo_parametr *philos)
{
	if (philos->number == philos->input->philo - 1)
	{
		pthread_mutex_lock(&(philos->input->fork[philos->number]));
		print_s("has taken a left fork", philos);
		pthread_mutex_lock(&(philos->input->fork[0]));
		print_s("has taken a right fork", philos);
	}
	else
	{
		pthread_mutex_lock(&(philos->input->fork[philos->number]));
		print_s("has taken a left fork", philos);
		pthread_mutex_lock(&(philos->input->fork[philos->number + 1]));
		print_s("has taken a right fork", philos);
	}
}

void	put_forks(t_philo_parametr *philos)
{
	if (philos->number == philos->input->philo - 1)
	{
		pthread_mutex_unlock(&(philos->input->fork[philos->number]));
		pthread_mutex_unlock(&(philos->input->fork[0]));
	}
	else
	{
		pthread_mutex_unlock(&(philos->input->fork[philos->number]));
		pthread_mutex_unlock(&(philos->input->fork[philos->number + 1]));
	}
}
