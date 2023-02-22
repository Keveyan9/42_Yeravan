/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:21:07 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/09 23:28:15 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_child	var;

	var.argv_i = 2;
	var.i_fd = 0;
	var.o_fd = 0;
	var.pid1 = 0;
	var.pid2 = 0;
	if (argc == 5)
	{
		chekin_file(argv, argc, &var);
		var.path = faund_path(env);
		pipe(var.pip);
		var.pid1 = fork();
		if (var.pid1 == 0)
			ferst_child (argv[var.argv_i], env, &var);
		var.pid2 = fork();
		if (var.pid2 == 0)
			last_child (argv[++var.argv_i], env, &var);
		close_pip(&var);
		waitpid(var.pid1, NULL, 0);
		waitpid(var.pid2, NULL, 0);
	}
	else
		write(2, "pipex invalid: wrong number of arguments\n", 42);
	return (0);
}
