/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidavtya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:44:54 by tidavtya          #+#    #+#             */
/*   Updated: 2022/02/20 18:28:53 by tidavtya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_parsed_dict[41][12];

void	put_word(char *str)
{
	char	t;
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		t = str[i];
		write(1, &t, 1);
	}
	write(1, " ", 1);
}

void	put_ex(int max_num, char triplet[3])
{
	if (max_num != 0)
	{
		if (!(triplet[0] == '0' && triplet[1] == '0' && triplet[2] == '0' ))
			put_word (g_parsed_dict[28 + max_num]);
	}
}
