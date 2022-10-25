/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:48:23 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/25 17:33:10 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	last_down(t_list **take, t_list **put, int *count, char *c)
{
	if (*count > 1 && ((*take)->content < (*put)->content
			|| (*take)->next->content < (*put)->content))
	{
		if ((*take)->content > (*take)->next->content)
		{
			(*count)--;
			push(take, put);
			write(1, "p", 1);
			write(1, &c[1], 1);
			write(1, "\n", 1);
		}
		else
		{
			(*count)--;
			*take = (*take)->next;
			push(take, put);
			write(1, "r", 1);
			write(1, &c[0], 1);
			write(1, "\np", 2);
			write(1, &c[1], 1);
			write(1, "\n", 1);
		}
	}
	if (*take && (*take)->content < (*put)->content)
		finish_string(take, put, count, c);
}

int	siqel_down_valid(t_list **take, t_list **put, int*count)
{	
	if (*count > 2)
	{
		if ((*take)->content < (*put)->content)
			return (1);
		else if ((*take)->before->content < (*put)->content)
			return (1);
		else if ((*take)->next->content < (*put)->content)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	down_valid_ferst(t_list **take, t_list **put )
{
	if ((*take)->content < (*put)->content)
	{
		if (((*take)->next->content < (*put)->content) \
				&& (*take)->next->content > (*take)->content)
			return (0);
		else if ((*take)->before->content < (*put)->content \
					&& (*take)->before->content > (*take)->content)
			return (0);
		else
			return (1);
	}
	return (0);
}

int	down_valid_secend(t_list **take, t_list **put)
{
	if ((*take)->next->content < (*put)->content)
	{
		if ((*take)->next->content < (*take)->before->content \
				&& ((*take)->before->content < (*put)->content))
			return (0);
		else
			return (1);
	}
	return (0);
}

int	rb_down_efectiv(t_list **take, t_list **put)
{
	if ((*take)->next->next->content < (*take)->next->content)
	{
		if ((*take)->next->next->content > (*take)->content \
				&& (*take)->next->next->content > (*take)->before->content)
			return (1);
	}
	return (0);
}
