/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:32:03 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/16 23:57:19 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_list **take_argument, t_list **put_argument)
{
	if (*put_argument && *take_argument)
	{
		(*take_argument)->last->next = (*take_argument)->next;
		(*take_argument)->next-> last = (*take_argument)->last;
		(*take_argument)->next = *put_argument;
		(*put_argument)->last-> next = *take_argument;
		(*take_argument)->last = (*put_argument)->last;
		(*put_argument)->last = *take_argument;
	}
	else if (*take_argument)
	{		
		(*take_argument)->last->next = (*take_argument)->next;
		(*take_argument)-> next -> last = (*take_argument)->last;
		*put_argument = *take_argument;
		(*put_argument)->next = *put_argument;
		(*put_argument)->last = *put_argument;
	}
}
