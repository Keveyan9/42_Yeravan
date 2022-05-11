/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:30:36 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/12 15:30:55 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	n;

	n = 0;
	if (!s || !(new_str = (char *)malloc(len + 1)))
		return (0);
	if (ft_strlen(s) < start)
	{	new_str[n] = '\0';
		return(new_str);
	}
	while (s[start + n] && n < len)
	{
		new_str[n] = s[start + n];
		n++;
	}
	new_str[n++] = '\0';
	return (new_str);
}