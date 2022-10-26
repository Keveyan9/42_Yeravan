/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:30:55 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/25 23:43:19 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	finish_string(t_list **take, t_list **put, int *count, char *c)
{
	(*count)--;
	(*put)->before->next = *take;
	(*take)->before = (*put)->before;
	(*put)->before = *take;
	(*take)->next = *put;
	*put = *take;
	*take = NULL;
	write(1, "p", 2);
	write(1, &c[1], 1);
	write(1, "\n", 1);
}
