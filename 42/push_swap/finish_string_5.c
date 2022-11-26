/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_string_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:09:57 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/05 19:10:13 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	finish_string_5(t_list **take, t_list **put)
{
	(*put)->before->next = *take;
	(*take)->before = (*put)->before;
	(*put)->before = *take;
	(*take)->next = *put;
	*put = *take;
	*take = NULL;
	write(1, "pa\n", 3);
}
