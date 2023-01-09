/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:02 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/10 02:10:57 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

unsigned int  timer()
{
	struct timeval get_tim;
	gettimeofday(&get_tim, NULL);
	return((get_tim.tv_usec/1000) + get_tim.tv_sec*1000);
}

void *logic(void *arg)
{
	philo_parametr *philos;
	int siqel;
	
	siqel = 0; 
	philos = arg;
	philos->tred_finish_id = 1;
	while(philos->input->tred_finish && (philos->input->ok_siqel == -1
			|| philos->input->ok_siqel > siqel++))
	{		
		take_forks(philos);
		philos->starteat= timer();
		print_s("is eating ",philos);
	//	if(chek_distroy_eats_moment(philos))
	//	{
	//		put_forks(philos);
	//		break;
	///	}
		put_forks(philos);
		philos->startsleep = timer();
		print_s("is sleeping ",philos);
	//	if(chek_distroy_sleep_moment(philos))
	//		break;
		philos->startthink = timer();
		print_s("is thinking ",philos);
	}
	philos->tred_finish_id = 0;
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
	pthread_mutex_init(&input->m_print_lock,NULL);
	n = 0;
	while(n < input->philo)
	{
		philo_a[n].number = n;
		philo_a[n].startsleep = 0;
		if(n % 2 == 0)
		{
	 		if(pthread_create(&(philo_a[n].thread),NULL,&logic,&philo_a[n]))
			{
				printf("creat_tread_problems");
				return (1);
			}
		usleep(10);
		}

		n++;
	}
	n = 0;
	usleep(100);
	while(n < input->philo)
	{
		if(n % 2 !=0 )
		{
			if(pthread_create(&(philo_a[n].thread),NULL,&logic,&philo_a[n]))
			{
				printf("creat_tread_problems");
				return (1);
			}
		usleep(10);
		}
		n++;
	}
	n = 0;


	while(n < input->philo)
	{
		chek_distroy_moment(philo_a[n])

		if(philo_a[n].tred_finish_id == 0)
		{
			input->print_lock = 0;
			input->tred_finish = 0;
			break;
		}
		n++;
		if(n == input->philo)
			n = 0;	
	}

	while(n < input->philo)
		pthread_join(philo_a[n++].thread,NULL);
	return(0);
}
