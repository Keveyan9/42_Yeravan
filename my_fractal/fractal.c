/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:11:07 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/10 01:10:12 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fractal.h"

static void	config(t_struct_mlx_mandelbrot *mand_var)
{
	mand_var->xsize = 500;
	mand_var->ysize = 500;
	mand_var->xmove = 0;
	mand_var->ymove = 0;
	mand_var->ciqel = 10;
	mand_var->gama = 1000;
	mand_var->zoom = 4;
	mand_var->flag = 0;
	mand_var->jul_y = 0.835;
	mand_var->jul_x = +0.2321;
	mand_var->ol = 2;
}

static void	coll_hook(t_struct_mlx_mandelbrot *mand_var)
{
	mlx_mouse_hook(mand_var->mlx_win, key_maus_man, mand_var);
	mlx_key_hook(mand_var->mlx_win, key_hook_man, mand_var);
	mlx_hook(mand_var->mlx_win, 17, 0, clos, mand_var);
	mlx_loop(mand_var->mlx);
}

static int	coll_julia(t_struct_mlx_mandelbrot *mand_var, char **argv)
{
	open_mlx(argv[1], mand_var);
	if (argv[2] && argv[3])
	{
		mand_var->jul_x = ft_atoi(argv[2]) / 1000.0;
		mand_var->jul_y = ft_atoi(argv[3]) / 1000.0;
		julia(mand_var);
	}	
	else if (argv[1] && !argv[2] && argv[3])
		julia(mand_var);
	else
	{
		ft_printf("is not corect julia coefficent");
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct_mlx_mandelbrot	mand_var;

	config(&mand_var);
	if (argc > 1)
	{
		if (!ft_strncmp("Mandelbrot", argv[1], 11) && !argv[2])
		{
			open_mlx(argv[1], &mand_var);
			mandelbrot(&mand_var);
			mand_var.flag = 1;
			coll_hook(&mand_var);
		}
		else if (!ft_strncmp("Julia", argv[1], 5))
		{
			coll_julia(&mand_var, argv);
			coll_hook(&mand_var);
		}
		else
			ft_printf("is not corect input you can input Mandelbrot or Julia\n");
	}
	else
		ft_printf("is not input you can input Mandelbrot or Julia\n");
	return (0);
}
