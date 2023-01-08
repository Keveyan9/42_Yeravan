/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:02 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/09 00:17:28 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

unsigned int  timer()
{
	struct timeval get_tim;
	gettimeofday(&get_tim, NULL);
	return((get_tim.tv_usec/1000) + get_tim.tv_sec );
}

void *logic(void *arg)
{
	int n;
	int siqel;
	philo_parametr *philos;
	
	siqel = 0;
	philos = arg;
	while(philos->input->tred_finish && (philos->input->ok_siqel == -1
			|| philos->input->ok_siqel > siqel++))
	{	
	
		take_forks(philos);
		philos->starteat= timer();
		print_s("is eating ",philos);
		while(timer() - philos->starteat <= philos->input->eat);
		put_forks(philos);
		philos->startsleep = timer();
		print_s("is sleeping ",philos);
		while(timer() - philos->startsleep <= philos->input->sleep);
		philos->startthink = timer();
		print_s("is thinking ",philos);
	}
	return(NULL);
}

int creat_philo(philo_parametr *philo_a,t_input_argument *input)
{
	int n;

	n = 0;
	while(n < input->philo)
	{
		philo_a[n].input = input;
		if(pthread_mutex_init(&(input->fork[n]),NULL))
		{
			printf("mutex_error\n");
			return (1);
		}
		n++;
	}
	n = 0;
	while(n < input->philo)
	{
		philo_a[n].number = n;
		if(pthread_create(&(philo_a[n].thread),NULL,&logic,&philo_a[n]))
		{
			printf("creat_tread_problems");
			return (1);
		}
		n++;
		usleep(1);
	}
chek_distroy(philo_a,input);

return(0);
}
