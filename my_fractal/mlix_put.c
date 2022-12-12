/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlix_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:55:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/09 15:36:30 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

void	my_mlx_pixel_put(t_struct_mlx_mandelbrot *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
