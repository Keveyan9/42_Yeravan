/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferst_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:42 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/04 18:21:50 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ferst_lift_efectiv_rb(t_list **take, t_list **put)
{
	if ((*take)->next->next->content > (*take)->next->content \
			&& (*take)->next->next->content < (*take)->content \
			&& (*take)->next->next->content < (*take)->before->content)
	{
		*take = (*take)->next;
		push(take, put);
		write(1, "ra\npb\n", 6);
	}
	else
	{
		swap(take);
		push(take, put);
		write(1, "sa\npb\n", 6);
	}
}	

void	ferst_lift_5(t_list **take, t_list **put, int *count)
{
	if ((*take)->content < (*take)->next->content \
			&& (*take)->content < (*take)->before->content)
	{
		push(take, put);
		write(1, "pb\n", 3);
	}	
	else if ((*take)->next->content < (*take)->before->content)
		ferst_lift_efectiv_rb(take, put);
	else
	{
		*take = (*take)->before;
		push(take, put);
		write(1, "rra\npb\n", 7);
	}
	(*count)--;
}
