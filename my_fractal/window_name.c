/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:51:32 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/25 14:06:34 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

char	*window_name_size(int *xy, char *fractal_name)
{
	char	*window_name_size;
	char	*x;
	char	*y;
	char	*name_prabel;
	char	*xy_sinvel;

	x = ft_itoa(xy[0]);
	y = ft_itoa(xy[1]);
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
