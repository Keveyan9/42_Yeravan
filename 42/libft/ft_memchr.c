/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:07:53 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/07 21:08:15 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sors;

	sors = (unsigned char *)s;
	while (n-- && *sors && *sors != (unsigned char)c)
		sors++;
	if (*sors == (unsigned char)c)
		return (sors);
	return (0);
}
