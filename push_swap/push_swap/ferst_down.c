/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferst_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:42 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/04 18:20:50 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	efectiv_rb(t_list **take, t_list **put, char *c)
{
	if ((*take)->next->next->content < (*take)->next->content \
			&& (*take)->next->next->content > (*take)->content \
			&& (*take)->next->next->content > (*take)->before->content)
	{
		*take = (*take)->next;
		push(take, put);
		write(1, "r", 1);
		write(1, &c[0], 1);
		write(1, "\np", 2);
		write(1, &c[1], 1);
		write(1, "\n", 1);
	}
	else
	{
		swap(take);
		push(take, put);
		write(1, "s", 1);
		write(1, &c[0], 1);
		write(1, "\np", 2);
		write(1, &c[1], 1);
		write(1, "\n", 1);
	}
}	

void	ferst_down(t_list **take, t_list **put, int *count, char *c)
{
	if ((*take)->content > (*take)->next->content \
			&& (*take)->content > (*take)->before->content)
	{
		push(take, put);
		write(1, "p", 1);
		write(1, &c[1], 1);
		write(1, "\n", 1);
	}	
	else if ((*take)->next->content > (*take)->before->content)
		efectiv_rb(take, put, c);
	else
	{
		*take = (*take)->before;
		push(take, put);
		write(1, "rr", 2);
		write(1, &c[0], 1);
		write(1, "\np", 2);
		write(1, &c[1], 1);
		write(1, "\n", 1);
	}
	(*count)--;
}
