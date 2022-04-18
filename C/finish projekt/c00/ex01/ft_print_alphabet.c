/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:22:34 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/08 22:43:05 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	sinvel ;

	sinvel = 'a';
	while (sinvel <= 'z')
	{
		write(1, &sinvel, 1);
		sinvel++;
	}
}
