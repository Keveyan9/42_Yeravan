/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:05:34 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/11 02:45:26 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv )
{
	t_main	var;

	if (argc > 3)
	{
		var.input_ful = ful_join(argv);
		var.input_cuts = ft_split(var.input_ful, ' ');
		var.wstrlen = ft_2strlen(var.input_cuts);
		var.input_s = (long int *) malloc(var.wstrlen * sizeof(long int));
		parsing(var.input_s, var.wstrlen, var.input_cuts);
		error_max_min_dupliqet(var.input_s, var.wstrlen);

		int n = 0;
		while (var.input_cuts[n])
		{
			printf("## %ld ##", var.input_s[n]);
			printf(" %s\n ", var.input_cuts[n++]);
		}
	}
	write(1, "is litl argument\n", 17);
	return (0);
}
