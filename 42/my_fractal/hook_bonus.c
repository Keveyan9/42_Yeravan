/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:37:42 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/10 00:56:21 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

static void	key_hook_half(int code, t_struct_mlx_mandelbrot *mand_var)
{
	if (code == 69)
		mand_var->zoom = mand_var->zoom - 0.1;
	else if (code == 78)
		mand_var->zoom = mand_var->zoom + 0.1;
	else if (code == 13)
		mand_var->jul_x = mand_var->jul_x - 0.01;
	else if (code == 0)
		mand_var->jul_x = mand_var->jul_x + 0.01;
	else if (code == 1)
		mand_var->jul_y = mand_var->jul_y - 0.01;
	else if (code == 2)
		mand_var->jul_y = mand_var->jul_y + 0.01;
	else if (code == 69)
		mand_var->zoom = mand_var->zoom - 0.1;
	else if (code == 78)
		mand_var->zoom = mand_var->zoom + 0.1;
	else if (code == 3)
		mand_var->ol = mand_var->ol + 0.1;
	else if (code == 5)
		mand_var->ol = mand_var->ol - 0.1;
}

int	key_hook_man(int code, t_struct_mlx_mandelbrot *mand_var)
{
	if (code == 53)
		exit(0);
	else if (code == 126)
		mand_var->ymove = mand_var->ymove - 10;
	else if (code == 125)
		mand_var->ymove = mand_var->ymove + 10;
	else if (code == 124)
		mand_var->xmove = mand_var->xmove - 10;
	else if (code == 123)
		mand_var->xmove = mand_var->xmove + 10;
	else if (code == 257)
		mand_var->ciqel = mand_var->ciqel - 1;
	else if (code == 49)
		mand_var->ciqel = mand_var->ciqel + 1;
	else if (code == 83)
		mand_var->gama = mand_var->gama + 5;
	else if (code == 82)
		mand_var->gama = mand_var->gama - 5;
	key_hook_half(code, mand_var);
	if (mand_var->flag == 1)
		mandelbrot(mand_var);
	else
		julia(mand_var);
	return (0);
}

int	key_maus_man(int code, int x, int y, t_struct_mlx_mandelbrot *mand_var)
{
	mand_var->xmove = mand_var->xsize / 2 * -1 + x;
	mand_var->ymove = mand_var->ysize / 2 * -1 + y;
	if (code == 4)
		mand_var->zoom = mand_var->zoom - 0.1;
	else if (code == 5)
		mand_var->zoom = mand_var->zoom + 0.1;
	if (mand_var->flag == 1)
		mandelbrot(mand_var);
	else
		julia(mand_var);
	return (0);
}

int	clos(t_struct_mlx_mandelbrot *mand_var)
{
	(void)mand_var;
	exit(0);
}
