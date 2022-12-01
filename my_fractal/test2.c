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

float	map_to_img(float x, int height, int mapx, int mapy)
{
	return ((x * (mapy - mapx) / height) + mapx);
}

float	map_to_real(float x, int width, int mapx, int mapy)
{
	return ((x * (mapy - mapx) / width) + mapx);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1001, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1001);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	float  x_zum = 500;
	float  y_zum = 500;
	float x = 0;
	float x1 = 0;
	float y = 0;
	float y1 = 0;
	float count_x = 0;
	float count_y = 0;
	float caficent = 4;
	int ciqel = 50;
	int ciqel_count = 0;
	float old_x = 0;

	while (x1 < 1000)
	{	
		x = map_to_real(x1, 1000, -2, 2);
		y1 = 0;
		while(y1 < 1000)
		{
			y = map_to_real(y1, 1000, -2, 2);
			count_y = x;
			count_x = y;
			ciqel_count = 0;
			while ((count_x * count_x) + (count_y* count_y) < caficent && ciqel_count < ciqel)
			{
				old_x = count_x;
				ciqel_count++;
				count_x = ((count_x*count_x) - (count_y*count_y)) + x;
				count_y = (2 * old_x * count_y) + y;
			}
			if(ciqel_count <= ciqel)
			{
				my_mlx_pixel_put(&img, x, y, 0x0FF0000);
			}
//			else
//				my_mlx_pixel_put(&img, x + x_zum, y_zum - y, 0xFF0000 * ciqel_count);
			y1++;
		}
		x1++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
