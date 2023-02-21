/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:26:41 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/14 16:13:08 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	init(char number[])
{
	write(1, &number[0], 1);
	write(1, &number[1], 1);
	write(1, &number[2], 1);
	if (number[0] != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	number[3];

	number[0] = '0';
	number[1] = '1';
	number[2] = '2';
	while (number[0] < '8')
	{
		while (number[1] < '9')
		{	
			while (number[2] < ':')
			{
				init(number);
				number[2]++;
			}
			number[2] = number[1] + 2;
			number[1]++;
		}
		number[1] = number[0] + 1;
		number[0]++;
	}
}
