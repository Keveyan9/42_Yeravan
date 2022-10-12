/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:05:34 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/12 21:16:51 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv )
{
	t_main	var;
	t_list *ferst_stec;
	t_list *head;

	if (argc > 3)
	{
		var.input_ful = ful_join(argv);
		var.input_cuts = ft_split(var.input_ful, ' ');
		var.wstrlen = ft_2strlen(var.input_cuts);
		var.input_s = (long int *) malloc(var.wstrlen * sizeof(long int));
		parsing(var.input_s, var.wstrlen, var.input_cuts);
		error_max_min_dupliqet(var.input_s, var.wstrlen);
		pour(var.input_s, var.wstrlen,&ferst_stec);
		free(var.input_s);
		head = ferst_stec;

		int n = 0;
		while (n < var.wstrlen-1)
		{
			printf("%d\n",ferst_stec->content);
			ferst_stec = ferst_stec->next;
			n++;
		}
	}
	else 
		write(1, "is litl argument\n", 17);
//	while(1);
	return (0);
}
