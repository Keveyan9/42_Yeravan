/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:52:41 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/09 21:53:08 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp( const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	if (n == 0)
		return (0);
	while (--n && *ptr1 == *ptr2 && ++ptr1)
		++ptr2;
	return (*ptr2 - *ptr1);
}