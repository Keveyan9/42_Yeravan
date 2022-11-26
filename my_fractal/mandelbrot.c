/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:23:57 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/25 14:08:11 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

void	mandelbrot(char *fractal_name, int *xy)
{
	mlx var;
	char *window_name;

	window_name = window_name_size(xy,fractal_name);
	var.init_id = mlx_init();
	var.window_id = mlx_new_window(var.init_id, xy[0],xy[1], window_name);
	mlx_loop(var.init_id);
	
}

