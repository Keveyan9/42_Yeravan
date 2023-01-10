/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:47 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/10 23:26:07 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(long long tm)
{
	long long	time;

	time = get_time();
	while (get_time() - time <= tm - 1)
		usleep (100);
}
