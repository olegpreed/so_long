#include <mlx.h>
#include <stdio.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int main()
{
	int trgb;
	t_data img;
	int t = 0, r = 0, g = 155, b = 155;
	int x = 0, y = 0;
	void *mlx = mlx_init();
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	void *mlxwp = mlx_new_window(mlx, 320, 240, "Approach");
	while (x < 100)
	{
		while(y < 100)
		{
			my_mlx_pixel_put(&img, x, y, create_trgb(t, r, g, b));
			y++;
			r++;
		}
		x++;
		x++;
		y = 0;	
	}
	t = 0, r = 67, g = 100, b = 230;
	y = 0; 
	x = 0;
	
	while (x < 320)
	{
		while(y < 240)
		{
			mlx_pixel_put(mlx, mlxwp, x, y, create_trgb(t, r, g, b));
			y++;
		}
		x++;
		y = 0;	
	}
	mlx_put_image_to_window(mlx, mlxwp, img.img, 110, 70 );
	//mlx_loop_hook(mlx, render_next_frame, struct);
	mlx_loop(mlx);
}