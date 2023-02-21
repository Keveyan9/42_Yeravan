/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pour.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:15:48 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/20 02:02:19 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pour(long int *input, int int_aray_len, t_list **pour_stec)
{
	int		n;
	t_list	*head;

	n = 0;
	*pour_stec = ft_lstnew(input[n]);
	head = *pour_stec;
	while (n < int_aray_len - 1)
		ft_beforeadd_back(pour_stec, ft_lstnew(input[++n]));
}
