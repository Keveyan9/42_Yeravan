/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:51:07 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/05 18:51:27 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	rb_down_efectiv(t_list **take)
{
	if ((*take)->next->next->content < (*take)->next->content)
	{
		if ((*take)->next->next->content > (*take)->content \
				&& (*take)->next->next->content > (*take)->before->content)
			return (1);
	}
	return (0);
}
