/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:17:44 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/08 20:18:53 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nowstring;
	size_t	n;
	size_t	t;

	n = 0;
	t = 0;
	nowstring = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nowstring)
		return (0);
	while (s1[n])
	{	
		nowstring[n] = s1[n];
		n++;
	}
	while (s2[t])
		nowstring[n++] = s2[t++];
	nowstring[n++] = '\0';
	return (nowstring);
}
