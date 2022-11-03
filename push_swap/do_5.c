/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:10:38 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/03 22:47:21 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	finish_string_5(t_list **take, t_list **put)
{
	(*put)->before->next = *take;
	(*take)->before = (*put)->before;
	(*put)->before = *take;
	(*take)->next = *put;
	*put = *take;
	*take = NULL;
	write(1, "pa\n", 3);
}


static void qeys_3(int count, t_list **stec_a, t_list **stec_b)
{

		if((*stec_a)->content < (*stec_a)->next->content 
				&& (*stec_a)->next->content > (*stec_a)->before->content)
		{
			swap(stec_a);
		   write(1,"sa\n",3);
		}
		if((*stec_a)->content > (*stec_a)->next->content 
				&& (*stec_a)->content > (*stec_a)->before->content)
		{
			*stec_a = (*stec_a)->next;
		   write(1,"ra\n",3);
		}
	   	if((*stec_a)->content > (*stec_a)->next->content)
		{	
				swap(stec_a);
				write(1,"sa\n",3);
		}		
}
static void qeys_5 ( int count ,t_list **stec_a, t_list **stec_b)
{
	int flag;

	flag = 0;
		ferst_lift_5( stec_a, stec_b, &count);
		if (count  > 3)
		{	
			flag = 1;
			push(stec_a, stec_b);
			write(1,"pb\n",3);
			qeys_3(count, stec_b, stec_a);
		}
			qeys_3(count, stec_a, stec_b);

		while(*stec_b) 
		{   
			if ((*stec_b)-> content < (*stec_a)->content) 
			{	
				if (flag == 1) 
				{
				push(stec_b, stec_a);
				write(1,"pa\n",3);
				flag = 0;
				}
				else
				   finish_string_5(stec_b, stec_a);	
			}	
			else if ((*stec_b)-> content < (*stec_a)->next->content)
			{
				if (flag == 1)
				{
					flag = 0;
					push(stec_b, stec_a);
					write(1,"pa\n",3);
				}
				else
				   finish_string_5(stec_b, stec_a);	
				swap(stec_a);
				write(1,"sa\n",3);	
			
			}
			else if ((*stec_b)-> content < (*stec_a)->next->next->content)
			{
					*stec_a = (*stec_a)->next->next;
					write(1,"ra\nra\n",6);
				if(flag  == 1)
				{
					flag = 0; 
					push(stec_b,stec_a);
					write(1,"pa\n",3);
				}
				else 
					finish_string_5(stec_b,stec_a);

			}	
			else if ((*stec_a)->next->next->next \
					&& (*stec_a)->next->next->next->content > (*stec_b)->content)
			{

				*stec_a = (*stec_a)->before;
				write(1,"rra\n",4);
				if(flag == 1)
				{
					push(stec_b, stec_a);
					write(1,"pa\n",3);
					flag = 0;
				}
				else 
					finish_string_5(stec_b,stec_a);
				*stec_a = (*stec_a)->next->next ;
				write(1,"ra\nra\n",6);
			}
			else
			{
				if (flag == 1)
				{
					push(stec_b,stec_a);
					write(1,"pa\n",3);
					flag =0;
				}
				else
					finish_string_5(stec_b,stec_a);
				*stec_a = (*stec_a)->next;
				write(1,"ra\n",3);
			}
		}
}



void	do_6(int count, t_list **stec_a, t_list **stec_b)
{
	if(count == 3 || count ==2 )
		qeys_3(count, stec_a, stec_b);

	if(count > 3)
		qeys_5(count, stec_a, stec_b);

}
