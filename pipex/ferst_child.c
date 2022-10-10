/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferst_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:39:32 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/09 22:57:16 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ferst_child(char *argv, char **env, t_child *var)
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
	dup2(var->i_fd, 0);
	dup2(var->pip[1], 1);
	close_pip(var);
	execve(chekd_path, comands + i, env);
	write(2, "comand can`not finshd\n", 22);
	exit(0);
}
