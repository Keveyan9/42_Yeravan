/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:44:55 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/02 15:45:09 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	lensrc ;
	size_t	lendest ;
	size_t	n;

	lensrc = ft_strlen(src);
	lendest = ft_strlen(dst);
	n = 0;
	if (dstsize < lendest)
		return (lensrc + dstsize);
	while (src[n++] && n < dstsize - 1)
		dst[lendest - 1 + n] = src[n];
	dst[n] = '\0';
	return (lendest + lensrc);
}
