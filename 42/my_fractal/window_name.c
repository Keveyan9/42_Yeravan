/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:51:32 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/08 20:36:08 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

char	*window_name_size(t_struct_mlx_mandelbrot *win_var, char *fractal_name)
{
	char	*window_name_size;
	char	*x;
	char	*y;
	char	*name_prabel;
	char	*xy_sinvel;

	x = ft_itoa(win_var->xsize);
	y = ft_itoa(win_var->ysize);
	name_prabel = ft_strjoin(fractal_name, " __ ");
	window_name_size = ft_strjoin(x, " * ");
	xy_sinvel = ft_strjoin(window_name_size, y);
	free(window_name_size);
	window_name_size = ft_strjoin(name_prabel, xy_sinvel);
	free(x);
	free(y);
	free(name_prabel);
	free(xy_sinvel);
	return (window_name_size);
}
