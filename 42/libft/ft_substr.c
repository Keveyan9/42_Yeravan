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
	size_t	chap;

	chap = 0;
	while (!s && s[start++] && len--)
		chap++;
	new_str = (char *)malloc (chap);
	if (!s || !new_str || ft_strlen(s) < start)
		return (0);
	while (*s && len--)
	{
		new_str[n] = s[start + n];
		n++;
	}
	new_str[n++] = '\0';
	return (new_str);
}
