/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logiq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:29:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/05 18:35:30 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	algoritm_half(int *siqel, t_list **stec_a, t_list **stec_b, char *c)
{
	c[0] = 'b';
	c[1] = 'a';
	c[2] = '0';
	ferst_down(stec_b, stec_a, siqel, c);
	while (*siqel > 0)
	{
		down(stec_b, stec_a, siqel, c);
		lift(stec_b, stec_a, siqel, c);
	}
}

void	algoritm(int count, t_list **stec_a, t_list **stec_b)
{
	int		siqel;
	char	c[3];

	c[2] = '1';
	while (c[2] == '1')
	{
		c[2] = '0';
		siqel = count;
		if (!(*stec_b))
		{			
			c[0] = 'a';
			c[1] = 'b';
			c[2] = '0';
			ferst_down(stec_a, stec_b, &siqel, c);
			while (siqel > 0)
			{
				down(stec_a, stec_b, &siqel, c);
				lift(stec_a, stec_b, &siqel, c);
			}
		}
		siqel = count;
		if (!(*stec_a))
			algoritm_half(&siqel, stec_a, stec_b, c);
	}
}
