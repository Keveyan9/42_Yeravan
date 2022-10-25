/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:45:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/25 03:50:08 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	put_secend_r(char *c)
{
	write(1, "\nr", 2);
	write(1, &c[0], 1);
	write(1, "\np", 2);
	write(1, &c[1], 1);
}

static void	put_secend_rr(char *c)
{
	write(1, "\ns", 2);
	write(1, &c[0], 1);
	write(1, "\np", 2);
	write(1, &c[1], 1);
}

static void	put_last(char *c)
{
	write (1, "\nrr", 3);
	write (1, &c[0], 1);
	write (1, "\np", 2);
	write (1, &c[1], 1);
}

static void	efection_secend_push(t_list **take, t_list **put, char *c)
{
	if (rb_down_efectiv(take, put))
	{
		*take = (*take)->next;
		push(take, put);
		put_secend_r(c);
	}
	else
	{
		swap (take);
		push (take, put);
		put_secend_rr(c);
	}	
}

void	down(t_list **take, t_list **put, int *count, char *c)
{
	while (siqel_down_valid(take, put, count))
	{
		if (down_valid_ferst(take, put))
		{
			push(take, put);
			write(1, "\np", 2);
			write(1, &c[1], 1);
		}	
		else if (down_valid_secend(take, put))
			efection_secend_push(take, put, c);
		else
		{
			*take = (*take)->before;
			push(take, put);
			put_last(c);
		}
		(*count)--;
	}
	last_down(take, put, count, c);
}
