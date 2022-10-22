/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:49:19 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/23 03:40:01 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void last_lift(t_list **take, t_list**put,int *count )
	{
		if(*count > 1 && ((*take)->content > (*put)->content || (*take)->next->content > (*put)->content))
		{
			if((*take)->content > (*take)->next->content)
			{
				count--;
				push(take,put);
				write(1, "pb\n",3);
			}
			else
			{
				count--;
				*take = (*take)->next;
				push(take,put);
				write(1,"ra\npb\n",6);
			}

			if((*take)->content > (*put)->content)
			{
				count--;
				push(take,put);
				write(1, "pb\n",3);
			}
		}
	}

void lift(t_list **take, t_list **put,int *count)
{
	while(*count > 2 && ((*take)->content > (*put)->content
			|| (*take)->before->content > (*put)->content || (*take)->next->content > (*put)->content ))
	{
		if((*take)->content < (*take)->next->content && (*take)->content < (*take)->before->content)
		{
			push(take,put);
			write(1, "p1b\n",3);
		}	
		else if((*take)->next->content < (*take)->before->content)
		{
			if ((*take)->next->next->content > (*take)->next->content
				   	&& (*take)->next->next->content < (*take)->content 
					&&(*take)->next->next->content < (*take)->before->content)
				{
					*take = (*take)->next;
					push(take,put);
					write(1,"r1a\npb\n",6);
				}
				else 
				{
					swap(take);
					push(take,put);
					write(1,"sa\npb\n",6);
				}
				
		}
		else 
		{
			*take = (*take)->before;
			push(take,put);
			write(1,"rra\npb\n",7);
		}	
	//printf("&&%d&&\n",*count);
	(*count)--;
	}
}


void ferst_lift( t_list **take,t_list **put,int *count)
{
		if((*take)->content < (*take)->next->content && (*take)->content < (*take)->before->content)
		{
			push(take,put);
			write(1, "pb\n",3);
		}	
		else if((*take)->next->content < (*take)->before->content)
		{
			if ((*take)->next->next->content > (*take)->next->content
				   	&& (*take)->next->next->content < (*take)->content 
					&&(*take)->next->next->content < (*take)->before->content)
				{
					*take = (*take)->next;
					push(take,put);
					write(1,"ra\npb\n",6);
				}
				else 
				{
					swap(take);
					push(take,put);
					write(1,"sa\npb\n",6);
				}
			
		}
		else  
		{
			*take = (*take)->before;
			push(take,put);
			write(1,"r1ra\npb\n",7);
		}
	count--;
}
void algoritm (int count, t_list **stec_a, t_list **stec_b)
{
	int need;
	
	need = 2;
	while( need == 2)
	{
		need = 0;
		if(!(*stec_b))
		{
			if(!(*stec_b))
			{
				ferst_lift(stec_a, stec_b,&count);
			}
			lift(stec_a, stec_b,&count);
		}
	}

	while( count--)
	{
		printf("$%d$\n",(*stec_b)->content);
		*stec_b = (*stec_b)->next;
	}
}

