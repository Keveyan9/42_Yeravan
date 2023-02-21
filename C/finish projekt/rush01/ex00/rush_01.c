/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:52:05 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/12 15:52:30 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	b;
	int	u;
	int	d;
	int	l;
	int	r;
	int	v;
	int	colup[4];
	int	coldown[4];
	int	rowleft[4];
	int	rowright[4];

	if (argc > 1)
	{
		b = 0;
		i = 0;
		u = 0;
		d = 0;
		l = 0;
		r = 0;
		v = 0;
		while (argv[1][i] != '\0')
		{
			if ('0' < argv[1][i] && argv[1][i] < '5')
			{
				if (b < 4 && u < 4)
				{
					colup[u] = argv[1][i] - 48;
					u++;
				}
				else if ((b > 3 && b < 8) && d < 4)
				{
					coldown[d] = argv[1][i] - 48;
					d++;
				}
				else if ((b > 7 && b < 12) && l < 4)
				{
					rowleft[l] = argv[1][i] - 48;
					l++;
				}
				else if ((b > 11 && b < 16) && r < 4)
				{
					rowright[r] = argv[1][i] - 48;
					r++;
				}
				else
				{
				}	
				b++;
			}
			else if (argv[1][i] != ' ' || argv[1][i] != ',')
			{
				write (1, " 1 you Enter ancorect number", 30);
				return (0);
			}
			i++;
		}
	}
	else
		write (1, "plise Enter corect number 1-4 and 16 pice \n", 40);
	while (v < 4)
	{
		ft_temp(colup[4], coldown[4], rowleft[4], rowright[4]);
	}
	return (0);
}
