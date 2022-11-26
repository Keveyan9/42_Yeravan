/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:25:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/17 17:23:37 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include "libft.h"
# include"ft_printf.h"
# include "mlx.h"

typedef struct MLX
{
	void *init_id;
	void *window_id;
}	mlx;


char	*window_name_size(int *xy, char *fractal_name);
void	mandelbrot(char *fractal_name, int *);
void	julia(char *fractal_name, int coefficient); 

#endif
