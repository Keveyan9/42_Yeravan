/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:02 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/31 01:46:09 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

unsigned int  timer()
{
	struct timeval get_tim;
	gettimeofday(&get_tim, NULL);
	return(get_tim.tv_usec);
}


void *logic(void *arg)
{
	t_pthread_argument *pthread;
	pthread = arg;
	while(1)
	{	
		take_forks(pthread);
		pthread->starteat = timer();
		if (!((pthread->starteat + pthread->input->eat - pthread->startsleep) <= pthread->input->die))
		{	
			printf("%u_in_ms%u is die \n",timer(),pthread->number + 1);
			put_forks(pthread);
			pthread->kill = (pthread->number + 1) * -1;   
		}	
		printf("%u_in_ms%u is eating \n",pthread->starteat,pthread->number + 1);
		while( timer() - pthread->starteat <= pthread->input->eat*1000);
		put_forks(pthread);
		pthread->startsleep = timer();
		printf("%u_in_ms%u is sleping \n",pthread->startsleep,pthread->number + 1);
		while(timer() - pthread->startsleep <= pthread->input->sleep*1000);
		pthread->startthink = timer();
		printf("%u_in_ms%u is thinking \n",pthread->startthink,pthread->number + 1);
	}
	return(NULL);
}

int creat_philo(t_input_argument *input, t_pthread_argument *pthread)
{
	int n;

	n = 0;
	pthread->input = input;
	pthread->fork = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t) * (input->philo + 1));
	pthread->thread = (pthread_t*) malloc( sizeof(pthread_t)*( input->philo + 1));
	pthread->number = 0;
	while(n < input->philo)
	{
		if (pthread_mutex_init(&(pthread->fork[n]),NULL))
			return (1);
		if(pthread_create(&(pthread->thread[n]),NULL,&logic,pthread))
			return (1);
		n++;
	}	
	n = 0;

	n = 0;

	while(1)
	{
		if(pthread->kill < 0)
		{

			while(n < input->philo )
			{
				if(pthread_mutex_destroy(&(pthread->fork[n])))
					return(1);
				n++;
			}
			return(pthread->kill);
		}
	}
		return(0);
}
