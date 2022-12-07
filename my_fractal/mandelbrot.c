/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:23:57 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/07 16:08:56 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

void	mandelbrot(t_struct_mlx *win_var, int *xy)
{
	t_mandelbrot	m_var;

	m_var.x_center = xy[0]/2;
	m_var.y_center = xy[1]/2;
	m_var.x = xy[0]/2 * -1;
	m_var.y = xy[1]/2 * -1;
	m_var.counter = 4;
	m_var.xzum = 0;
	m_var.yzum = 0;

	while( m_var.x < (xy[0]/2))
	{	
		m_var.xmin = ( m_var.x + m_var.xzum) / (xy[0] / m_var.counter);
		while(m_var.y < xy[1]/2 - 2)
		{
			m_var.ymin = (m_var.y + m_var.yzum) / (xy[0]/m_var.counter);
			m_var.zx = 0;
			m_var.zy = 0;
			m_var.ciqel = 500;

			while( m_var.zx * m_var.zx + m_var.zy * m_var.zy < 4 &&  m_var.ciqel)
			{

				m_var.oldx = m_var.zx;
				m_var.zx = m_var.zx * m_var.zx - m_var.zy * m_var.zy + m_var.xmin;
				m_var.zy = 2 * m_var.oldx *m_var.zy + m_var.ymin;
				m_var.ciqel--;
			}
			if(m_var.zx * m_var.zx + m_var.zy * m_var.zy > 4) 
				my_mlx_pixel_put(win_var, m_var.x + m_var.x_center, m_var.y_center - m_var.y, m_var.ciqel * 1000 *  0x0000FF);
				m_var.y++;
		}
		m_var.y = (xy[1]/2 * -1) + 2; 
		m_var.x++;
	}
		mlx_put_image_to_window(win_var->mlx, win_var->mlx_win, win_var->img, 0 ,0);
}	
