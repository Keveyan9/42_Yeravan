/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:14:17 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/05 17:34:39 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

int chek_distroy(t_pthread_argument *pthread)
{
	int n;

	n = 0;
	while(1)
	{
		while( n < pthread->input->philo )
		{
			if(timer() - pthread->input->die < pthread->startsleep[n] ) 
			{
				printf("%u\n", timer() - pthread->starteat[n]); 
				printf("%u in_ms is died %u\n",timer(),n + 1);
			n = 0;
			while(0 )
			{
				if(pthread_mutex_lock(&pthread->fork[n]))
					return(2);
				if(pthread_mutex_destroy(&(pthread->fork[n])))
					return(1);
				n++;
			}
			return(1);
			}
		n++;
		}
		n = 0;
	}
	return(0);
}

void take_forks(t_pthread_argument *pthread,int n)
{

		if(n  == pthread->input->philo - 1)
		{
			pthread_mutex_lock(&pthread->fork[n]);
			printf("%u _in_ms %u has taken a left fork\n",timer(),n + 1);
			pthread_mutex_lock(&pthread->fork[0]);
			printf("%u _in_ms %u has taken a right fork\n",timer(),n + 1);
		}
		else
		{
			pthread_mutex_lock(&pthread->fork[n ]);
			printf("%u _in_ms %u has taken a left fork\n",timer(),n + 1);
			pthread_mutex_lock(&pthread->fork[n + 1]);
			printf("%u _in_ms %u has taken a right fork\n",timer(),n + 1);
		}
}

void put_forks(t_pthread_argument *pthread, int n)
{

	if(n  == pthread->input->philo - 1)
	{
		pthread_mutex_unlock(&pthread->fork[n]);
		pthread_mutex_unlock(&pthread->fork[0]);
	}
	else
	{
		pthread_mutex_unlock(&pthread->fork[n]);
		pthread_mutex_unlock(&pthread->fork[n + 1]);
	}
}
