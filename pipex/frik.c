/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frik.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:48:24 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/08 19:51:18 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	frik(char **s1)
{	
	int	i;

	i = 0;
	if (s1)
	{
		while (s1[i])
			free (s1[i++]);
		free (s1);
	}
}