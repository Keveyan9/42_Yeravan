/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:53 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/09 16:33:41 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{	
	t_input_argument	input;
	philo_parametr		*philo_a;
	
	input.ok_siqel = -1;	
	input.print_lock = 1;
	input.tred_finish = 1;
	if (argc == 5 || argc == 6)
	{
		if(chek_argument(argv,&input) == 1)
		{
			printf("is litle argument");
			return(0);
		}
		philo_a = (philo_parametr*) malloc(sizeof(philo_parametr) * input.philo);
		input.fork = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t) * input.philo);
		if (creat_philo(philo_a, &input))
			return(0);
//		if(chek_distroy(&pthread))
//			return(0);
//		while(1);

	}
	else
	printf("is litl or more  argumnet");
	return(0);
}
