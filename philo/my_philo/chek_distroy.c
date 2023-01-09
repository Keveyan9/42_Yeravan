/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_distroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:14:33 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/10 01:36:07 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int chek_distroy_eats_moment(philo_parametr *philos)
{
	while(timer() - philos->starteat <= philos->input->eat)
	{
		if(philos->startsleep > 0)
		{
			if(timer()  - philos->startsleep > philos->input->die)
			{
				print_s(" die is ___________-eat",philos);
				philos->input->print_lock = 0;
				pthread_mutex_lock(&(philos->input->m_print_lock));
				usleep(10);
				pthread_mutex_unlock(&(philos->input->m_print_lock));
				return(1);
			}
		}
	}
	return(0);
}

int chek_distroy_sleep_moment(philo_parametr *philos)
{
	while(timer() - philos->startsleep <= philos->input->sleep)
	{
		if(philos->startsleep > 0)
		{
			if(timer()  - philos->startsleep > philos->input->die)
			{
				print_s(" die is ______________sleep",philos);
				philos->input->print_lock = 0;
				pthread_mutex_lock(&(philos->input->m_print_lock));
				usleep(10);
				pthread_mutex_unlock(&(philos->input->m_print_lock));
				return(1);
			}
		}
	}
	return(0);
}
