/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:55:44 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/16 12:39:06 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		write(2, "list_malloc problems\n", 22);
		exit (1);
	}
	new_node->content = content;
	new_node->next = NULL;
	new_node->before = NULL;
	return (new_node);
}
