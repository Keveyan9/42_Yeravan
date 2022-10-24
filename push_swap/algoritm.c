/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:49:19 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/24 03:57:43 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void last_down_a(t_list **take, t_list**put,int *count,int *need )
	{
		t_list *head;

		if(*count > 1 && ((*take)->content <  (*put)->content || (*take)->next->content < (*put)->content))
		{
			*need = 2;
			if((*take)->content > (*take)->next->content)
			{
				(*count)--;
				push(take,put);
				write(1, "pa\n",3);
			}
			else
			{
				(*count)--;
				*take = (*take)->next;
				push(take,put);
				write(1,"rb\npa\n",6);
			}
		}
			if( *take  && (*take)->content < (*put)->content)
			{
				*need = 2;
				(*count)--;
				head = *put;
				(*put) -> before->next = *take;
				(*take) -> before = (*put)->before;
				(*put)->before  = *take;
				(*take)->next = *put;
				*put = *take;
				*take = NULL;
				write(1, "pa\n",3);
			}
		}

void down_a(t_list **take, t_list **put,int *count , int *need)
{
	int n;
	int t = 0;

	n = *count;
	while(*count > 2 && ((*take)->content < (*put)->content
			|| (*take)->before->content < (*put)->content || (*take)->next->content < (*put)->content ))
	{
		*need = 2;
		if(((*take)->content < (*put)->content) && (!(((*take)->next->content < (*put)->content) && (*take)->next->content > (*take)->content) 
					&& !((*take)->before->content < (*put)->content && (*take)->before->content > (*take)->content))) 
		{
			push(take,put);
			write(1, "pa\n",3);
		}	
		else if(((*take)->next->content < (*put)->content) && !(((*take)->next->content < (*take)->before->content) 
				  	&& ((*take)->before->content < (*put)->content)))
		{
			if ((*take)->next->next->content < (*take)->next->content
				   	&& (*take)->next->next->content > (*take)->content 
					&&(*take)->next->next->content > (*take)->before->content )
				{
					*take = (*take)->next;
					push(take,put);
					write(1,"rb\npa\n",6);
				}
				else 
				{
					swap(take);
					push(take,put);
					write(1,"sb\npa\n",6);
				}	
		}
		else 
		{
			*take = (*take)->before;
			push(take,put);
			write(1,"rrb\npa\n",7);
		}
		(*count)--;
	}
	last_down_a(take,put,count,need);
}

void last_lift_a(t_list **take, t_list**put,int *count )
	{
		t_list *head;

		if(*count > 1 && ((*take)->content > (*put)->content || (*take)->next->content > (*put)->content))
		{
			if((*take)->content < (*take)->next->content)
			{
				(*count)--;
				push(take,put);
				write(1, "pa\n",3);
			}
			else
			{
				(*count)--;
				*take = (*take)->next;
				push(take,put);
				write(1,"rb\npa\n",6);
			}
		}
			if( *take && (*take)->content > (*put)->content)
			{

				(*count)--;
				head = *put;
				(*put) -> before->next = *take;
				(*take) -> before = (*put)->before;
				(*put)->before  = *take;
				(*take)->next = *put;
				*put = *take;
				*take = NULL;
				write(1, "pa\n",3);
			}
		}

void lift_a(t_list **take, t_list **put,int *count)
{
	int n;
	int t = 0;

	n = *count;
	while(*count > 2 && ((*take)->content > (*put)->content
			|| (*take)->before->content > (*put)->content || (*take)->next->content > (*put)->content ))
	{
		if(((*take)->content > (*put)->content) && (!(((*take)->next->content > (*put)->content) && (*take)->next->content < (*take)->content) 
					&& !((*take)->before->content > (*put)->content && (*take)->before->content < (*take)->content))) 
		{
			push(take,put);
			write(1, "pa\n",3);
		}	
		else if(((*take)->next->content > (*put)->content) && !(((*take)->next->content > (*take)->before->content) 
				  	&& ((*take)->before->content > (*put)->content)))
		{
			if ((*take)->next->next->content > (*take)->next->content
				   	&& (*take)->next->next->content < (*take)->content 
					&&(*take)->next->next->content < (*take)->before->content )
				{
					*take = (*take)->next;
					push(take,put);
					write(1,"rb\npa\n",6);
				}
				else 
				{
					swap(take);
					push(take,put);
					write(1,"sb\npa\n",6);
				}	
		}
		else 
		{
			*take = (*take)->before;
			push(take,put);
			write(1,"rrb\npa\n",7);
		}
		(*count)--;
	}
	last_lift_a(take,put,count);
}

void ferst_lift_a( t_list **take,t_list **put,int *count)
{
		if((*take)->content < (*take)->next->content && (*take)->content < (*take)->before->content)
		{
			push(take,put);
			write(1, "pa\n",3);
		}	
		else if((*take)->next->content < (*take)->before->content)
		{
			if ((*take)->next->next->content > (*take)->next->content
				   	&& (*take)->next->next->content < (*take)->content 
					&&(*take)->next->next->content < (*take)->before->content)
				{
					*take = (*take)->next;
					push(take,put);
					write(1,"rb\npa\n",6);
				}
				else 
				{
					swap(take);
					push(take,put);
					write(1,"sb\npa\n",6);
				}	
		}
		else  
		{
			*take = (*take)->before;
			push(take,put);
			write(1,"rrb\npa\n",7);
		}
	(*count)--;
}

void last_down_b(t_list **take, t_list**put,int *count )
	{
		t_list *head;

		if(*count > 1 && ((*take)->content <  (*put)->content || (*take)->next->content < (*put)->content))
		{
			if((*take)->content > (*take)->next->content)
			{
				(*count)--;
				push(take,put);
				write(1, "pb\n",3);
			}
			else
			{
				(*count)--;
				*take = (*take)->next;
				push(take,put);
				write(1,"ra\npb\n",6);
			}
		}
			if(*take && (*take)->content < (*put)->content)
			{
				(*count)--;
				head = *put;
				(*put) -> before->next = *take;
				(*take) -> before = (*put)->before;
				(*put)->before  = *take;
				(*take)->next = *put;
				*put = *take;
				*take = NULL;
				write(1, "pb\n",3);
			}
		}

void down_b(t_list **take, t_list **put,int *count)
{
	int n;
	int t = 0;

	n = *count;
	while(*count > 2 && ((*take)->content < (*put)->content
			|| (*take)->before->content < (*put)->content || (*take)->next->content < (*put)->content ))
	{
		if(((*take)->content < (*put)->content) && (!(((*take)->next->content < (*put)->content) && (*take)->next->content > (*take)->content) 
					&& !((*take)->before->content < (*put)->content && (*take)->before->content > (*take)->content))) 
		{
			push(take,put);
			write(1, "pb\n",3);
		}	
		else if(((*take)->next->content < (*put)->content) && !(((*take)->next->content < (*take)->before->content) 
				  	&& ((*take)->before->content < (*put)->content)))
		{
			if ((*take)->next->next->content < (*take)->next->content
				   	&& (*take)->next->next->content > (*take)->content 
					&&(*take)->next->next->content > (*take)->before->content )
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
			write(1,"rra\npb\n",7);
		}
		(*count)--;
	}
	last_down_b(take,put,count);
}

void last_lift_b(t_list **take, t_list**put,int *count )
	{
		t_list *head;

		if(*count > 1 && ((*take)->content > (*put)->content || (*take)->next->content > (*put)->content))
		{
			if((*take)->content < (*take)->next->content)
			{
				(*count)--;
				push(take,put);
				write(1, "pb\n",3);
			}
			else
			{
				(*count)--;
				*take = (*take)->next;
				push(take,put);
				write(1,"ra\npb\n",6);
			}
		}
			if(*take && (*take)->content > (*put)->content)
			{

				(*count)--;
				head = *put;
				(*put) -> before->next = *take;
				(*take) -> before = (*put)->before;
				(*put)->before  = *take;
				(*take)->next = *put;
				*put = *take;
				*take = NULL;
				write(1, "pb\n",3);
			}
		}

void lift_b(t_list **take, t_list **put,int *count)
{
	int n;
	int t = 0;

	n = *count;
	while(*count > 2 && ((*take)->content > (*put)->content
			|| (*take)->before->content > (*put)->content || (*take)->next->content > (*put)->content ))
	{
		if(((*take)->content > (*put)->content) && (!(((*take)->next->content > (*put)->content) && (*take)->next->content < (*take)->content) 
					&& !((*take)->before->content > (*put)->content && (*take)->before->content < (*take)->content))) 
		{
			push(take,put);
			write(1, "pb\n",3);
		}	
		else if(((*take)->next->content > (*put)->content) && !(((*take)->next->content > (*take)->before->content) 
				  	&& ((*take)->before->content > (*put)->content)))
		{
			if ((*take)->next->next->content > (*take)->next->content
				   	&& (*take)->next->next->content < (*take)->content 
					&&(*take)->next->next->content < (*take)->before->content )
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
			write(1,"rra\npb\n",7);
		}
		(*count)--;
	}
	last_lift_b(take,put,count);
}

void ferst_lift_b( t_list **take,t_list **put,int *count)
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
					write(1,"r3\npb\n",6);
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
	(*count)--;
}

void algoritm (int count, t_list **stec_a, t_list **stec_b)
{
	int need;
	
	need = 2;
	int whil_n;
	int siqel;
	
	whil_n = count;

	while( need == 2)
	{
		need = 0;
		siqel = count;
		if(!(*stec_b))
		{
			ferst_lift_b(stec_a, stec_b,&siqel);
			
			while (siqel > 0)
			{
				lift_b(stec_a, stec_b,&siqel);
				down_b(stec_a,stec_b,&siqel);
			}
		}
		siqel = count;	
		if(!(*stec_a))
		{
			ferst_lift_a (stec_b, stec_a,&siqel);	
			while (siqel > 0)
			{
				lift_a(stec_b, stec_a,&siqel);
				down_a(stec_b,stec_a,&siqel,&need);
			}
		}	

}
t_list *head1;
	*stec_a = (*stec_a)->before;
	head1 = *stec_a;
	printf("@@@%d@@@\n",(*stec_a)->content);
do	{	
		if ((*stec_a)->content > (*stec_a)->next->content)
		{	
			printf("$%d$\n",(*stec_a)->content);
		}
		else
			printf("big problem %d\n",(*stec_a)->content);

			*stec_a = (*stec_a)->next;
	}while(head1 != *stec_a );

//	while( whil_n--)
//	{
//		printf("&&&$%d$\n",(*stec_a)->content);
//		*stec_a = (*stec_a)->next;
//	}
}

