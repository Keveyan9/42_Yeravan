#include <mlx.h>
#include<stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	float  x = 1;
	float  y = 500;
	float d;
	float r;
	d = 0.4;
	r = 0.1;

	int c = 1;
	while (x < 1000 && y > 0 )
	{	
		my_mlx_pixel_put(&img, x, y , 0x00FF0000);
	
		d = d*r*(1-d);
		y = 500 - (d*100);
		x ++ ;
		r = r + 0.1;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}