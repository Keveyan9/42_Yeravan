/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:25:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/07 15:04:47 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include "libft.h"
# include"ft_printf.h"
# include "mlx.h"

typedef struct	s_struct_mlx {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	*window_name;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_struct_mlx;

typedef struct s_mandelbrot{

	float	x_center;
	float	y_center;
	float	x;
	float	y;
	int		ciqel;
	float	xmin;
	float	ymin;
	float	zx;
	float	oldx;
	float	zy;
	float	counter;
	float	yzum;
	float	xzum;

}			t_mandelbrot;

void	open_mlx(char *fractal_name, int *xy, t_struct_mlx *win_var);
char	*window_name_size(int *xy, char *fractal_name);
void	mandelbrot(t_struct_mlx *win_var, int *);
void	julia(char *fractal_name, int coefficient); 
void	my_mlx_pixel_put(t_struct_mlx *data, int x, int y, int color);
#endif
