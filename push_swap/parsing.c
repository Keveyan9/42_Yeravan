/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:35:08 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/26 15:02:46 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	parsing(long int *exit_int, int otputs_i, char **s)
{
	int	s_i;

	s_i = 0;
	while (s[s_i] && s_i <= otputs_i)
	{
		if (ft_strlen(s[s_i]) > 11)
		{
			write(1, "is big for int32\n", 16);
			exit(1);
		}
		exit_int[s_i] = ft_atoi(s[s_i]);
		s_i++;
	}
}
