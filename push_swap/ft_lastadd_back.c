/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:21:05 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/19 23:50:49 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lastadd_back(t_list **lst, t_list *new)
{
	t_list	*before_element;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	before_element = *lst->before;
	before_element->next = new;
	new->before = before_element;
}
