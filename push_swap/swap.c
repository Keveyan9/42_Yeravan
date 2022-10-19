/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:55:26 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/17 10:52:51 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_list **swap_argument)
{
	t_list	*temp;

	temp = NULL;
	(*swap_argument)->last->next = (*swap_argument)->next;
	(*swap_argument)->next->last = (*swap_argument)->last;
	(*swap_argument)->last = (*swap_argument)->next;
	(*swap_argument)->next->next->last = *swap_argument;
	temp = (*swap_argument)->next->next;
	(*swap_argument)->next->next = *swap_argument;
	(*swap_argument)->next = temp;
	*swap_argument = (*swap_argument)->last;
}
