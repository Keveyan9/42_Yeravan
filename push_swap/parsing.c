/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:35:08 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/11 02:06:51 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	parsing(long	int *exit, int otputs_i, char **s)
{
	int	s_i;

	s_i = 0;
	while (s[s_i] && s_i <= otputs_i)
	{
		exit[s_i] = ft_atoi(s[s_i]);
	s_i++;
	}
}
