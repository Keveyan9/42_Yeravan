/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:21:05 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/20 01:59:35 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_beforeadd_back(t_list **lst, t_list *new)
{
	t_list	*before_element;

	if (!*lst)
	{
		*lst = new;
		return ;
	}

	if((*lst)->before) 
	{
		(*lst)->before->next = new;
		(*lst)->before->next->next = *lst;	
		(*lst)->before->next->before = (*lst)->before;
		(*lst)->before = new;
	}
		else
	{
		(*lst)->next = new;
		(*lst)->next->next = *lst;
		(*lst)->before = new;
		(*lst)->before->before = *lst;
	}

}
