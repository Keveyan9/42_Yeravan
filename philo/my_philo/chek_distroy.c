/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_distroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:14:33 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/09 01:33:51 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"


void *chek(void *arg)
{

	philo_parametr *philo_a;
	int n;
	
	n = 0;
	philo_a = arg;
	while(1)
	{
		if(philo_a[n].startsleep > 0)
		{
			//if(timer() - philo_a[n].startsleep > philo_a[n].input->die)
//			break;
		}
		n++;
		if(n == philo_a[n].input->philo)
			n = 0;
	}
	return(NULL);
}

void chek_distroy(philo_parametr *philo_a, t_input_argument *input)
{
	pthread_t chek_thred;

	if(pthread_create(&chek_thred,NULL,&chek,philo_a))
	{
		printf("chek tread error\n");
	}
	pthread_join(chek_thred,NULL);
}
