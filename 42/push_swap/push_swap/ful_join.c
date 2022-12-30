/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ful_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:04:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/02 21:21:22 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

char	*ful_join(char **argv)
{
	char	*box;
	char	*box2;
	char	*box_prabels;
	int		argv_i;

	argv_i = 1;
	box = argv[argv_i];
	if (argv[argv_i + 1])
	{
		argv_i++;
		while (argv[argv_i])
		{
			box_prabels = ft_strjoin (" ", argv[argv_i]);
			box2 = ft_strjoin(box, box_prabels);
			if (argv_i > 2)
				free(box);
			box = ft_strdup(box2);
			free(box_prabels);
			free(box2);
			argv_i++;
		}
	}
	return (box);
}
