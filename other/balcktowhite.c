#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct	s_data {
	void	*mlx;
	void 	*mlxwp;
}				t_data;
typedef struct m_data {
	void *img;
	char *relative_path;
	int img_width;
	int img_height;
}	pikcha;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int color(t_data *a)
{
	static unsigned char t = 0, r = 0, g = 0, b = 0, k = 0;
	//printf("%d %d %d\n", r, g ,b );
	int x = 0, y = 0;
	while (x < 320)
	{
		while(y < 240)
		{
			mlx_pixel_put(a->mlx,a->mlxwp, x, y, create_trgb(t, r, g, b));
			y++;
		}
		x++;
		y = 0;	
	}
	if (r == 200)
		k = -1;
	if (r == 0 )
		k = 0;
	if (k == 0)
	{
		r++;
		g++;
		b++;
	}
	else
	{
		r--;
		g--;
		b--;
	}
	return 1;
}
int hello(t_data *a)
{
	printf("hi\n");
	return 0;
}
int main()
{
	//int trgb;
	t_data img;
	pikcha pika;
	pika.relative_path = "./pikasmall.xpm";
	img.mlx = mlx_init();
	img.mlxwp = mlx_new_window(img.mlx, 320, 240, "Approach");
	mlx_loop_hook(img.mlx, &color, &img);
	//mlx_hook(img.mlxwp, 4, 0, &changecolor, &img);
	//mlx_key_hook(img.mlxwp, &changecolor, &img);
	// mlx_mouse_hook(img.mlxwp, &changecolor, &img);
	//mlx_loop_hook(mlx, render_next_frame, struct);

	pika.img = mlx_xpm_file_to_image(img.mlx, pika.relative_path, &pika.img_height, &pika.img_width);
	mlx_put_image_to_window(img.mlx, img.mlxwp, pika.img, -50, -50);
	mlx_loop(img.mlx);
}