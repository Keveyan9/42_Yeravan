/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:05:34 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/20 00:51:41 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv )

{
	t_main	var;
	t_list	*stec_a;
	t_list	*stec_b;
	
	stec_a = NULL;
	stec_b = NULL;
	if (argc > 2)
	{
		var.input_ful = ful_join(argv);
		var.input_cuts = ft_split(var.input_ful, ' ');
		var.wstrlen = ft_2strlen(var.input_cuts);
		var.input_s = (long int *) malloc(var.wstrlen * sizeof(long int));
		parsing(var.input_s, var.wstrlen, var.input_cuts);
		error_max_min_dupliqet(var.input_s, var.wstrlen);
		pour(var.input_s, var.wstrlen, &stec_a);
		free(var.input_s);
		algoritm(var.wstrlen, &stec_a, &stec_b);
	}
	else if (argc == 2)
		return (0);
	else
		write(1, "is litl argument\n", 17);
	return (0);
}
