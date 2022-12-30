/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:14:17 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/31 01:40:22 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

void take_forks(t_pthread_argument *pthread)
{

		if(pthread->number == pthread->input->philo)
		{
			pthread_mutex_lock(&pthread->fork[pthread->number ]);
			printf("%u _in_ms %u has taken a left fork\n",timer(),pthread->number + 1);
			pthread_mutex_lock(&pthread->fork[0]);
			printf("%u _in_ms %u has taken a right fork\n",timer(),pthread->number + 1);
		}
		else
		{
			pthread_mutex_lock(&pthread->fork[pthread->number ]);
			printf("%u _in_ms %u has taken a left fork\n",timer(),pthread->number + 1);
			pthread_mutex_lock(&pthread->fork[pthread->number + 1]);
			printf("%u _in_ms %u has taken a right fork\n",timer(),pthread->number + 1);
		}
}

 
void put_forks(t_pthread_argument *pthread)
{

	if(pthread->number == pthread->input->philo - 1)
	{
		pthread_mutex_unlock(&pthread->fork[pthread->number ]);
		pthread_mutex_unlock(&pthread->fork[0]);
	}
	else
	{
		pthread_mutex_unlock(&pthread->fork[pthread->number ]);
		pthread_mutex_unlock(&pthread->fork[pthread->number + 1]);
		pthread->starteat = timer();
	}
}
