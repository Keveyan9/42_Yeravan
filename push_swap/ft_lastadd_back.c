/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:21:05 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/12 19:34:01 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lastadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
 	last_element = ft_lstlast(*lst);
	last_element->next = new;
}
