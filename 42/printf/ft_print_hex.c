/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:41:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/07/25 19:41:44 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_hex_lowercase(int *len, unsigned int hexcalcul)
{
	char	*hexform_lowercase ;

	hexform_lowercase = "0123456789abcdef";
	if (hexcalcul >= 16)
		ft_print_hex_lowercase(len, hexcalcul / 16);
	write(1, &hexform_lowercase[hexcalcul % 16], 1);
	(*len)++;
}

void	ft_print_hex_uppercase(int *len, unsigned int hexcalcul)
{
	char	*hexform_uppercase;

	hexform_uppercase = "0123456789ABCDEF";
	if (hexcalcul >= 16)
		ft_print_hex_uppercase(len, hexcalcul / 16);
	write(1, &hexform_uppercase[hexcalcul % 16], 1);
	(*len)++;
}
