/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:53 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/11 14:56:52 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{	
	t_input_argument	input;
	t_philo_parametr	*philo_a;

	input.ok_siqel = -1;
	if (argc == 5 || argc == 6)
	{
		if (chek_argument(argv, &input) == 1)
		{
			printf("is not correct input\n");
			return (0);
		}
		philo_a = (t_philo_parametr *) malloc(sizeof (t_philo_parametr) * \
				input.philo);
		input.fork = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * \
				input.philo);
		if (creat_philo(philo_a, &input))
			return (0);
		if (chek_distroy (philo_a, &input))
			return (0);
	}
	else
		printf("is little or more argument");
	return (0);
}
