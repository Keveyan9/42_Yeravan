/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_row.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:11:48 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/10 20:36:49 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

size_t	need_row(const char *s, char c )
{
	size_t	row ;
	char	flag;

	flag = 0;
	row = 0;
	while (*s)
	{
		if (*s != c && flag++ == 0)
			row++;
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (row);
}
