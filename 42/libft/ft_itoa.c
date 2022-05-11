/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:55:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/14 15:55:46 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void calem(long int *n1,size_t *calemb)
	{
		while (*n1 > 9 )
		{
			*n1 /= 10;
			(*calemb)++;
		}
	}

char	*ft_itoa(int n)
{
	size_t	calemb;
	char	*back;
	long int	n1;

	calemb = 0;
	if (n < 0 && !calemb++)
		n = -n;
	n1 = n;
	calem(&n1,&calemb);
	back =(char *)malloc(calemb + 2);
		if(!back)
			return(NULL);
	back[calemb + 1] = '\0';
	while (n > 10)
	{ 
		back[calemb--] = '0' + n % 10;
		n = n/10;
	}
	back[calemb--] = '0' + n;
	if(calemb == 0)
		back[calemb] = '-';
	return(back);
}