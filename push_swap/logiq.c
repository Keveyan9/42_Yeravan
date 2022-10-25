/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logiq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:29:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/25 04:00:58 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algoritm(int count, t_list **stec_a, t_list **stec_b)
{
	int		siqel;
	char	c[3];

	siqel = count;
	c[1] = '1';
//	while(c[1])
//	{
		c[2] = '0';
		siqel = count;
		if (!(*stec_b))
		{
			
				printf("$$$$$$$$$$$o- %d  --$$$$$\n",siqel);
			ferst_down (stec_a, stec_b, &siqel);	
			//while (siqel > 0)
		//	{
				c[0] = 'a';
				c[1] = 'b';
				printf("$$$$$$$$$$$o- %d  --$$$$$\n",siqel);
				down(stec_a,stec_b,&siqel,c);

				lift(stec_a, stec_b,&siqel,c);
				printf("$$$$$$$$$$$o- %d  --$$$$$\n",siqel);
		//	}
		}
	//	siqel = count;	
	//	if(!(*stec_a))
	//	{
	//		ferst_lift_a (stec_b, stec_a,&siqel);	
	//		while (siqel > 0)
	//		{
	//			lift_a(stec_b, stec_a,&siqel);
	//			down_a(stec_b,stec_a,&siqel,&need);
	//		}
	//	}	

//	}


	t_list *head1;
	*stec_a = (*stec_a)->before;
	head1 = *stec_b;

	printf("@@@%d@@@\n",(*stec_b)->content);

do	{	
		//if ((*stec_b)->content > (*stec_a)->next->content)
	//	{	
			printf("$%d$\n",(*stec_b)->content);
	//	}
	//	else
	//		printf("big problem %d\n",(*stec_a)->content);

			*stec_b = (*stec_b)->next;
	}while(head1 != *stec_b );

}
