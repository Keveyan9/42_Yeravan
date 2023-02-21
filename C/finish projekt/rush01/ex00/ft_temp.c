void	ft_temp(int colup[4], int coldown[4], int rowleft[4], int rowright[4]);
void	ft_print(colup[t], coldown[t], rowleft[t], rowright[t]);
void	ft_write(char sh);

void	ft_temp(int colup[4], int coldown[4], int rowleft[4], int rowright[4])
{	
	int	t;
	int	c;

	t = 0;
	c = 0;
	while (t < 4, t++, c++)
	{
		if (((colup[c] + coldown[c]) < 6) && ((colup[c] + coldown[c]) > 2))
			write (1, "%d\n", colup[c], 1);
		else
		{
			ft_write(" 1 -plise Enter corect number 1-4 in colup and coldown 8 pice ");
			return ;
		}
		if ((rowleft[c] + rowright[c]) < 6 && (rowleft[c] + rowright[c] > 3))
		{
		}
		else
		{
			ft_write("2 -plise Enter corect number 1-4in rowright  and rowleft pice ");
			return ;
		}
		ft_print (colup[t], coldown[t], rowleft[t], rowright[t]);
	}
}

void	ft_print(colup[t], coldown[t], rowleft[t], rowright[t])
{
	printf("%d\n", colup[t]);
	printf("%d\n", coldown[t]);
	printf("%d\n", rowleft[t]);
	printf("%d\n", rowright[t]);
}

void	ft_write(char sh)
{
	write (1, &sh, 80);
}
