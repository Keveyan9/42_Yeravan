/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:53 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/31 15:40:11 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{	
	t_input_argument	input;
	t_pthread_argument	pthread;
	
	input.ok_time = 0;
	if (argc == 5 || argc == 6)
	{
		if(chek_argument(argv,&input) == 1)
		{
			printf("isargument");
			return(0);
		}
		if (creat_philo(&input,&pthread))
			return(0);
//		if(chek_distroy(&pthread))
//			return(0);
	}
	else
		printf("is littl or more  argumnet");
	return(0);
}

