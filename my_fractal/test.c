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
	mlx_win = mlx_new_window(mlx, 1000, 1001, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1001);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	float  x_zum = 700;
	float  y_zum = 500;
	float x = -500;
	float y = -500;
	float count_x = 0;
	float count_y = 0;
	float caficent = 4;
	int ciqel = 250;
	int ciqel_count = 0;
	float old_x = 0;

	int c = 1;
	while (x < 500)
	{	
		y = -500;
		while( y < 500)
		{
			count_y = 0;
			count_x = 0;
			ciqel_count = 0;
			while((count_x*count_x) + ( count_y*count_y) < caficent && ciqel_count < ciqel)
			{
				old_x = count_x;
				ciqel_count++;
				count_x = ((count_x*count_x) - (count_y*count_y)) + x/500;
				count_y = (2*old_x*count_y) + y/500;
				
			}		
			//	printf("count_x == %f", x);
			//	printf(" count_y == %f", y);
			//	printf(" set %f ",count_x*count_x + count_y*count_y);
			//	printf(" ciqel __%d\n",ciqel_counto);g

			if(count_x*count_x+count_y*count_y > caficent)
			{
				my_mlx_pixel_put(&img, x + x_zum,  y_zum - y , 0x00FF00 *ciqel_count);
			}
	//		else
	//			my_mlx_pixel_put(&img, x + x_zum, y + y_zum, 0xFF0000 * ciqel_count);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	}
