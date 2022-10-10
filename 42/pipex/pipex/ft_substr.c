/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:00:37 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/08 20:06:49 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	n;

	n = 0;
	if (ft_strlen(s) < start)
	{	
		new_str = malloc (sizeof(char));
		new_str[n] = '\0';
		return (new_str);
	}
	while (s[n] && n < len)
		n++;
	new_str = (char *)malloc(n + 1);
	if (!s || !new_str)
		return (0);
		n = 0;
	while (s[start + n] && n < len)
	{
		new_str[n] = s[start + n];
		n++;
	}
	new_str[n++] = '\0';
	return (new_str);
}
