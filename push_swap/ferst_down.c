/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferst_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:42 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/25 17:31:03 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ferst_down_efectiv_rb(t_list **take, t_list **put, int *count)
{
	if ((*take)->next->next->content < (*take)->next->content \
			&& (*take)->next->next->content > (*take)->content \
			&& (*take)->next->next->content > (*take)->before->content)
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

void	ferst_down(t_list **take, t_list **put, int *count)
{
	if ((*take)->content > (*take)->next->content \
			&& (*take)->content > (*take)->before->content)
	{
		push(take, put);
		write(1, "pb\n", 3);
	}	
	else if ((*take)->next->content > (*take)->before->content)
		ferst_down_efectiv_rb(take, put, count);
	else
	{
		*take = (*take)->before;
		push(take, put);
		write(1, "rra\npb\n", 7);
	}
	(*count)--;
}
