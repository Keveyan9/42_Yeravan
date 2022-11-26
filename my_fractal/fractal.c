/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:11:07 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/25 14:01:24 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fractal.h"

int	main(int argc, char **argv)
{
	int xy[2];

	xy[0] = 1000;
	xy[1] =1000;
	if (argc > 1)
	{
		if (!ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) && !argv[2])
			mandelbrot(argv[1], xy);
		else if (!ft_strncmp("Julia", argv[1], ft_strlen(argv[1])))
		{
			if (argv[2] && !argv[3])
				julia(argv[1], ft_atoi(argv[2]));
			else if (!argv[2])
				julia(argv[1], 10);
			else
				ft_printf("is not corect julia coefficent");
		}
		else
			ft_printf("is not corect input you can input Mandelbrot or Julia\n");
	}
	return (0);
}
