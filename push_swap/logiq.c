/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logiq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:29:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/03 01:20:28 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algoritm(int count, t_list **stec_a, t_list **stec_b)
{
	int		siqel;
	char	c[3];

	siqel = count;
	c[2] = '1';
	while(c[2] == '1' )
	{
		c[2] = '0';
		siqel = count;
		if (!(*stec_b))
		{			
			c[0] = 'a';
			c[1] = 'b';
			c[2] = '0';
			ferst_down (stec_a, stec_b, &siqel,c);	
			while (siqel > 0)
			{
				down(stec_a, stec_b, &siqel, c);
				lift(stec_a, stec_b,&siqel,c);
			}
		}
		siqel = count;	
		if(!(*stec_a))
		{
			c[0] = 'b';
			c[1] = 'a';
			c[2] = '0';
			ferst_down (stec_b, stec_a, &siqel, c);	
			while (siqel >  0)
			{
				down(stec_b, stec_a, &siqel, c);
				lift(stec_b, stec_a, &siqel, c);
			}
		}
	}
	t_list *head1;
	head1 = *stec_a;
//	printf("@@@%d@@@\n",(*stec_b)->content);

//do	{	
		//if ((*stec_b)->content > (*stec_a)->next->content)
	//	{	
		//	printf("$%d$\n",(*stec_a)->content);
	//	}
	//	else
	//		printf("big problem %d\n",(*stec_a)->content);

//			*stec_a = (*stec_a)->next;
//	}while(head1 != *stec_a);
}
