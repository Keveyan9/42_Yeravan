/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:02 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/05 18:12:40 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

unsigned int  timer()
{
	//struct timeval get_tim;
	//gettimeofday(&get_tim, NULL);
//	return((get_tim.tv_usec/1000) + get_tim.tv_sec );
return(0);
}

void *logic(void *arg)
{
	int n;
	int count;
	t_pthread_argument *pthread;

	pthread = arg;
	n = pthread->number;
	count = pthread->input->ok_time;
printf ("%u\n",n);
	while(1)
	{		
		take_forks(pthread,n);
		pthread->starteat[n] = timer();
		printf("%u _in_ms %u is eating \n",timer(),n + 1);
		while( timer() - pthread->starteat[n] <= pthread->input->eat);
		put_forks(pthread,n);
		pthread->startsleep[n] = timer();
		printf("%u _in_ms %u is sleping \n",timer(),n + 1);
		while(timer() - pthread->startsleep[n] <= pthread->input->sleep);
		pthread->startthink[n] = timer();
		printf("%u _in_ms %u is thinking \n",pthread->startthink[n],n + 1);
	}
	return(NULL);
}

int creat_philo(t_input_argument *input, t_pthread_argument *pthread)
{
	int n;

	n = 0;
	pthread->input = input;
	pthread->fork = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * input->philo);
	pthread->thread = (pthread_t *) malloc(sizeof(pthread_t) * input->philo);
	pthread->starteat = (unsigned int*) malloc( sizeof(unsigned int) * input->philo);
	pthread->startsleep = (unsigned int*) malloc( sizeof(unsigned int) * input->philo);
	pthread->startthink = (unsigned int*) malloc( sizeof(unsigned int) * input->philo );

	pthread->number = 0;
	while(n < input->philo)
	{
		if (pthread_mutex_init(&(pthread->fork[n]),NULL))
			return (1);
		n++;
	}
	n = 0;
	while(n < input->philo)
	{
		if(pthread_create(&(pthread->thread[n]),NULL,&logic,pthread))
			return (1);
		n++;
		usleep(30);
	    pthread->number++;
		}	
//	while(1);
	return(0);
}
