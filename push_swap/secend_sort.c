/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secend_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:19:40 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/21 00:53:32 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	secend_sort(t_list **stec_a, t_list **stec_b, int *grup_qaunt,int caunt)
{
	t_list *head_a;
	t_list *head_b;
	int grup_n;
	int caunt_n;

	caunt_n = 0;
	grup_n = 0;
	while(caunt  >=  0)
	{
		while(*grup_qaunt > grup_n && caunt >= 0)
		{
			if((*stec_a)->content < (*stec_a)->before->content)
			{
				push(stec_a,stec_b);
				write(1,"pa\n",3);
			}
			else
			{
				*stec_a = (*stec_a)->before;
			   	write(1,"rra\n",1);
				push(stec_a,stec_b);
				write(1,"pa\n",3);
		   	}
				caunt--;
			grup_n++;
		}
		grup_n = 0;
		while(*grup_qaunt > grup_n && caunt >= 0)
		{
			if((*stec_a)->content > (*stec_a)->before->content)
			{
				printf("---%d----",(*stec_a)->content);
				push(stec_a,stec_b);
				write(1,"pl\n",3);
			}
			else
			{
				*stec_a = (*stec_a)->before;
			   	write(1,"rrl\n",1);
				push(stec_a,stec_b);
				write(1,"pl\n",3);
		   	}

			grup_n++;
			caunt--;
		}
		grup_n = 0;
	}
}
