/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:02:50 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/09 22:51:20 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	last_child(char *argv, char **env, t_child *var)
{
	char	**comands;
	char	*chekd_path;
	int		i;

	i = 0;
	comands = ft_split(argv, ' ');
	if (!access(comands[0], F_OK))
	{
		chekd_path = comands[0];
		i = 1;
	}	
	else
		chekd_path = chekin_comands_path(var->path, comands[0]);
	dup2(var->o_fd, 1);
	dup2(var->pip[0], 0);
	close_pip(var);
	execve (chekd_path, comands, env);
	write (2, "last command can`not finshd\n ", 28);
	exit(0);
}
