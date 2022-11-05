/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:10:38 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/05 19:10:27 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	qeys_3( t_list **stec_a)
{
	if ((*stec_a)->content < (*stec_a)->next->content \
			&& (*stec_a)->next->content > (*stec_a)->before->content)
	{
		swap(stec_a);
		write(1, "sa\n", 3);
	}
	if ((*stec_a)->content > (*stec_a)->next->content \
			&& (*stec_a)->content > (*stec_a)->before->content)
	{
		*stec_a = (*stec_a)->next;
		write(1, "ra\n", 3);
	}
	if ((*stec_a)->content > (*stec_a)->next->content)
	{	
		swap(stec_a);
		write(1, "sa\n", 3);
	}		
}

static void	push_or_finish(t_list **stec_a, t_list **stec_b, int *flag )
{
	if (*flag == 1)
	{
		*flag = 0;
		push(stec_b, stec_a);
		write(1, "pa\n", 3);
	}
	else
		finish_string_5(stec_b, stec_a);
}

static void	qeys_5_half(t_list **stec_a, t_list **stec_b, int *flag)
{
	if ((*stec_b)-> content < (*stec_a)->next->next->content)
	{
		*stec_a = (*stec_a)->next->next;
		write(1, "ra\nra\n", 6);
		push_or_finish(stec_a, stec_b, flag);
	}	
	else if ((*stec_a)->next->next->next \
			&& (*stec_a)->next->next->next->content > (*stec_b)->content)
	{
		*stec_a = (*stec_a)->before;
		write(1, "rra\n", 4);
		push_or_finish(stec_a, stec_b, flag);
		*stec_a = (*stec_a)->next->next;
		write(1, "ra\nra\n", 6);
	}
	else
	{
		push_or_finish(stec_a, stec_b, flag);
		*stec_a = (*stec_a)->next;
		write(1, "ra\n", 3);
	}
}

static void	qeys_5(t_list **stec_a, t_list **stec_b, int *flag)
{
	while (*stec_b)
	{
		if ((*stec_b)-> content < (*stec_a)->content)
			push_or_finish(stec_a, stec_b, flag);
		else if ((*stec_b)-> content < (*stec_a)->next->content)
		{
			swap(stec_a);
			push_or_finish(stec_a, stec_b, flag);
			write(1, "sa\n", 3);
		}
		else
			qeys_5_half(stec_a, stec_b, flag);
	}
}

void	do_5(int count, t_list **stec_a, t_list **stec_b)
{
	int	flag;

	flag = 0;
	if (count == 3 || count == 2)
		qeys_3(stec_a);
	if (count > 3)
	{
		ferst_lift_5(stec_a, stec_b, &count);
		if (count > 3)
		{	
			flag = 1;
			push(stec_a, stec_b);
			write(1, "pb\n", 3);
		}
		qeys_3(stec_a);
		qeys_5(stec_a, stec_b, &flag);
	}
}
