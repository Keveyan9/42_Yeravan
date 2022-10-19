/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:49:19 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/19 22:53:10 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void algoritm (int count, t_list **stec_a, t_list **stec_b)
{
	int count_a;
	int count_b;
	int grup;
	int grup_n;
	int flag;

	grup_n = 0;
	flag = 0;
	grup = 3;

	count_a = 0;
	count_b = 0;
	if(count > 1 && count < 4)
			speshl_qeys(count,stec_a,stec_b);
// go to b

	while(	)
	{
		if (flag == 0)
		{
			while(grup_n <= grup)
			{
				if ((*stec_a)->content <
			}
		}	
	}



}

