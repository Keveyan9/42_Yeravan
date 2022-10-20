/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferst_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:18:41 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/20 16:43:19 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ferst_sorting(t_list **stec_a)
{
	t_list	*head;
	int flag_duing;
	int flag_position;
	int flag_ra;	
	
	flag_position = 0;
	flag_ra = 0;
	flag_duing = 0;

	head = *stec_a;
	while(((*stec_a)->next->next != head) && ((*stec_a)->next->next->next != head))
	{	
		flag_ra = 1;
		flag_duing = 0;
		if(flag_position == 0 && flag_duing == 0)
		{	
			if(((*stec_a)->content > (*stec_a)->next->content) && (*stec_a)->next != head )
			{
				swap(stec_a);
				write(1, "sa\n", 3);
				flag_ra = 0;
				*stec_a = (*stec_a)->next;
				write(1, "r1a\n", 4);
			}
			flag_duing = 1;
			flag_position = 1;
		}
		if(flag_position == 1 && flag_duing == 0)
		{	
			if(((*stec_a)->content < (*stec_a)->next->content) && (*stec_a)->next != head )
			{
				swap(stec_a);
				write(1, "sa\n", 3);
				flag_ra = 0;
				*stec_a = (*stec_a)->next;
				write(1, "r2a\n", 4);
			}
			flag_duing = 1;
			flag_position = 0;
		}
			if(flag_ra == 0)	
			{
				*stec_a = (*stec_a)->next;
				write(1, "r3a\n",  4);
			}
			else
			{
				*stec_a = (*stec_a)->next->next;
				write(1,"ra\nra\n",6);
			} 
	}

			printf(	"&&%d&&",(*stec_a)->content);

			if(((*stec_a)->content < (*stec_a)->next->content) && (*stec_a)->next != head )
			{
				swap(stec_a);
				write(1, "s2\n", 3);
				flag_ra = 0;
				*stec_a = (*stec_a)->next;
				write(1, "r2a\n", 4);
			}

			if(flag_ra == 0)	
			{
				*stec_a = (*stec_a)->next;
				write(1, "r3a\n",  4);
			}
			else
			{
				*stec_a = (*stec_a)->next->next;
				write(1,"r4\nr4\n",6);
			}
			if((*stec_a) != head)
			{
				*stec_a = (*stec_a)->next;
				write(1, "r5a\n",  4);
			}

}
