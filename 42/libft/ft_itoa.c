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

void	calem(long int n2, size_t *calemb )
{
	while (n2 > 9)
	{
		n2 /= 10;
		(*calemb)++;
	}
}

char	*ft_itoa(int n)
{
	size_t		calemb;
	char		*back;
	long int	n1;

	calemb = 1;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		calemb++;
	}
	calem (n1, &calemb);
	back = (char *)malloc(calemb + 1);
	if (!back)
		return (NULL);
	back[calemb] = '\0';
	while (n1 > 10 && calemb)
	{
		back[--calemb] = '0' + n1 % 10;
		n1 = n1 / 10;
	}
	back[--calemb] = '0' + n1;
	if (--calemb == 0)
		back[calemb] = '-';
	return (back);
}
