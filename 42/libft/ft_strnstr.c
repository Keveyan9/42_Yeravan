/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/10 20:52:24 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	t;

	t = 0;
	if (!*needle)
		return ((char *)haystack);
	while (needle && *haystack && loc)
	{	
		t = 0 ;
		while (needle[t] && needle[t] == *haystack && loc--)
		{
			t++;
			haystack++;
			if (!needle[t])
				return ((char *)haystack - t);
		}		
		haystack++;
		loc--;
	}
	return (NULL);
}
