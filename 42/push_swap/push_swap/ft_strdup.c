/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:54:22 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/08 19:55:06 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*str;

	n = 0;
	str = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (*s)
		str[n++] = *s++;
	str[n] = '\0';
	return (str);
}
