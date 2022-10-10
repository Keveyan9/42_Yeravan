/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekin_comands_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:45:19 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/09 23:00:47 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

char	*chekin_comands_path( char **path, char *comands)
{
	size_t	n;
	char	*path_and_comands;
	char	*comand_and_slesh;

	n = 0;
	comand_and_slesh = ft_strjoin("/", comands);
	while (path[n])
	{
		path_and_comands = ft_strjoin(path[n], comand_and_slesh);
		if (!access(path_and_comands, F_OK & X_OK))
		{
			free (comand_and_slesh);
			return (path_and_comands);
		}
		free (path_and_comands);
			n++;
	}
	free (comand_and_slesh);
	write (2, "commands not found\n", 19);
	exit (0);
}
