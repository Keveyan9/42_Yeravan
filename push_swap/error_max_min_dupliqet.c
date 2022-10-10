/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_max_min_dupliqet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:08:05 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/11 02:31:23 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void error_max_min_dupliqet(long int *data, int count)
{
	int i;
	int i_campair;

	i_campair = 0;
	i = 0;
	while (i < count)
	{
		printf("_%d- ",count);
		printf("%ld\n ",data[i]);
		if (data[i] > INT_MAX || data[i] < INT_MIN)
		{
			write(1,"input number non corect max and min\n",36);
			exit(0);
		}
		i_campair = i + 1;
		while (i_campair < count)
		{
			if (data[i] == data[i_campair])
			{
				write(1,"dubliqet number error\n",22);
				exit(0);
			}
			i_campair++;
		}
		i++;
	}
}
