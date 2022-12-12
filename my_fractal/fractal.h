/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:25:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/10 00:51:26 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include "libft.h"
# include"ft_printf.h"
# include "mlx.h"

typedef struct s_struct_mlx_mandelbrot{
	unsigned int	gama;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	char			*window_name;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				xsize;
	int				ysize;
	float			x_center;
	float			y_center;
	float			x;
	float			y;
	int				ciqel;
	float			xmin;
	float			ymin;
	float			zx;
	float			oldx;
	float			zy;
	float			ymove;
	float			xmove;
	float			zoom;
	int				flag;
	float			jul_x;
	float			jul_y;
	float			ol;	

}			t_struct_mlx_mandelbrot;

void	open_mlx(char *fractal_name, t_struct_mlx_mandelbrot *win_var);
char	*window_name_size( t_struct_mlx_mandelbrot *win_var, \
		char *fractal_name);
void	mandelbrot(t_struct_mlx_mandelbrot *win_var);
void	julia(t_struct_mlx_mandelbrot *win_var);
void	my_mlx_pixel_put(t_struct_mlx_mandelbrot *data, int x, \
		int y, int color);
int		key_hook_man(int code, t_struct_mlx_mandelbrot *mand_var);
int		key_maus_man(int code, int x, int y, t_struct_mlx_mandelbrot *mand_var);
int		clos(t_struct_mlx_mandelbrot *mand_var);
#endif
