/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:45:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/25 17:37:07 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	put_secend_r(char *c)
{
	write(1, "r", 1);
	write(1, &c[0], 1);
	write(1, "\np", 2);
	write(1, &c[1], 1);
	write(1, "\n", 1);
}

static void	put_secend_rr(char *c)
{
	write(1, "s", 1);
	write(1, &c[0], 1);
	write(1, "\np", 2);
	write(1, &c[1], 1);
	write(1, "\n", 1);
}

static void	put_last(char *c)
{
	write (1, "rr", 2);
	write (1, &c[0], 1);
	write (1, "\np", 2);
	write (1, &c[1], 1);
	write(1, "\n", 1);
}

static void	efection_secend_push(t_list **take, t_list **put, char *c)
{
	if (rb_lift_efectiv(take, put))
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

void	lift(t_list **take, t_list **put, int *count, char *c)
{
	while (siqel_lift_valid(take, put, count))
	{
		
		c[2] = '1';
		if (lift_valid_ferst(take, put))
		{
			push(take, put);
			write(1, "p", 1);
			write(1, &c[1], 1);
			write(1, "\n", 1);
		}	
		else if (lift_valid_secend(take, put))
			efection_secend_push(take, put, c);
		else
		{			*take = (*take)->before;
			push(take, put);
			put_last(c);
		}
		(*count)--;
	}
	last_lift(take, put, count, c);
}
