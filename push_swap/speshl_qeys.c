/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speshl_qeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:43:20 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/17 13:29:30 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	speshl_qeys(int count, t_list **stec_a, t_list **stec_b)
{
	if (count == 2)
	{
		if ((*stec_a)-> content > (*stec_a)->next->content)
		{	
			swap(stec_a);
			write(1, "sa\n", 3);
		}
	}
	else if ( count == 3)
	{
		if ((*stec_a)->content > (*stec_a)->next->content  &&
			   	(*stec_a)->content > (*stec_a)->before->content)
			{
				*stec_a = (*stec_a)->next;
				write(1, "ra\n", 3);
			}

		if ((*stec_a)-> content > (*stec_a)->next->content)
		{	
			swap(stec_a);
			write(1, "sa\n", 3);
		}

	}
}
