/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekin_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:30:24 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/09 22:59:15 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	chekin_file( char **argv, int argc, t_child *var)
{
	var->i_fd = open (argv[1], O_RDWR);
	var->o_fd = open (argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (var->i_fd < 0)
	{
		perror (argv[1]);
		exit (0);
	}
	if (var->o_fd < 0)
	{
		perror(argv[argc - 1]);
		exit (0);
	}
}
