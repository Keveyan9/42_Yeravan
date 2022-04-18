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

char	*ft_itoa(int n)
{
	size_t	calemb;
	char	*back;
	int	n1;

	n1 = n;
	calemb = 0;
	while (n1 > 9)
	{
		n1 = n1 / 10;
		calemb++;
	}
	back =(char *)malloc(calemb + 2);
		if(!back)
			return(NULL);
	back[calemb + 1] = '\0';
	while (n > 10)
	{ 
		back[calemb--] = '0' + n % 10;
		n = n/10;
	}
	back[calemb] = '0' + n;
	return(back);
}