/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:10:07 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/08 20:11:14 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**ft_split( char const *s, char c)
{
	char	**back;
	size_t	s_index;
	size_t	row_maloc;
	size_t	row_index;

	s_index = 0;
	row_maloc = 0;
	row_index = 0;
	back = (char **)malloc ((need_row(s, c) + 1) * sizeof(char *));
	if (!s && !back)
		return (0);
	back[need_row(s, c)] = NULL;
	while (row_index < need_row(s, c))
	{
		while (s[s_index] && s[s_index] == c)
			s_index++;
		while (s[s_index] && s[s_index] != c && ++row_maloc)
			s_index++;
		back[row_index++] = ft_substr(s, (s_index - row_maloc), row_maloc);
		s_index++;
		row_maloc = 0;
	}
	return (back);
}
