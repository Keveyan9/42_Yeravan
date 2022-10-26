/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:10:38 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/26 16:07:11 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	min_lift(t_list **stec_a, t_list  **stec_b, int *count)
{

}

void	do_5(int count, t_list **stec_a, t_list **stec_b)
{
	while (count > 3 )
	{
		min_lift(stec_a, stec_b,&count);
	}
		printf("%d\n",(*stec_a)->content); 
	printf("%d\n",(*stec_a)->next->content); 
}


