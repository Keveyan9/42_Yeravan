/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:32:03 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/23 22:41:28 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_list **take_argument, t_list **put_argument)
{
	t_list *head ;

	head = (*take_argument)->next;
	if (*put_argument && *take_argument)
	{
		(*take_argument)->before->next = (*take_argument)->next;
		(*take_argument)->next-> before = (*take_argument)->before;
		(*take_argument)->next = *put_argument;
		(*put_argument)->before-> next = *take_argument;
		(*take_argument)->before = (*put_argument)->before;
		(*put_argument)->before = *take_argument;
		*put_argument = *take_argument;
	}
	else if (*take_argument)
	{
		(*take_argument)->before->next = (*take_argument)->next;
		(*take_argument)-> next -> before = (*take_argument)->before;
		*put_argument = *take_argument;
		(*put_argument)->next = *put_argument;
		(*put_argument)->before = *put_argument;
	}
	*take_argument = head;
}
