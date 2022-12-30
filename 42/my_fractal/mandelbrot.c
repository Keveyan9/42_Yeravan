/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:23:57 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/10 01:03:27 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

static void	config(t_struct_mlx_mandelbrot *win_var)
{
	win_var->x_center = win_var->xsize / 2;
	win_var->y_center = win_var->ysize / 2;
	win_var->x = win_var->xsize / 2 * -1;
	win_var->y = win_var->ysize / 2 * -1;
}

static void	mat(t_struct_mlx_mandelbrot *win_var, int *ciqel)
{
	*ciqel = 0;
	win_var->zx = 0;
	win_var->zy = 0;
	while (win_var->zx * win_var->zx + win_var->zy * win_var->zy < 4 && \
		*ciqel < win_var->ciqel)
	{
		win_var->oldx = win_var->zx;
		win_var->zx = win_var->zx * \
		win_var->zx - win_var->zy * win_var->zy + win_var->xmin;
		win_var->zy = win_var->ol * win_var->oldx * win_var->zy + win_var->ymin;
		(*ciqel)++;
	}
}

void	mandelbrot(t_struct_mlx_mandelbrot *win_var)
{
	int	ciqel;

	config(win_var);
	while (win_var->x < (win_var->xsize / 2))
	{	
		win_var->xmin = (win_var->x + win_var->xmove) / \
		(win_var->xsize / win_var->zoom);
		while (win_var->y < (win_var->ysize / 2) - 2)
		{
			win_var->ymin = (win_var->y + win_var->ymove) / \
			(win_var->xsize / win_var->zoom);
			mat(win_var, &ciqel);
			if (win_var->zx * win_var->zx + win_var->zy * win_var->zy > 4)
				my_mlx_pixel_put(win_var, win_var->x + win_var->x_center, \
			win_var->y_center - win_var->y, ciqel * win_var->gama + 1000);
			else
				my_mlx_pixel_put(win_var, win_var->x + win_var->x_center, \
					win_var->y_center - win_var->y, 0x000000);
		win_var->y++;
		}
		win_var->y = (win_var->ysize / 2 * -1) + 2;
		win_var->x++;
		mlx_put_image_to_window(win_var->mlx, \
		win_var->mlx_win, win_var->img, 0, 0);
	}
}	
