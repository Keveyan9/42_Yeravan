/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:49:19 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/21 00:53:30 by skeveyan         ###   ########.fr       */
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
	int grup_qaunt;

	grup_qaunt = 4;
	grup_n = 0;
	flag = 0;
	grup = 0;

	count_a = 0;
	count_b = 0;
	
	ferst_sorting(stec_a);
	while( grup_n <= count)
	{
		printf("$%d$\n",(*stec_a)->content);
		*stec_a = (*stec_a)->next;
		grup_n++;
	}
//	if(count > 1 && count < 4)
	//		speshl_qeys(count,tec_a,stec_b);
	secend_sort(stec_a,stec_b,&grup_qaunt,count );
	grup_qaunt = 8;	
	secend_sort(stec_b,stec_a,&grup_qaunt,count );
	while( grup <= count-1)
	{
		printf("@%d@\n",(*stec_b)->content);
		*stec_b = (*stec_b)->next;
		grup++;
	}
}

