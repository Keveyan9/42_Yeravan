/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:17:28 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/06 20:51:44 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
void	open_mlx(char *fractal_name, int *xy, t_struct_mlx *win_var)
{

	win_var->window_name = window_name_size(xy,fractal_name);
	
	win_var->mlx = mlx_init();
	win_var->mlx_win = mlx_new_window(win_var->mlx, xy[0], xy[1], win_var->window_name);

	win_var->img = mlx_new_image(win_var->mlx, xy[0], xy[1]);
	win_var->addr = mlx_get_data_addr(win_var->img, &win_var->bits_per_pixel, &win_var->line_length,
								&win_var->endian);
}
