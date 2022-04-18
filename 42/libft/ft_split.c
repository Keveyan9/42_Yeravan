/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:55:15 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/14 15:55:16 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	need_matric_line(char const *s, char c)
{
	size_t matric_line;
	size_t s_index;

	s_index = 0;
	matric_line = 1;
	if(!s)
		return(0);
	while(s[s_index++])
	{
		while(s[s_index] && s[s_index] == c)
			s_index++;
		if(s[s_index])
			matric_line++;
		while(s[s_index] && s[s_index] != c)
			s_index++;
	}
	return(matric_line);
}
char	**ft_split(char const *s, char c)
{
	size_t s_index;
	size_t cope_size;
	size_t matric_line_t;
	size_t need_matric_line_parametrs;
	char **back;
	
	s_index =0;
	cope_size = 0;
	matric_line_t = 0;
	need_matric_line_parametrs = need_matric_line(s,c);
	back =(char **)(malloc(need_matric_line_parametrs * sizeof(char)));
	if (!back)
		return(0);
	while(s[s_index++] && matric_line_t < need_matric_line_parametrs - 1)
	{
		while(s[s_index] && s[s_index] == c)
			s_index++;
		while(s[s_index] && s[s_index] != c)
		{
			s_index++;
			cope_size++;
		}
		back[matric_line_t++] = ft_substr(s,s_index - cope_size,cope_size);
		cope_size = 0;
		s_index++;
	}
	back[matric_line_t++] = (NULL);
	return(back);
}