/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:05:34 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/05 18:29:22 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	valid_start(long int *c, int count)
{
	int	t;

	t = 0;
	while (t < count - 1)
	{
		if (&(c[t + 1]) && c[t] > c[t + 1])
		{
			return (1);
		}
		t++;
	}
	exit(0);
}

int	main(int argc, char **argv )
{
	t_main	var;
	t_list	*stec_a;
	t_list	*stec_b;

	stec_a = NULL;
	stec_b = NULL;
	if (argc > 1)
	{
		var.input_ful = ful_join(argv);
		var.input_cuts = ft_split(var.input_ful, ' ');
		var.wstrlen = ft_2strlen(var.input_cuts);
		var.input_s = (long int *) malloc(var.wstrlen * sizeof(long int));
		parsing(var.input_s, var.wstrlen, var.input_cuts);
		error_max_min_dupliqet(var.input_s, var.wstrlen);
		pour(var.input_s, var.wstrlen, &stec_a);
		if (valid_start(var.input_s, var.wstrlen))
		{
			free(var.input_s);
			if (var.wstrlen > 5)
				algoritm(var.wstrlen, &stec_a, &stec_b);
			else
				do_5(var.wstrlen, &stec_a, &stec_b);
		}
	}
	return (0);
}
