/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:17:28 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/09 15:35:54 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

void	open_mlx(char *fractal_name, t_struct_mlx_mandelbrot *win_var)
{
	win_var->window_name = window_name_size(win_var, fractal_name);
	win_var->mlx = mlx_init();
	win_var->mlx_win = mlx_new_window(win_var->mlx, win_var->xsize, \
			win_var->ysize, win_var->window_name);
	win_var->img = mlx_new_image(win_var->mlx, win_var->xsize, win_var->ysize);
	win_var->addr = mlx_get_data_addr(win_var->img, &win_var->bits_per_pixel, \
			&win_var->line_length, &win_var->endian);
}
