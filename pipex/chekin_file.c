/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekin_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:30:24 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/08 19:38:18 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	chekin_file(char **fp, int argc, int *i_fd, int *o_fd )
{
	*i_fd = open (fp[1], O_RDWR);
	if (*i_fd < 0)
	{
		perror ("not  input file ");
		exit (0);
	}
	*o_fd = open (fp[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*o_fd < 0)
	{
		perror ("out file error");
		exit (0);
	}
}
