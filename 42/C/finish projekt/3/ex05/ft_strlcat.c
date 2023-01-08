/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:30:35 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/22 23:12:03 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//sxal er

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_lenct;
	unsigned int	dest_lenct;
	unsigned int	n;

	n = 0;
	src_lenct = 0;
	dest_lenct = 0;
	while (src[src_lenct])
		src_lenct++;
	while (dest[dest_lenct])
		dest_lenct++;
	if (size < 1 || size < dest_lenct)
		return (size + src_lenct);
	while (src[n] && dest_lenct < size - 1)
	{
		dest[dest_lenct++] = src[n];
		n++;
	}
	dest[dest_lenct] = '\0';
	return (dest_lenct + src_lenct);
}
