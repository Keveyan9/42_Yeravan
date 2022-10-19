/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferst_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:18:41 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/19 22:53:10 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ferst_sorting(int *flag, int count; t_list	**stec_a)
{
	int count_n;
	while(count_n < = count)
	{
		if(flag == 0)
		{	
			if((*stec_a)->content > (*stec_a)->next->content)
			{
				swap(stec_a);
				write(1,"sa\n",3);
			}
			*stec_a = (*stec_a)->last
		}

	}
}

