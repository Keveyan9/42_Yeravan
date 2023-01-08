/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:14:17 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/08 23:23:16 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

void print_s(char *s, philo_parametr *philos)
{
	if(philos->input->print_lock)
		printf("%u _in_ms %u %s\n",timer(),philos->number + 1, s);
}

void take_forks(philo_parametr *philos)
{

		if( philos->number  == philos->input->philo - 1)
		{
			pthread_mutex_lock(&(philos->input->fork[philos->number]));
			print_s("has taken a left fork",philos);
			pthread_mutex_lock(&(philos->input->fork[0]));
			print_s("has taken a right fork",philos);
		}
		else
		{

			pthread_mutex_lock(&(philos->input->fork[philos->number]));
			print_s("has taken a left fork",philos);
			pthread_mutex_lock(&(philos->input->fork[philos->number + 1]));
			print_s("has taken a right fork",philos);
		}
}

void put_forks(philo_parametr *philos)
{
		if(philos->number  == philos->input->philo - 1)
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
